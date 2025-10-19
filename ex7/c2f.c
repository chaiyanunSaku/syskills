#include <stdio.h>

float c2f(int c) {
	float ans = ((9.0*c)/5.0)+32;
	return ans;
}

int main() {
	int lb, ub;
	printf("lower limit: ");
	scanf("%d", &lb);
	printf("upper limit: ");
	scanf("%d", &ub);
	printf("%s%15s\n", "Celcius", "Fahrenheit");
	while (lb <= ub) {
		float f = c2f(lb);
		printf("%7d%15.1f\n", lb, f);
		lb +=5;
	}
	return 0;
}
