#include <stdio.h>
#include <string.h>

int same_text(const char *left, const char *right) {
    int result = strcmp(left, right);
    return result == 0;
}

int main(void) {
    char input[] = "Hi";
    char expected[] = "Hi";
    int same = same_text(input, expected);
    if (same) {
        printf("same\n");
    } else {
        printf("different\n");
    }
    return 0;
}
