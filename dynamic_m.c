#include "dynamic_m.h"
#include <stdlib.h>

void Vvod2(FILE *in, int **x, int n) {
    *x = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        fscanf(in, "%i", &(*x)[i]);
    }
    return;
}

void Vivod2(FILE *out, int **x, int n) {
    for (int i = 0; i < n; i++) {
        fprintf(out, "%3i ", (*x)[i]);
    }
    fprintf(out, "\n");
    return;
}

void FR2(int *x) {
    free(x);
    return;
}

int SOK(int **x, int n, int z) {
    int sm = 0;
    for (int i = 0; i < n; i++) {
        if ((*x)[i] % z == 0) {
            sm += (*x)[i];
        }
    }
    return sm;
}

/*void NS(FILE *out, int **x1, int n1, int **x2, int n2, int **x3, int n3, int z) {
    int sm1 = SOK(x1, n1, z);
    int sm2 = SOK(x2, n2, z);
    int sm3 = SOK(x3, n3, z);

    int mx = sm1;
    if (sm2 > mx){
        mx = sm2;
    }
    if (sm3 > mx){
        mx = sm3;
    }

    if (sm1 == mx){
        Vivod2(out, x1, n1);
    }
    if (sm2 == mx) Vivod2(out, x2, n2);
    if (sm3 == mx) Vivod2(out, x3, n3);
}*/
