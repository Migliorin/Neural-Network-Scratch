#ifndef MATRIX_H
#define MATRIX_H

struct Matrix {
    float *mat;
    int *rows;
    int *cols;
};

float randomNumberMinus1to1(void);

void printMatrix(struct Matrix *mat);

void freeMatrix(struct Matrix *mat);

struct Matrix* createMat(int rows, int cols);

void mulMatScalar(struct Matrix* mat, float number);

struct Matrix* transpose(struct Matrix* mat);

void fillMatrixRandomNumber(struct Matrix* mat);

#endif

