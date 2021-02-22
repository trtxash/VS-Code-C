#include <stdio.h>
int main(void)
{
    int i, j;
    for (i = 1; i < 4; i++)
    {
        for (j = i; j < 4; j++)
            printf("%d * %d = %d  ", i, j, i * j);
        printf("\n");
    }

    return 0;
}
