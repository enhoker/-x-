#include <stdio.h> 
#include <stdlib.h> 

typedef struct node {
	int value;
	struct node* prev;
	struct node* next;
} node;

typedef struct list {
	node* beg;
	node* fin;
} list;

list list_new(void) {
	list a;
	a.beg = NULL;
	a.fin = NULL;
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
}

int list_push(list* l, int a) {
	if (l == NULL) {
		return 1;
	};
	node q;
	q.value = a;
	if (l->fin == NULL) {
		l->beg = &q;
		l->fin = &q;
		return 0;
	};
	q.prev = l->fin;
	q.next = NULL;
	l->fin->next = &q;
	l->fin = &q;
	return 0;
}

int list_pop(list* l, int* x) {
	if (l == NULL) {
		return 1;
	};
	*x = l->fin->value;
	node* s = l->fin;
	if (l->fin->prev == NULL) {
		free(l->fin);
		return 0;
	};
	l->fin->prev->next = NULL;
	l->fin = l->fin->prev;
	free(s);
	return 0;
}

int list_unshift(list* l, int a) {
	if (l == NULL) {
		return 1;
	};
	node q;
	q.value = a;
	if (l->beg == NULL) {
		l->beg = &q;
		l->fin = &q;
		return 0;
	};
	q.prev = NULL;
	q.next = l->beg;
	l->beg->prev = &q;
	l->beg = &q;
	return 0;
}

int list_shift(list* l, int* x) {
	if (l == NULL) {
		return 1;
	};
	*x = l->beg->value;
	node* s = l->beg;
	if (l->fin->prev == NULL) {
		free(l->fin);
		return 0;
	};
	l->beg->next->prev = NULL;
	l->beg = l->beg->next;
	free(s);
	return 0;
}