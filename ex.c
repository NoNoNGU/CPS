#include <stdio.h>

int sum(int a, int b){
    return (a+b);
}

int main() {
    int a,b ,result;
    scanf("%d %d", &a, &b);
    result = sum(a,b);
    printf("%d\n", result);
    return 0;
}
