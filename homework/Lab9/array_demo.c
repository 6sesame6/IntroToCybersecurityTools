#include <stdio.h>

int main(void) {
    int numbers[3] = {4, 7, 10};
    int *p = &numbers[1];
    for (int i = 1; i < 3; i = i + 1) {
        int previous = *(p - 1);
        int current = *p;
        printf("previous = %d, current = %d\n", previous, current);
        p = p + 1;
    }
    return 0;
}
