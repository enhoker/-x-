#include <stdio.h> 
#include <stdlib.h> 
#include "Tack1_3"

int main(void) {
	char c = '0';
	int x;
	list* l = list_new();
	while (c != '\n') {
		scanf_s("%c", &c);
		if (c == '(') push(l, 0);
		if (c == '{') push(l, 1);
		if (c == ')') {
			pop(l, &x);
			if (x != 0) {
				printf("NO");
				return 0;
			}
		}
		if (c == '}') {
			pop(l, &x);
			if (x != 1) {
				printf("NO");
				return 0;
			}
		}
	}
	if (l->head != NULL) printf("NO");
	else printf("YES");

	return 0;
}
