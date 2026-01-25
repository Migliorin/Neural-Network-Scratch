#include<matrix.h>
#include<stdio.h>

struct Linear{

};


int main(){
	//srand((unsigned)time(NULL));
	struct Matrix *mat;
	struct Matrix *mat2;


	mat = createMat(3,2);
	mat2 = createMat(2,2);

	printMatrix(mat);
	printf("\n");
	printMatrix(mat2);


	freeMatrix(mat);
	freeMatrix(mat2);
	return 0;
}
