#include <stdlib.h>

double *multiples(int m, double n) {
    double* result = (double*) malloc(sizeof(double) * m);
    result[0] = n;
    for (size_t i = 1; i < m; ++i) 
        result[i] = result[i-1] + n;
    return result;
}
