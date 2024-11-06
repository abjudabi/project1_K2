#include <stdio.h>
#include <stdbool.h>

void decoder(bool D0, bool D1, bool *enRA, bool *enRB, bool *enRO) {
    int caseValue = (D0 << 1) | D1;
    switch (caseValue) {
        case 0:
            *enRA = 1; *enRB = 0; *enRO = 0;
            break;
        case 1:
            *enRA = 0; *enRB = 1; *enRO = 0;
            break;
        case 2:
            *enRA = 0; *enRB = 0; *enRO = 1;
            break;
        case 3:
            *enRA = 0; *enRB = 0; *enRO = 0;
            break;
        default:
            break;
    }
}

