
#include "matrix.h"
#include "convolution.h"
#include "LinalgAlgorithms.h"
#include <math.h>
#include <stdlib.h>

double f(double x, double * params){
    return x*x*params[0] + params[1];
}

int main(int argc, char ** argv){

    int size = 5;
    double params[] = {1.0, 2.0};

    Matrix * x = linspace(-1.0, 1.0, 10);
    Matrix * y = map(f, x, params);
    show(transpose(x).m);
    show(transpose(y).m);

    return 0;
}
