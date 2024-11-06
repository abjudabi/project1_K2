#include <stdio.h>
#include <stdbool.h>

void ALU(int RA, int RB, bool D0, bool S, bool *carry, int *sum) {
    if (S == 0) {
        if (D0 == 0) {
            RA = RA + RB;
            if (RA > 0b1111) {
                *carry = 1;
                *sum = RA & 0b1111;
            } else {
                *carry = 0;
                *sum = RA & 0b1111;
            }
        } else {
            RB = RA + RB;
            if (RB > 0b1111) {
                *carry = 1;
                *sum = RB & 0b1111;
            } else {
                *carry = 0;
                *sum = RB & 0b1111;
            }
        }
    } else {
        if (D0 == 0) {
            *carry = 0;
            RA = RA - RB;
            *sum = RA & 0b1111;
        } else {
            *carry = 0;
            RB = RA - RB;
            *sum = RB & 0b1111;
        }
    }
}

int main() {
    bool carry;
    int sum;

    ALU(15, 3, 0, 0, &carry, &sum);
    printf("ALU result: carry=%d, sum=%d\n", carry, sum);

    return 0;
}

