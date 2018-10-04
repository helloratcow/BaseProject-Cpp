#include <stdio.h>
#include "main.h"

#ifndef TEST
int main() {
    int x=0,y=0;
    printf("Rule Breaker!!!\n");
    printf("5 + 2 = %d\n", addNumber(5, 2));
    printf("%d\n", getTriangleType(3, 4, 5));

    printf("4 * 5 = %d\n", times(4, 5));

    printf("Hello, world\n");

    printf("a-no-ne a-no-ne\n");
    printf("MDFK\n");

    printf("%d\n",multiply(4, 4));
    printf("Hello, world\n");


    printf("a-no-ne a-no-ne\n");
    printf("MDFK\n");

    printf("fuck rat\n");
    printf("a-no-ne a-no-ne\n");

    printf("MDFK\n");


    return 0;
}
#endif // TEST

//YES


int addNumber(int a, int b) {
    return a + b;
}

int multiply(int a, int b){
    return a * b;
}

int getTriangleType(int a, int b, int c) {
    if (a > b && a > c) {
        int temp = c; c = a; a = temp;
    }
    else if (b > a && b > c) {
        int temp = c; c = b; b = temp;
    }

    if (a + b <= c) {
        return -2;
    }
    else if (a * a + b * b == c * c) {
        return 0;
    }
    else if (a * a + b * b > c * c) {
        return 1;
    }
    else if (a * a + b * b < c * c) {
        return -1;
    }
    return -3;
}
int times(int a, int b){
    return a * b;
}
