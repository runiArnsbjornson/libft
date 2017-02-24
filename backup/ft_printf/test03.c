#include <stdio.h>
#include <float.h>
#include <limits.h>

int main() {
	printf("The number of bits in a byte %d\n\n", CHAR_BIT);
	printf("The minimum value of CHAR = %d\n", CHAR_MIN);
	printf("The maximum value of CHAR = %d\n\n", CHAR_MAX);
	printf("The minimum value of SIGNED CHAR = %d\n", SCHAR_MIN);
	printf("The maximum value of SIGNED CHAR = %d\n\n", SCHAR_MAX);
	printf("The maximum value of UNSIGNED CHAR = %d\n\n", UCHAR_MAX);
	printf("The minimum value of SHORT INT = %d\n", SHRT_MIN);
	printf("The maximum value of SHORT INT = %d\n\n", SHRT_MAX);
	printf("The minimum value of INT = %d\n", INT_MIN);
	printf("The maximum value of INT = %d\n\n", INT_MAX);
	printf("The maximum value of UNSIGNED INT = %u\n\n", UINT_MAX);
	printf("The minimum value of LONG = %ld\n", LONG_MIN);
	printf("The maximum value of LONG = %ld\n\n", LONG_MAX);
	printf("The maximum value of UNSIGNED LONG = %lu\n\n", ULONG_MAX);
	printf("The minimum value of LONG LONG = %lld\n", LLONG_MIN);
	printf("The maximum value of LONG LONG = %lld\n\n", LLONG_MAX);
	printf("The maximum value of UNSIGNED LONG LONG = %llu\n\n", ULLONG_MAX);
	printf("The maximum value of SSIZE_T = %ld\n", SSIZE_MAX);
	printf("The maximum value of NL_ARGMAX = %u\n", NL_ARGMAX);
	return(0);
}
