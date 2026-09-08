#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <oti/oti.h>

int main(void) {
    oarrm1n3_t x, f;
    double tol = 1e-10;

    x = oarrm1n3_ones(3, 3);
    f = oarrm1n3_createEmpty(3, 3);
    x.p_data[0].e1 = 1.0;

    /* f = sqrt(x) */
    oarrm1n3_sqrt_to(&x, &f);

    /* For x = 1.0 + eps, sqrt(x) = 1.0 + 0.5*eps */
    if (fabs(f.p_data[0].r - 1.0) > tol) {
        fprintf(stderr, "Array test failed on real part: got %g, expected 1.0\n", f.p_data[0].r);
        return 1;
    }
    if (fabs(f.p_data[0].e1 - 0.5) > tol) {
        fprintf(stderr, "Array test failed on 1st derivative: got %g, expected 0.5\n", f.p_data[0].e1);
        return 1;
    }

    printf("C array tests passed successfully.\n");
    return 0;
}
