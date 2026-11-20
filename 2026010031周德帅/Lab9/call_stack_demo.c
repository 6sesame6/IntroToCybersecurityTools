#include <stdio.h>

static int D(int x) {
    int result = x + 1;
    return result;  /* 在这里下断点，此时 A、B、C 都在等待返回。 */
}

static int C(int x) {
    return D(x + 1);
}

static int B(int x) {
    return C(x + 1);
}

static int A(int x) {
    return B(x + 1);
}

int main(void) {
    int answer = A(1);
    printf("answer = %d\n", answer);
    return 0;
}
