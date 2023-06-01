#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char * longestCommonPrefix(char ** strs, int strsSize) {
    if (strsSize == 0) return "";

    // Start by assuming the shortest string is the first one
    int shortestLength = strlen(strs[0]);

    // Iterate over the rest of the strings to find the actual shortest
    for(int i = 1; i < strsSize; i++) {
        int length = strlen(strs[i]);
        if(length < shortestLength) {
            shortestLength = length;
        }
    }

    char *common = (char *)malloc((shortestLength + 1) * sizeof(char));
    common[0] = '\0';

    for (int i = 0; i < shortestLength; i++) {
        // Get the current character of the first string
        char c = strs[0][i];

        // Check if this character is the same in all strings
        for (int j = 1; j < strsSize; j++) {
            // If we found a string where the current character is different,
            // set the common prefix length to the current index and break
            if (strs[j][i] != c) {
                common[i] = '\0';
                return common;
            }
        }

        // If we reached this point, the current character is the same in all strings,
        // so add it to the common prefix
        common[i] = c;
        common[i + 1] = '\0'; // Don't forget to keep your string null-terminated
    }

    return common;
}

int main(int argc, char const *argv[]) {
    char *strs[] = {"flower","flow","flight"};
    int strsSize = 3;
    char * common = longestCommonPrefix(strs, strsSize);
    printf("common is %s\n", common);
    free(common);

    return 0;
}
