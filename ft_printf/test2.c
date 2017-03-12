#include <stdio.h>
#include <math.h>
#include <string.h>
static void decode (char *s, double x) {
    long y;
	memcpy(&y, &x+1, 8);

    printf("%lx ",y);
    if ((y & 0x7ff80000L) == 0x7ff80000L) {
        printf ("NaN  (%s)\n", s);
        return;
    }
    if ((y & 0xfff10000L) == 0x7ff00000L) {
        printf ("+Inf (%s)\n", s);
        return;
    }
    if ((y & 0xfff10000L) == 0xfff00000L) {
        printf ("-Inf (%s)\n", s);
        return;
    }
    printf ("%e (%s)\n", x, s);
}

int main (int argc, char *argv[]) {
    double dvar;

    printf ("sizeof double = %u\n", sizeof(double));
    printf ("sizeof long   = %u\n", sizeof(long));

    dvar = 1.79e308; dvar = dvar * 10000;
    decode ("too big", dvar);

    dvar = -1.79e308; dvar = dvar * 10000;
    decode ("too big and negative", dvar);

    dvar = -1.0; dvar = sqrt(dvar);
    decode ("imaginary", dvar);

    dvar = -1.79e308;
    decode ("normal", dvar);

    return 0;
}
