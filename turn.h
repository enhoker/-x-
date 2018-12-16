#include <stdio.h> 
#include <stdlib.h> 

typedef struct node {
	int value;
	void * data;
	struct node* prev;
	struct node* next;
} node;

typedef struct list {
	node* beg;
	node* fin;
} list;

list* list_new(void) {
	list* a = malloc(sizeof(int) + 2 * sizeof(void*));
	a->beg = NULL;
	a->fin = NULL;
	return a;
}

int list_delete(list* l) {
	node* a = l->beg;
	node* b;
	if (a == NULL) {
		return 1;
	}
	while (a != NULL) {
		b = a;
		a = b->next;
		free(&b);
	}
	free(l);
	return 0;
}

int list_push(list* l, void * a) {
	if (l == NULL) {
		return 1;
	};
	node* q = malloc(sizeof(int) + 2 * sizeof(void*));
	q->data = a;
	if (l->fin == NULL) {
		l->beg = q;
		l->fin = q;
		return 0;
	};
	q->prev = l->fin;
	q->next = NULL;
	l->fin->next = q;
	l->fin = q;
	return 0;
}

int list_shift(list* l, void ** x) {
	if (l == NULL) {
		exit(1);
	};
	if (l->beg == NULL) {
		exit(1);
	};
	if (l->beg) {
		*x = l->beg->data;
		if (l->fin == l->beg) {
			free(l->fin);
			l->fin = NULL;
			l->beg = NULL;
			return 0;
		}
		else {
			node * tmp = l->beg->next;
			free(l->beg);
			l->beg = tmp;
			return 0;
		};
	};
}
