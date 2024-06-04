#ifndef ROTATION_H
#define ROTATION_H

#include "matrix.h"
#include <math.h>

Matrix * ROTX(double alpha){
    /*Ritorna la matrice quadrata associata alla rotazione attorno all'asse X */
    Matrix * result = init(3, 3);

    double ct = cos(alpha);
    double st = sin(alpha);

    result->elements[0][0] = 1;
    result->elements[1][1] = ct;
    result->elements[1][2] = -st;
    result->elements[2][1] = st;
    result->elements[2][2] = ct;

    return result;
}

Matrix * ROTY(double beta){
    /*Ritorna la matrice quadrata associata alla rotazione attorno all'asse Y */
    Matrix * result = init(3, 3);

    double ct = cos(beta);
    double st = sin(beta);

    result->elements[1][1] = 1;

    result->elements[0][0] = ct;
    result->elements[0][2] = st;
    result->elements[2][0] = -st;
    result->elements[2][2] = ct;

    return result;
}

Matrix * ROTZ(double gamma){
    /*Ritorna la matrice quadrata associata alla rotazione attorno all'asse Z */
    Matrix * result = init(3, 3);

    double ct = cos(gamma);
    double st = sin(gamma);

    result->elements[2][2] = 1;

    result->elements[0][0] = ct;
    result->elements[0][1] = -st;
    result->elements[1][0] = st;
    result->elements[1][1] = ct;

    return result;
}

Matrix * ROT(double alpha, double beta, double gamma){
    return MMUL(ROTX(alpha), MMUL(ROTY(beta), ROTZ(gamma)));
}

#endif
