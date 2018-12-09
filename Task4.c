#include <stdio.h> 
#include <stdlib.h> 
#include "Tack1_3"

int main(void) {
	char c = '0';
	int x;
	struct list l = list_new();
	while (c != '\n') {
		scanf("%c", &c);
		if (c == '(') list_push(&l, 0);
		if (c == '{') list_push(&l, 1);
		if (c == ')') {
			list_pop(&l, &x);
			if (x != 0) {
				printf("NO");
				return 0;
			}
		}
		if (c == '}') {
			list_pop(&l, &x);
			if (x != 1) {
				printf("NO");
				return 0;
			}
		}
	} 
	if (l.beg != NULL) printf("NO");
	else printf("YES");
}
