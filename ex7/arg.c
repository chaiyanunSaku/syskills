#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int ans = 0;
	for (int i=0; i<argc; i++) {
		ans += atoi(argv[i]);
	}
	printf("%d\n", ans);
	return 0;
}
