#include <stdio.h>
int main()
{
    int a[ ][3] = { {1,4}, {3,2}, {4,5,6}, {0} };
    printf("%d\n", a[0][0]);
    printf("%d\n", a[0][1]);
    printf("%d\n", a[0][2]);
    printf("%d\n", a[1][0]);
    printf("%d\n", a[1][1]);
    printf("%d\n", a[1][2]);
    printf("%d\n", a[2][0]);
    printf("%d\n", a[2][1]);
    printf("%d\n", a[2][2]);
}
