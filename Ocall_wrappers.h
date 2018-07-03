#ifndef _OCALL_WRAPPERS_H_
#define _OCALL_WRAPPERS_H_

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include <string.h>

#if defined(__cplusplus)
extern "C" {
#endif

int sgx_sscanf(const char *str, const char *format, ...);

#define sscanf sgx_sscanf
#define strcpy(dst, src) strncpy(dst, src, strlen(src))
#define strcat(dst, src) strncat(dst, src, strlen(src))

#define strdup sgx_strdup

#if defined(__cplusplus)
}
#endif

#endif /* !_OCALL_WRAPPERS_H_ */