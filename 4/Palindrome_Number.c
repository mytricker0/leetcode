#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
bool isPalindrome(int x){
    int nDigits = floor(log10(abs(x))) + 1;
    char str[nDigits];  // Ensure the string is large enough to hold the number
    sprintf(str, "%d", x);
    int len = strlen(str);
    int i = 0;
    for (i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return false;
        }
    }
    return true;
}


int main(int argc, char const *argv[])
{
    int num = 12345;
    printf("%d\n", isPalindrome(num));

    return 0;
}
