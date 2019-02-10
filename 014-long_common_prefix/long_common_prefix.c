#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize)
{
    if(0 == strsSize) return "";
    if(1 == strsSize) return strs[0];

    int index_str = 0;
    int i = 0;
    char* result = (char*)malloc(strlen(strs[0]) * sizeof(char));
    int m = 0;

    /*
     * 纵向比较：以第一个字符床长度为基准，对每个字符串的每个对应位置进行比较
     */
    for(index_str = 0; index_str < strlen(strs[0]) * sizeof(char); index_str++)
    {
        /* 遍历每个字符串 */
        for(i = 1; i < strsSize; i++)
        {
            if(strs[0][index_str] != strs[i][index_str])
            {
                result[m] = '\0';
                return result;
            }
        }

        result[m++] = strs[0][index_str];
    }

    result[m] = '\0';

    return result;
}

int main(void)
{
    char *condition_str[] = {"flower", "flow", "falight"};

    printf("%s\n", longestCommonPrefix(condition_str, 3));

    return 0;
}