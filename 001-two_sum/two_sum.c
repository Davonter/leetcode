#include <stdio.h>
#include <stdlib.h>

static int *twosum(int *nums, int numsSize, int target)
{
    static int array[2] = {0};
    
    int i = 0, j = 0;
    
    for(i = 0; i < numsSize; i++)
    {
        for(j = i+1; j < numsSize; j++)
        {
            if(target == nums[i] + nums[j])
            {
                array[0] = i;
                array[1] = j;
                
                return array;
            }
        }
    }
    
    return NULL;
}

int main(void)
{
    int a[5] = {4, 2, 6, 1, 2};
    int target = 7;
    
    int *answer = twosum(a, 5, target);
    
    printf("answer[0] = %d, answer[1] = %d\n", answer[0], answer[1]);
    
    return 0;
}