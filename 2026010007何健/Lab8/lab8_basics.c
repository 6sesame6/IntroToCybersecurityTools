#include <stdio.h>

/* 学号 2026010007 的 10 位数字，逐位存入数组。 */
int add(int x, int y) {
    int result = x + y;
    return result;
}

int main(void) {
    printf("Student ID: 2026010007\n");
    int number = 7;
    int student_id[10] = {2,0,2,6,0,1,0,0,0,7};

    if (number >= 5) {
        printf("number >= 5\n");
    } else {
        printf("number < 5\n");
    }

    printf("Loop ID: ");
    for (int i = 0; i < 10; i = i + 1) {
        printf("%d", student_id[i]);
    }
    printf("\n");

    int sum = add(student_id[0], student_id[9]);
    printf("sum = %d\n", sum);

    int *p = &number;
    printf("before: number = %d, *p = %d\n", number, *p);
    *p = 26;
    printf("after: number = %d, *p = %d\n", number, *p);



    return 0;
}
