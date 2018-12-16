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

void insert(struct Notebook * N, char* name, long long int number) {
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
}
