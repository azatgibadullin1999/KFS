/**
 * @file stdlib.h
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef __KFS_LIBC_STDLIB_H__
# define __KFS_LIBC_STDLIB_H__

# include <stddef.h>

# ifdef __cplusplus
extern "C" {
# endif

typedef struct {
	int quot; /* Quotient */
	int rem;  /* Remainder */
} div_t;

typedef struct {
	long quot; /* Quotient */
	long rem;  /* Remainder */
} ldiv_t;

typedef struct {
	long long quot; /* Quotient */
	long long rem;  /* Remainder */
} lldiv_t;

div_t div(int numerator, int denominator);
ldiv_t ldiv(long numerator, long denominator);
lldiv_t lldiv(long long numerator, long long denominator);

char *itoa(long long value, char *str, int base);
char *uitoa(unsigned long long value, char *str, unsigned int base);
int atoi(const char *str);

void *malloc(size_t);
void free(void *);

void abort();

# ifdef __cplusplus
}
# endif

#endif // __KFS_LIBC_STDLIB_H__