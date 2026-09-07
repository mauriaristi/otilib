#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <oti/oti.h>

int main(void) {
    onumm1n3_t x, f;
    double tol = 1e-10;

    /* x = 3.5 + eps */
    onumm1n3_set_r(3.5, &x);
    x.e1 = 1.0;

    /* f = sin(x) */
    onumm1n3_sin_to(&x, &f);

    /* Verify derivatives of sin(x) at x = 3.5 */
    /* f(x) = sin(3.5) */
    if (fabs(f.r - sin(3.5)) > tol) {
        fprintf(stderr, "Scalar test failed on real part: got %g, expected %g\n", f.r, sin(3.5));
        return 1;
    }
    /* f'(x) = cos(3.5) */
    double d1 = onumm1n3_get_deriv(0, 1, &f);
    if (fabs(d1 - cos(3.5)) > tol) {
        fprintf(stderr, "Scalar test failed on 1st derivative: got %g, expected %g\n", d1, cos(3.5));
        return 1;
    }
    /* f''(x) = -sin(3.5) */
    double d2 = onumm1n3_get_deriv(0, 2, &f);
    if (fabs(d2 - (-sin(3.5))) > tol) {
        fprintf(stderr, "Scalar test failed on 2nd derivative: got %g, expected %g\n", d2, -sin(3.5));
        return 1;
    }
    /* f'''(x) = -cos(3.5) */
    double d3 = onumm1n3_get_deriv(0, 3, &f);
    if (fabs(d3 - (-cos(3.5))) > tol) {
        fprintf(stderr, "Scalar test failed on 3rd derivative: got %g, expected %g\n", d3, -cos(3.5));
        return 1;
    }

    printf("C scalar tests passed successfully.\n");
    return 0;
}
