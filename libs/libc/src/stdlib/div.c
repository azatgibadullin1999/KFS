/**
 * @file div.c
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 14-09-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stdio.h>
#include <stdlib.h>

div_t div(int numerator __attribute__((unused)), int denominator __attribute__((unused))) {
	div_t ret = { 0, 0 };
	printf("ERROR!!! you are not suppposed to use that: %s", __func__);
	return ret;
}

ldiv_t ldiv(long numerator __attribute__((unused)), long denominator __attribute__((unused))) {
	ldiv_t ret = { 0, 0 };
	printf("ERROR!!! you are not suppposed to use that: %s", __func__);
	return ret;
}

lldiv_t lldiv(long long numerator __attribute__((unused)), long long denominator __attribute__((unused))) {
	lldiv_t ret = { 0, 0 };
	printf("ERROR!!! you are not suppposed to use that: %s", __func__);
	return ret;
}
