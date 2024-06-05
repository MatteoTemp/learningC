#ifndef _LINALGALGORITHM_
#define _LINALGALGORITHM_

#include <math.h>
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

#endif
