#include "stdio.h"

struct ClassA {
    int a;
    char b[5];
};

typedef struct ClassA ClassA;

int main() {
    //struct ClassA;
    ClassA a;
    int s1 = sizeof(a);
    printf("s1 sizeof :%d.", s1);
}
