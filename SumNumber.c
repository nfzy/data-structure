#include <stdio.h>

int main(int argc, char const *argv[])
{

    int i, sum = 0, iNum = 0;
    printf("请输入求和到几位数：");
    scanf("%d", &iNum);

    for (i = 0; i <= iNum; ++i)     
    {
        sum += i;                       // n
        printf("sum is: %d\t", sum);    // n
    }
    printf("\n");                       // 1

    
    sum = (1 + iNum) * iNum / 2;        // 1
    printf("Sum is: %d\n", sum);        // 1

    return 0;
}
