
#include "matrix.h"
#include "convolution.h"
#include <math.h>
#include <stdlib.h>



int main(int argc, char ** argv){

    int size = atoi(argv[1]);

    Matrix * m = init(1, size);
    Matrix * n = init(1, size);


    for (int i = 0; i < size; i++){
        m->elements[0][i] = 1.0;
        n->elements[0][i] = 1.0;
    }

    show(m);
    show(n);

    Matrix * result = convolution(m, n);
    show(transpose(result).m);

    return 0;
}
