#include <stdio.h>
#include <stdlib.h>
#include "Task8.h"

// Функция check_tree проверяет, является ли поддерево вершины tree АВЛ-деревом
//Функция принимает указатель на вершину, поддерево которой мы хотим проверить, 
// и указатель на переменную, в которую мы будем записывать глубину поддерева
// Функция возвращает 1, если поддерево является АВЛ-деревом и 0 в противном случае
int check_tree(struct Point * tree, int * depth) {
	int check = 0, left = 0, right = 0;
	check = check_tree(tree->left, &left) * check_tree(tree->right, &right);
	*depth = max(left, right) + 1;
	return check;
}

