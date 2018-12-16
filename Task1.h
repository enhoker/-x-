#include <stdlib.h>
#include <stdio.h>

//Структура "элемент списка"
typedef struct Node {
	//Значение в элементе
	int value;
	//Указатель на следующий элемент
	struct Node* next;
} Node;

//Структура "односвязный список"
typedef struct List {
	//Указатель на первый элемент списка (равный NULL для пустого списка)
	Node* beg;
} List;

//Создание нового пустого списка
List* list_new(void) {
	List* a = malloc(sizeof(void*));
	a->beg = NULL;
	return a;
}

//Удаление списка
void list_delete(List* l) {
	Node* a = l->beg;
	Node* b;
	while (a != NULL) {
		b = a;
		a = b->next;
		free(b);
	}
	free(l);
}

//Добавление элемента а в список l
void insert(List* l, int a) {
	Node* q = malloc(sizeof(int) + sizeof(void*));
	q->value = a;
	q->next = l->beg;
	l->beg = q;
}

//Удаление из списка l всех элементов со значением а
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
			free(j);
		}
		else {
			last = i;
			i = i->next;
		}

	}
}

//Печать списка
void list_print(List* l) {
	Node* i = l->beg;
	while (i != NULL) {
		printf("%d, ", i->value);
		i = i->next;
	}
}
