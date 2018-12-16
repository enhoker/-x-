#include <stdio.h>
#include <stdlib.h>
#include "turn.h"

struct Point
{
	int data; // ключ
	float value; // значение
	struct Point * left;
	struct Point * right;
};

struct tree
{
	struct Point * root;   // Указатель на корень дерева
	int count;            // Количество узлов в дереве
};

// Создание нового дерева
struct tree * tree_create(void)
{
	struct tree * new_tree = malloc(sizeof(void *) + sizeof(int));
	if (new_tree == NULL) return NULL;
	new_tree->root = NULL;
	new_tree->count = 0;
	return new_tree;
}

// Поиск вершины с ключом item в дереве search_tree
int bin_search(const struct tree * search_tree, int item)
{
	const struct Point * search_Point;
	search_Point = search_tree->root;
	for (;;)
	{
		if (search_Point == NULL) return 0;
		else if (item == search_Point->data) return 1;
		else if (item > search_Point->data) search_Point = search_Point->right;
		else search_Point = search_Point->left;
	}
}

// Вставка элемента в дерево
int insert(struct tree * search_tree, int item, float val)
{
	struct Point * search_Point, **new;
	new = &search_tree->root;
	search_Point = search_tree->root;
	for (;;)
	{
		if (search_Point == NULL) // Если мы нашли, куда вставлять вершину - вставим её
		{
			search_Point = *new = malloc(2 * sizeof(void *) + sizeof(int) + sizeof(float));
			if (search_Point != NULL)
			{
				search_Point->data = item;
				search_Point->value = val;
				search_Point->left = search_Point->right = NULL;
				search_tree->count++;
				return 0; // Возвращаем 0, если функция выполнилась без ошибок 
			}
			else return 1; // Возвращаем 1, если произошла какая-то непонятная ошибка
		}
		else if (item == search_Point->data) return 2; // Если значение продублировалось - возвращаем код ошибки 2

		// Если ещё не нашли - продолжаем углубляться в дерево
		else if (item > search_Point->data)
		{
			new = &search_Point->right;
			search_Point = search_Point->right;
		}
		else
		{
			new = &search_Point->left;
			search_Point = search_Point->left;
		}
	}
}

// Удаление вершины по ключу
int delete(struct tree * search_tree, int ** item)
{
	struct Point ** q, *z;

	q = &search_tree->root;
	z = search_tree->root;
	// Поиск удаляемого элемента
	for (;;)
	{
		if (z == NULL) return 0;
		else if (item == (int **)z->data) break;
		else if (item > (int **)z->data)
		{
			q = &z->right;
			z = z->right;
		}
		else
		{
			q = &z->left;
			z = z->left;
		}
	}

	// Собственно удаление элемента
	if (z->right == NULL) *q = z->left;
	else
	{
		struct Point * y = z->right;
		if (y->left == NULL)
		{
			y->left = z->left;
			*q - y;
		}
		else
		{
			struct Point * x = y->left;
			while (x->left != NULL)
			{
				y = x;
				x = y->left;
			}
			y->left = x->right;
			x->left = z->left;
			x->right = z->right;
			*q = x;
		}
	}
	search_tree->count--;
	free(z);
	return 1;
}

// Удаление отдельного узла дерева и его потомков
void destroy(struct Point * search_Point)
{
	if (search_Point == NULL) return;
	destroy(search_Point->left);
	destroy(search_Point->right);
	free(search_Point);
}

// Полное удаление дерева
void destroy_tree(struct tree * search_tree)
{
	destroy(search_tree->root);
	free(search_tree);
}

// Обход в глубину - через рекурсию
void DFS(struct Point * search_Point) {
	printf("(%d, %f), ", search_Point->data, search_Point->value);
	DFS(search_Point->left);
	DFS(search_Point->right);
}

// Обход в ширину - через очередь
void BFS(struct tree search_tree) {
	list * l = list_new();
	struct Point * a = search_tree.root;
	list_push(l, a);
	int i = 0;
	for (i = 0; i < search_tree.count; i++) {
		list_shift(l, &a);
		printf("(%d, %f), ", a->data, a->value);
		list_push(l, a->left);
		list_push(l, a->right);
	}
}

int main() {
	return 0;
}
