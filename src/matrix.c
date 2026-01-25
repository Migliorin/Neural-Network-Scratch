#include "matrix.h"
#include<time.h>
#include<stdlib.h>
#include<stdio.h>


float randomNumberMinus1to1(){
	static int seeded = 0;

    	if (!seeded) {
    	    srand((unsigned) time(NULL));
    	    seeded = 1;
    	}

	return 2.0 * ((float)rand() / RAND_MAX) - 1.0;
}

void printMatrix(struct Matrix *mat){
    int j = 0;
    int row = *(mat->rows);
    int col = *(mat->cols);

    for (int i = 0; i < row*col; i++)
    {
        printf("%.4f ",mat->mat[i]);

        if(j == col - 1){
           printf("\n");
            j = 0;
        } else {
            j++;
        }
    }


}


void freeMatrix(struct Matrix *mat){
	free(mat->rows);
	free(mat->cols);
	free(mat->mat);

	printf("Matrix Successfully freed.\n");

}

struct Matrix* createMat(int rows, int cols){
	int *row = (int *)malloc(sizeof(int));
	int *col = (int *)malloc(sizeof(int));
	struct Matrix *mat= (struct Matrix *)malloc(sizeof(struct Matrix));
	float *mat_data = (float *)malloc(rows*cols*sizeof(float));

	if(row == NULL || col == NULL || mat == NULL || mat_data == NULL){
		free(mat);
		free(mat_data);
		free(col);
		free(row);
		printf("Erro na cricao da matrix");
		return NULL;
	}

	*row = rows;
	*col = cols;

	for(int i = 0; i < rows*cols; i++){
		mat_data[i] = randomNumberMinus1to1();
	}

	mat->rows = row;
	mat->cols = col;
	mat->mat = mat_data;

	return mat;
}
