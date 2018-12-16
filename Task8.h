#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data; // ключ
	float value; // значение
	struct node * left;
	struct node * right;
};

struct tree
{
	struct node * root;   // Указатель на корень дерева
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
	const struct node * search_node;
	search_node = search_tree->root;
	for (;;)
	{
		if (search_node == NULL) return 0;
		else if (item == search_node->data) return 1;
		else if (item > search_node->data) search_node = search_node->right;
		else search_node = search_node->left;
	}
}

// Вставка элемента в дерево
int insert(struct tree * search_tree, int item, float val)
{
	struct node * search_node, **new;
	new = &search_tree->root;
	search_node = search_tree->root;
	for (;;)
	{	
		if (search_node == NULL) // Если мы нашли, куда вставлять вершину - вставим её
		{
			search_node = *new = malloc(2 * sizeof(void *) + sizeof(int) + sizeof(float));
			if (search_node != NULL)
			{
				search_node->data = item;
				search_node->value = val;
				search_node->left = search_node->right = NULL;
				search_tree->count++;
				return 0; // Возвращаем 0, если функция выполнилась без ошибок 
			}
			else return 1; // Возвращаем 1, если произошла какая-то непонятная ошибка
		}
		else if (item == search_node->data) return 2; // Если значение продублировалось - возвращаем код ошибки 2
		
		// Если ещё не нашли - продолжаем углубляться в дерево
		else if (item > search_node->data)
		{
			new = &search_node->right;
			search_node = search_node->right;
		}
		else
		{
			new = &search_node->left;
			search_node = search_node->left;
		}
	}
}

// Удаление вершины по ключу
int delete(struct tree * search_tree, int ** item)
{
	struct node ** q, *z;

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
		struct node * y = z->right;
		if (y->left == NULL)
		{
			y->left = z->left;
			*q - y;
		}
		else
		{
			struct node * x = y->left;
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
void destroy(struct node * search_node)
{
	if (search_node == NULL) return;
	destroy(search_node->left);
	destroy(search_node->right);
	free(search_node);
}

// Полное удаление дерева
void destroy_tree(struct tree * search_tree)
{
	destroy(search_tree->root);
	free(search_tree);
}

// Обход в глубину - через рекурсию
void DFS(struct node * search_node) {
	printf("(%d, %f), ", search_node->data, search_node->value);
	DFS(search_node->left);
	DFS(search_node->right);
}
