#include <stdio.h>

int main() {
    int num = 12345;
    char str[10];  // Ensure the string is large enough to hold the number

    sprintf(str, "%d", num);
    printf("The string is: %s\n", str);
return 0;
}


