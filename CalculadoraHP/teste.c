#include <stdio.h>

int main() {
    int temp;

    printf(" 1 :");
    scanf(" %d%*d\n " ,&temp);
    fflush(stdin);
    printf(" %d%*d\n ", temp);

    printf(" 2 : ");
    scanf(" %d%*d\n ", &temp);
    printf(" %d%*d\n ", temp);
    return 0;
}