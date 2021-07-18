#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int compare_ints(const void *a, const void *b)
{
    int arg1 = *(const int *)a;
    int arg2 = *(const int *)b;
    return (arg1 > arg2) - (arg1 < arg2);
    // 可行的简写
    // return arg1 - arg2; // 错误的简写（若给出 INT_MIN 则会失败）
}

int main(void)
{
    int ints[] = {-2, 99, 0, -743, 2, INT_MIN, 4};
    int size = sizeof ints / sizeof *ints;

    qsort(ints, size, sizeof(int), compare_ints);

    for (int i = 0; i < size; i++)
    {
        printf("%d ", ints[i]);
    }

    printf("\n");
}