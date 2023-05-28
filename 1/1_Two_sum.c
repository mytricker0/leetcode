#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* ret = NULL;
    int retSize = 0;

    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                retSize += 2;
                ret = (int*)realloc(ret, sizeof(int) * retSize);
                ret[retSize - retSize] = i;
                ret[retSize>>1] = j;
            }
        }
    }

    *returnSize = retSize;
    return ret;
}
int main(int argc, char const *argv[])
{
    int nums[] = {-1,-2,-3,-4,-5};
    int target = -8;
    int *ret;
    int retSize = 0;
    int* yes = twoSum(nums, sizeof(nums)/sizeof(int), target, &retSize);
    
    printf("Output: ");
    for (int i = 0; i < retSize; i++) {
        printf("%d ", yes[i]);
    }
    printf("\n");
}
