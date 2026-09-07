#include <stdio.h>
#include <string.h>
#include <oti/oti.h>

int main(void) {
    int major = -1, minor = -1, patch = -1;
    char expected[64];

    /* The runtime accessor must agree with the compile-time macro. */
    if (strcmp(oti_version(), OTI_VERSION_STRING) != 0) {
        fprintf(stderr, "Version test failed: library reports %s, header declares %s\n",
                oti_version(), OTI_VERSION_STRING);
        return 1;
    }

    /* The numeric components must reconstruct the version string. */
    oti_version_numbers(&major, &minor, &patch);
    snprintf(expected, sizeof(expected), "%d.%d.%d", major, minor, patch);

    if (strcmp(oti_version(), expected) != 0) {
        fprintf(stderr, "Version test failed: components give %s, string is %s\n",
                expected, oti_version());
        return 1;
    }

    /* The packed version must match the encoding of its own components. */
    if (oti_version_number() != OTI_VERSION_ENCODE(major, minor, patch)) {
        fprintf(stderr, "Version test failed: packed version %d does not encode %s\n",
                oti_version_number(), expected);
        return 1;
    }

    /* NULL outputs are documented as accepted. */
    oti_version_numbers(NULL, NULL, NULL);

    printf("C version tests passed successfully (OTIlib %s).\n", oti_version());
    return 0;
}
