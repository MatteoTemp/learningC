#ifndef _CONVOLUTION_H_
#define _CONVOLUTION_H_

#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"

Matrix * convolution(Matrix * input, Matrix * kernel){

    if (input->row_n != 1 || kernel -> row_n != 1){
        fprintf(stderr, "Input matrices must be row-vectors");
        exit(SHAPE_MISMATCH);
    }

    int input_size = input->col_n;
    int kernel_size = kernel->col_n;
    int output_size = input_size + kernel_size - 1;

    Matrix * output = init(1, output_size);

    for (int output_index = 0; output_index < output_size; ++output_index){
        for (int input_index = 0; input_index < input_size; ++input_index){
            int kernel_index = output_index - input_index;
            if (kernel_index >= 0 && kernel_index < kernel_size){
                output->elements[0][output_index]
                    += input->elements[0][input_index] * kernel->elements[0][kernel_index];
            }
        }
    }

    return output;
}


#endif
