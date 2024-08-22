#ifndef MATRIX_H
#define MATRIX_H

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE_MISMATCH -1
#define SHAPE_MISMATCH -2

typedef struct matrix{

    /*
        m righe x n colonne
    */

    uint64_t row_n;
    uint64_t col_n;
    double ** elements;
}Matrix;

typedef union {
    Matrix * m;
    double lambda;
}LinalgRes;

Matrix * init(uint64_t row_n, uint64_t col_n){
    Matrix * result = (Matrix *)malloc(sizeof(Matrix));

    result->row_n = row_n;
    result->col_n = col_n;

    result->elements = (double **)malloc(row_n * sizeof(double*));
    for (int i = 0; i < row_n; i++){
        result->elements[i] = (double*)calloc(col_n, sizeof(double));
    }

    return result;
}

void show(Matrix * m){

    if(m == NULL){
        printf("NULL matrix\n");
        return;
    }

    printf("Matrix %d rows x %d columns\n", (int)m->row_n, (int)m->col_n);
    for (int i = 0; i < m->row_n; i++){
        for (int j = 0; j < m->col_n; j++){
            printf("%f\t", m->elements[i][j]);
        }
        printf("\n");
    }
}

double trace(Matrix * m){
    double sum;
    if (m->col_n == m->row_n){
        for (int i = 0; i < m->row_n; i++){
            sum += m->elements[i][i];
        }
        return sum;
    }

    return 0;
}

 LinalgRes transpose(Matrix * m){

     LinalgRes result;

    if (m->row_n == 1 && m->col_n == 1){
        result.lambda = m->elements[0][0];
        return result;
    }

    result.m = init(m->col_n, m->row_n);

    for (int i = 0; i < result.m->row_n; i++){
        for (int j = 0; j < result.m->col_n; j++){
             result.m->elements[i][j] = m->elements[j][i];
        }
    }

    return result;
}

Matrix * MADD(Matrix * A, Matrix * B){
    /*Somma due matrici le cui dimensioni sono uguali */

    Matrix * result = NULL;
    if(A->row_n != B->row_n || A->col_n != B->col_n){
        return result;
    }

    result = init(A->row_n, A->col_n);
    for (int i = 0; i < result->row_n; i++){
        for (int j = 0; j < result->col_n; j++){
            result->elements[i][j] =  A->elements[i][j] + B->elements[i][j];
        }
    }

    return result;
}
Matrix * MSUB(Matrix * A, Matrix * B){
     /*Sottrae due matrici le cui dimensioni sono uguali */
    Matrix * result = NULL;
    if(A->row_n != B->row_n || A->col_n != B->col_n){
        return result;
    }

    result = init(A->row_n, A->col_n);
    for (int i = 0; i < result->row_n; i++){
        for (int j = 0; j < result->col_n; j++){
            result->elements[i][j] =  A->elements[i][j] - B->elements[i][j];
        }
    }

    return result;
}

Matrix * MMUL(Matrix * A, Matrix * B){

    /*Moltiplica due matrici */

    if (A ->col_n != B->row_n){
        return NULL;
    }

    Matrix * result = init(A->row_n, B->col_n);

    for (int i = 0; i < result->row_n; i++){
        for (int j = 0; j < result->col_n; j++){
            for (int k = 0; k < A->col_n; k++){
                result->elements[i][j] += A->elements[i][k] * B->elements[k][j];
            }
        }
    }

    return result;
}

Matrix * SMMUL(Matrix * m, double scalar){
    /*Moltiplica una matrice per uno scalare */
    Matrix * result = init(m ->row_n, m->col_n);

    for (int i = 0; i < m->row_n; i++){
        for (int j = 0; j < m->col_n; j++){
            result->elements[i][j] = m->elements[i][j] * scalar;
        }
    }
    return result;
}

#endif
