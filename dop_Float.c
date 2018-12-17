#include <stdio.h>
#include <stdlib.h>
//#include <stdbool.h>
#include <string.h>
union ann {
	float q;
	struct float_t {
		unsigned matiss : 23;
		unsigned exp : 8;
		unsigned sign : 1;
	};
};

int main() {
	int u;
	union ann d;
	scanf_s("%f", &d.q);
	printf("%f\n", d.q); 

	printf("%x %x %x \n", d.sign, d.exp, d.matiss);

	unsigned long long int  r;
	r = d.q;
	memcpy(&r, &d, 8);
	int i;
	int sight;

	for (i = 0; i < 32; i++) {
		sight = ((r << i) >> 31) & 1;
		printf("%d", sight);
		if (i == 0 || i == 8) printf(" ");
	}

	scanf_s("%d", &u);
	return 0;
}
