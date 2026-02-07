#include<matrix.h>
#include<stdio.h>

int main(){
	//srand((unsigned)time(NULL));
	struct Matrix *mat;
	struct Matrix *mat2;
	struct Matrix *trans;
	struct Matrix *mul;

	mat = createMat(3,4);
	mat2 = createMat(4,3);

	fillMatrixRandomNumber(mat);
	fillMatrixRandomNumber(mat2);

	printf("Matrix 3x4\n");
	printMatrix(mat);
	printf("\n");

	printf("Matrix 4x3\n");
	printMatrix(mat2);
	printf("\n");


	mulMatScalar(mat,-2.0);

	printf("Matrix 3x4 multiplicado por (-2)\n");
	printMatrix(mat);
	printf("\n");

	trans = transpose(mat);

	printf("Matrix 3x4 transposta\n");
	printMatrix(trans);
	printf("\n");

	printf("Multiplicacao matrix 3x4 pela matrix 4x3\n");
	mul = mulMat(mat, mat2);
    	printMatrix(mul);
	printf("\n");


	freeMatrix(mat);
	freeMatrix(mat2);
	freeMatrix(trans);
	freeMatrix(mul);
	return 0;
}
