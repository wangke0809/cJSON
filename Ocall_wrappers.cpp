#include "Ocall_wrappers.h"

// char* sgx_strcpy(char* des, const char* source)
// {
//  	return strncpy(des, source, strlen(source));
// }

// char* sgx_strcat(char* des, const char* source){
// 	return strncat(des, source, strlen(source));
// }

char *sgx_strdup(char *str)
{
	char*p = (char *)malloc(sizeof(char)*(strlen(str) + 1));
	*(p+strlen(str)) = '\0';
	strcpy(p, str);
	return p;
}

int sgx_sscanf(const char *str, const char *format, ...)
{
	int val_cnt = 0;
	va_list args;
	va_start(args, format);
	for ( ; *format != '\0'; format++) {
		if (*format == '%' && format[1] == 'd') {
			int positive;
			int value;
			int *valp;

			if (*str == '-') {
				positive = 0;
				str++;
			} else
				positive = 1;
			if (!isdigit(*str))
				break;
			value = 0;
			do {
				value = (value * 10) - (*str - '0');
				str++;
			} while (isdigit(*str));
			if (positive)
				value = -value;
			valp = va_arg(args, int *);
			val_cnt++;
			*valp = value;
			format++;
		}
		else if (*format == '%' && format[1] == 'c') {
			char value;
			char *valp;

			if (!isalpha(*str))
				break;
			value = *str;
			str++;
			valp = va_arg(args, char *);
			val_cnt++;
			*valp = value;
			format++;
		}
		else if (*format == *str) {
			str++;
		}
		else {
			break;
		}
	}
	va_end(args);
	return val_cnt;
}
