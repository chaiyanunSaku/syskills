#include <stdio.h>

int my_str_len(char *s) {
    // implement me
    int ans = 0;
    while (*s != '\0') {
        ans++;
        s++;
    }
    return ans;
}

int main() {
    char s[] = "Hello, Syskill folks!";
    int len = my_str_len(s);
    printf("Length of \"%s\": %d\n", s, len); // Expected output: 21
    return 0;
}
