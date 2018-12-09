#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
	int value;
	struct Node* next;
} Node;

typedef struct List {
	Node* beg;
} List;

List list_new(void) {
	List a;
	a.beg = NULL;
	return a;
}

void list_delete(List* l) {
	Node* a = l->beg;
	Node* b;
	while (a != NULL) {
		b = a;
		a = b->next;
		free(&b);
	}
	free (l);
}

void insert(List* l, int a) {
	Node q;
	q.value = a;
	q.next = l->beg;
	l->beg = &q;
}

void list_remove(List* l, int a) {
	Node* last = NULL;
	Node* i = l->beg;
	Node* j;
	while (i != NULL) {
		if (i->value == a) {
			if (last == NULL) l->beg = i->next;
			else last->next = i->next;
			j = i;
			i = i->next;
			free(&j);
		}
		else {
			last = i;
			i = i->next;
		}

	}
}

void list_print(List* l) {
	Node* i = l->beg;
	while (i != NULL) {
		printf("%d, ", i->value);
	}
}
