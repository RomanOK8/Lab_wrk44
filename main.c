#include <stdio.h>
#include <stdlib.h>
#include "dynamic_m.h"

int main() {
    FILE *in1 = fopen("VVOD1.txt", "r");
    FILE *in2 = fopen("VVOD2.txt", "r");
    FILE *in3 = fopen("VVOD3.txt", "r");
    FILE *out = fopen("VIVOD.txt", "w");

    int n1;
    do { printf("Input n1:"); scanf("%i", &n1); } while (n1 < 0 || n1 > 20);
    int n2;
    do { printf("Input n2:"); scanf("%i", &n2); } while (n2 < 0 || n2 > 20);
    int n3;
    do { printf("Input n3:"); scanf("%i", &n3); } while (n3 < 0 || n3 > 20);
    int z;
    do { printf("Input z:"); scanf("%i", &z); } while (z <= 0);

    int *A;
    int *B;
    int *C;

    Vvod2(in1, &A, n1);
    Vvod2(in2, &B, n2);
    Vvod2(in3, &C, n3);
    int sm1 = SOK(&A, n1, z);
    int sm2 = SOK(&B, n2, z);
    int sm3 = SOK(&C, n3, z);
if (sm1 > sm2 && sm1 > sm3) {
    fprintf(out, "A max\n");
    Vivod2(out, &A, n1);
} else if (sm2 > sm3 && sm2 > sm1) {
    fprintf(out, "B max\n");
    Vivod2(out, &B, n2);
} else if (sm3 > sm1 && sm3 > sm2) {
    fprintf(out, "C max\n");
    Vivod2(out, &C, n3);
} else if (sm1 == sm2 && sm1 > sm3) {
    fprintf(out, "V A max i v B max\n");
    Vivod2(out, &A, n1);
    Vivod2(out, &B, n2);
} else if (sm1 == sm3 && sm1 > sm2) {
    fprintf(out, "V A max i v C max\n");
    Vivod2(out, &A, n1);
    Vivod2(out, &C, n3);
} else if (sm3 == sm2 && sm2 > sm1) {
    fprintf(out, "V B max i v C max\n");
    Vivod2(out, &B, n2);
    Vivod2(out, &C, n3);
} else if (sm1 == 0 && sm2 == 0 && sm3 == 0) {
    fprintf(out, "vo vseh net\n");
} else {
    fprintf(out, "Vo vseh odinakovo\n");
    Vivod2(out, &A, n1);
    Vivod2(out, &B, n2);
    Vivod2(out, &C, n3);
}
//защита потом

    FR2(A);
    FR2(B);
    FR2(C);

    fclose(in1);
    fclose(in2);
    fclose(in3);
    fclose(out);

    printf("Proverka zapici");
    return 0;
}
