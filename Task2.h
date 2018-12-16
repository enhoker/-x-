#include <stdio.h>
#include <stdlib.h>
#include "Task1.h"

//Функция, создающая лист N, N - 1, N - 2, ... ,
// 2, 1; Она просто создает лист ф-ей list_new(),
//и заполняет нужными числами ф-ей insert.
//Эти функции были реализованы в 1.1
List* first_integers(int N) {
	List* temp = list_new();
	int i;
	for (i = 1; i <= N; ++i) {
		insert(temp, i);
	}
	return temp;
}
