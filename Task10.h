#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Record {
	char* name;
	long long int number;
};

struct Notebook {
	struct Record * book;
	int busy;
	int site;
};

int find(struct Notebook * N, char * name) {
	int i = 0;
	for (i = 0; i < N->busy; i++) {
		if (N->book[i].name == name) {
			printf("number %lld", N->book[i].number);
			return 0;
		}
	}
	printf("NO");
	return 1;
}

// Добавление записи
int insert(struct Notebook * N, char* name, long long int number) {
	int i = 0;
	for (i = 0; i < N->busy; i++) {
		if (N->book[i].name == name) {
			printf("Changed. Old value = %ld", N->book[i].number);
			N->book[i].number = number;
			return 1;
		}
	}
	if (N->site - N->busy < 1) {
		struct Record * tmp = malloc(sizeof(struct Record) * N->site * 2);
		memcpy(tmp, N->book, sizeof(struct Record) * N->busy);
		free(N->book);
		N->book = tmp;
		N->site = 2 * N->site;
	}
	N->book[N->busy].name = name;
	N->book[N->busy].number = number;
	N->busy++;
	return 0;
}
