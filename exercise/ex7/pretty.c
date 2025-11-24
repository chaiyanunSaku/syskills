#include <stdio.h>

void print_32() {
	for (int i=0; i<32; i++) {
		printf("=");
	}
	printf("\n");
}

int main() {
	char s[3][11];
	int n[3];

	for (int i=0; i<3; i++) {
		printf("Enter 3 paris, pair %d:<String> <Integer> :", i+1);
		scanf("%10s", s[i]);
		scanf("%d", &n[i]);
	}
	print_32();

	for (int i=0; i<3; i++) {
		printf("%-15s%03d\n", s[i], n[i]);
	}
	print_32();

	return 0;
}


