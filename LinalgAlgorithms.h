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

double determinant(Matrix * m){

    if (m->row_n != m->col_n){
        perror("La matrice non è singolare\n");
        exit(-1);
    }

    return 0;

}

#endif
