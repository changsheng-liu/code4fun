#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ADD_SIZE 5
struct node{
	int x;
	int y;
};

struct dynArray {
	struct node ** arrayList;
	int size;
	int occupied;
};

struct dynArray * initDynamicArray() {
	struct dynArray * arr = malloc(sizeof(struct dynArray));
	arr->size = ADD_SIZE;
	arr->occupied = 0;
	arr->arrayList = calloc(ADD_SIZE,sizeof(struct node *));
	return arr;
}

void dynArrayAddItem(struct dynArray * a, struct node * n) {
	if (a->size == a->occupied) {
		a->arrayList = (struct node **)realloc(a->arrayList, (a->size+ADD_SIZE)*sizeof(struct node *));
		a->size = ADD_SIZE + a->size;
	}
	a->arrayList[a->occupied] = n;
	a->occupied++;
}

struct node * dynArrayget(struct dynArray * a, int idx) {
	if (idx >= a->occupied) {
		return NULL;
	}
	return *(a->arrayList+idx);
}

void dynArrayRemoveItem(struct dynArray * a, int idx) {
	if(idx < 0 || idx >= a->occupied) {
		return;
	}
	int t;
	for(t = idx; t < a->occupied-1; t++) {
		a->arrayList[t] = a->arrayList[t+1];
	}
	a->occupied--;
}

void destroyArray(struct dynArray * a) {
	int t;
	struct node * n;
	for(t = 0; t < a->occupied; t++) {
		n = dynArrayget(a, t);
		free(n);
//		memset(, 0x00, sizeof(struct node *));
	}
	free(a);
}


int main(int argc, char *argv[]) {
		struct dynArray * a = initDynamicArray();
		struct node * n1 = malloc(sizeof(struct node));
		n1->x = 1;
		n1->y = 1;
		struct node * n2 = malloc(sizeof(struct node));
		n2->x = 2;
		n2->y = 2;
		dynArrayAddItem(a, n1);
		dynArrayAddItem(a, n2);
		dynArrayAddItem(a, n1);
		dynArrayAddItem(a, n2);
		dynArrayAddItem(a, n1);
		dynArrayAddItem(a, n1);
		
		struct node * n;
		for (int i = 0;i<6;i++) {
			n = dynArrayget(a, i);
			printf("%d\n", n->y);
		}
		printf("~~~~~~~\n");

		dynArrayRemoveItem(a, 3);
		for (int i = 0;i<5;i++) {
			n = dynArrayget(a, i);
			printf("%d\n", n->y);
//			printf("--%p\n",n);
		}
//		free(n1);
		destroyArray(a);// this free function did not support this example. Two same node cannot be in one array
		
		return 1;
}