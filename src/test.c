#include<matrix.h>
#include<stdio.h>

int main(){
	//srand((unsigned)time(NULL));
	struct Matrix *mat;
	struct Matrix *mat2;
	struct Matrix *trans;

	mat = createMat(3,4);
	mat2 = createMat(4,3);

	fillMatrixRandomNumber(mat);
	fillMatrixRandomNumber(mat2);

	printMatrix(mat);
	printf("\n");
	printMatrix(mat2);

	mulMatScalar(mat,-2.0);

	printf("\n");
	printMatrix(mat);

	trans = transpose(mat);

	printf("\n");
	printMatrix(trans);


	freeMatrix(mat);
	freeMatrix(mat2);
	freeMatrix(trans);
	return 0;
}
