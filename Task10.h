#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Структура "запись в телефонной книжке"
struct Record {
	char* name;
	long long int number;
};

// Структура "Телефонная книжка"
struct Notebook {
	struct Record * book; // Массив записей
	int busy; // Количество записей
	int site; // Количество "листов" в записной книжке
};

// Поиск записи в книжке
int find(struct Notebook * N, char * name) {
	int i = 0;
	// Просто пройдёмся по массиву записей, за O(n)
	for (i = 0; i < N->busy; i++) {
		if (N->book[i].name == name) {
			printf("number %lld", N->book[i].number);
			return 0; // код 0 - поиск увенчался успехом
		}
	}
	printf("NO");
	return 1; // код 1 - запись не найдена
}

// Добавление записи
int insert(struct Notebook * N, char* name, long long int number) {
	int i = 0;
	// Проверим, нет ли уже подходящей записи
	for (i = 0; i < N->busy; i++) {
		if (N->book[i].name == name) {
			printf("Changed. Old value = %ld", N->book[i].number);
			N->book[i].number = number;
			return 1; // код 1 - произошла замена старой записи
		}
	}
	// Увличим, если надо, буфер
	if (N->site - N->busy < 1) {
		struct Record * tmp = malloc(sizeof(struct Record) * N->site * 2);
		memcpy(tmp, N->book, sizeof(struct Record) * N->busy);
		free(N->book);
		N->book = tmp;
		N->site = 2 * N->site;
	}
	// И, наконец, добавим запись
	N->book[N->busy].name = name;
	N->book[N->busy].number = number;
	N->busy++;
	return 0;
}
