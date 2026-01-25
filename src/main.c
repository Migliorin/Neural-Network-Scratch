#include<stdlib.h>
#include<stdio.h>


struct Node{
	float *grad;
	int *adjCount;
	struct Node **array;
};

struct Node* createNode(){
	struct Node *node = (struct Node*)malloc(sizeof(struct Node));
	struct Node **array = (struct Node**)malloc(sizeof(struct Node *));

	float *grad = (float *)malloc(sizeof(float));
	int *adjCount = (int *)malloc(sizeof(int));

	if(grad == NULL || node == NULL || adjCount == NULL || array == NULL){
		free(grad);
		free(node);
		free(adjCount);
		free(array);

		printf("Erro de alocacao de memoria\n");
		return NULL;
	}

	*grad = 0.0;
	*adjCount = 0;
	node->grad = grad;
	node->adjCount = adjCount;
	node->array = array;
	return node;
}


void addNodeAdj(struct Node *from, struct Node *to){
	(*from->adjCount)++;
	printf("Qtd: %d\n",*from->adjCount);

	from->array = (struct Node**)realloc(from->array,(*from->adjCount) * sizeof(struct Node *));

	from->array[*from->adjCount -1] = to;
}


int main(){

	//printf("Hello world!");
	struct Node *a = createNode();
	struct Node *b = createNode();
	struct Node *c = createNode();

	*a->grad = 1.0;
	*b->grad = 1.2;
	*c->grad = 0.98;

	addNodeAdj(a,b);
	addNodeAdj(a,c);


	printf("Grad do primeiro valor %f\n",*(a->array[0])->grad);
	printf("Grad do ultimo valor %f\n",*(a->array[1])->grad);


	return 0;
}
