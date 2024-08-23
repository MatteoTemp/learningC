#ifndef _LINALGALGORITHM_
#define _LINALGALGORITHM_

#include <math.h>
#include <stdio.h>
#include "matrix.h"


double normp(Matrix * m, int p){
    double result = 0;

    for(int i = 0; i < m->row_n; i++){
        for (int j = 0; j < m->col_n; j++){
            result += pow(fabs(m->elements[i][j]), (double)p);
        }
    }
    return pow(result, 1 / (double)p);
}

Matrix * linspace(double lower_bound, double upper_bound, int steps){
    Matrix * output = init(1, steps);
    double delta_x = (upper_bound - lower_bound) / (double)(steps - 1);

    for (int i = 0; i <= steps; i++){
        output->elements[0][i] = lower_bound + (double)i * delta_x;
    }

    return output;
}

Matrix * map(double (*f)(double, double*), Matrix * m, double * parameters){
    Matrix * output = init(m->row_n, m->col_n);

    for(int i = 0; i < m->row_n; i++){
        for (int j = 0; j < m->col_n; j++){
            output->elements[i][j] = f(m->elements[i][j], parameters);
        }
    }

    return output;
}


double determinant(Matrix * m){

    //must be implemented

    if (m->row_n != m->col_n){
        perror("La matrice non è singolare\n");
        exit(-1);
    }

    return 0;
}

#endif
