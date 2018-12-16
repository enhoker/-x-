#include <stdio.h> 
#include <stdlib.h> 
//Структура "ячейка" - целое число +
//2 ссылки на пред. и след. элементы
typedef struct node {
	int value;
	struct node* prev;
	struct node* next;
} node;
//Структура дв. списка - 2 ссылки на
//начало и конец списка.
typedef struct list {
	node* beg;
	node* fin;
} list;
//Функция создания пустого списка
//Выделение памяти для двух ссылок
list* list_new(void) {
	list* a = malloc(2 * sizeof(void*));
	a->beg = NULL;
	a->fin = NULL;
	return a;
}
//Удаление списка. Последовательно
//освобождается память для всех ячеек
//а затем освобождается память, в которой
//хранились ссылки на начальный и конечный элементы списка
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
//Добавление элемента в конец
//Занимаем память для него и "привязываем"
//его к концу списка. Если список пуст
//делаем новый элемент началом и концом этого списка
int list_push(list* l, int a) {
	if (l == NULL) {
		return 1;
	};
	node* q = malloc(sizeof(int) + 2 * sizeof(void*));
	q->value = a;
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
//Удаляем элемент с конца.
//Если список пуст, ничег не делаем,
//вернется исключение.
//Если в списке один элемент,
//Делаем список пустым
int list_pop(list* l, int* x) {
	if (l == NULL) {
		exit(1);
	};
	if (l->fin == NULL) {
		exit(1);
	};
	if (l->fin) {
		*x = l->fin->value;
		if (l->fin == l->beg) {
			free(l->fin);
			l->fin = NULL;
			l->beg = NULL;
			return 0;
		}
		else {
			node * tmp = l->fin->prev;
			free(l->fin);
			l->fin = tmp;
			return 0;
		};
	};
}
//Аналогично Push, но в начале
int list_unshift(list* l, int a) {
	if (l == NULL) {
		return 1;
	};
	node* q = malloc(sizeof(int) + 2 * sizeof(void*));
	q->value = a;
	if (l->beg == NULL) {
		l->beg = q;
		l->fin = q;
		return 0;
	};
	q->prev = NULL;
	q->next = l->beg;
	l->beg->prev = q;
	l->beg = q;
	return 0;
}
//Аналогично Pop, но в начале
int list_shift(list* l, int* x) {
	if (l == NULL) {
		exit(1);
	};
	if (l->beg == NULL) {
		exit(1);
	};
	if (l->beg) {
		*x = l->beg->value;
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
