
#include "LinalgAlgorithms.h"
#include "matrix.h"
#include <math.h>

int main(){

    Matrix * m = init(3, 3);
    m->elements[0][0] = 1.0;
    m->elements[1][0] = 1.0;

    show(m);

    printf("%f\n", determinant(m));
    return 0;
}
