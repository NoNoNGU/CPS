#include <stdio.h>
#include <stdlib.h>

void success() {
       printf("Success!\n");
}

int main() {
      int var1 = 0;          
      int var2 = 9;          
      int input;             

    printf("Enter a number: ");

    scanf("%d", &input);

    if (input == var2) {
        success();
    } else {
        puts("Failure");
    }

    return 0;
}
