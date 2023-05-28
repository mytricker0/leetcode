#include <stdio.h>
#include <string.h>

#define MAX_CHARS 256
int max(int a, int b) {
    return (a > b) ? a : b;
}
int lengthOfLongestSubstring(char *s) {
    int n = strlen(s);
    int res = 0; // result
    
    // last index of all characters is initialized as -1
    int lastIndex[MAX_CHARS]; 
    memset(lastIndex, -1, sizeof(lastIndex));

    int i = 0; // Starting index of current window

    for (int j = 0; j < n; j++) {

        // Find the last index of str[j]
        // Update i (starting index of current window) as maximum of current value of i and last index plus 1
        i = max(i, lastIndex[s[j]] + 1);

        // Update the result if max is obtained
        res = max(res, j - i + 1);

        // Update last index of j.
        lastIndex[s[j]] = j;
    }
    return res;
}

// A utility function to find the maximum of two numbers


// Driver code
int main() {
    char *s = "abcabcbb";
    printf("The input string is %s \n", s);
    int len = lengthOfLongestSubstring(s);
    printf("The length of the longest non-repeating character substring is %d", len);
    
    return 0;
}