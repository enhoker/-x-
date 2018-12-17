#include <stdio.h>
#include <stdlib.h>
//#include <stdbool.h>
#include <string.h>
#include <time.h>

#define n 10

struct A {
	int x;
	unsigned int y;
	int l;
	char* z;
};

int main() {
	int u;
//	int n = 10;
	struct A *a = malloc(sizeof(struct A)*n);
	int i = 0, j;
	srand(time(NULL));
	for (; i < n; i++) {
		a[i].x = rand() * (-1)*(2*(rand() % 2) - 1);
		a[i].y = (rand() % 10) - 1;
		a[i].l = rand() % 20 + 3;
		a[i].z = malloc(a[i].l * sizeof(char));
		for (j = 0; j < a[i].l; j++) {
			a[i].z[j] = 'A' + (rand() % 25);
		}
		
	}

	for (i = 0; i < n; i++) {
		printf("(%d, %d, ", a[i].x, a[i].y);
		for (j = 0; j < a[i].l; j++) {
			printf("%c", a[i].z[j]);
		}
		printf(") \n");
	}
	
	scanf_s("%d", &u);
	return 0;
}
