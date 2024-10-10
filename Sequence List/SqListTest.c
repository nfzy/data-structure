// #include <stdio.h>

// typedef struct
// {
//     int data[20]; /* 数组，存储数据元素 */
//     int length;   /* 线性表当前长度 */
// } SqList;

// /* 初始化顺序线性表 */
// int InitList(SqList *L)
// {
//     L->length = 0;
//     return 1;
// }

// int ListInsert(SqList *L, int i, int e);
// int ListDelete(SqList *L, int i, int *e);

// int main(int argc, char const *argv[])
// {
//     SqList L;
//     InitList(&L);
//     ListInsert(&L, 1, 5);
//     ListInsert(&L, 2, 955);
//     ListInsert(&L, 3, 99);
//     ListInsert(&L, 4, 19);

//     for (int i = 0; i < (&L)->length; ++i)
//     {
//         printf("%d\n", L.data[i]);
//     }

//     int s = 0;
//     ListDelete(&L, 1, &s);
//     for (int i = 0; i < (&L)->length; ++i)
//     {
//         printf("%d\n", L.data[i]);
//     }
//     return 0;
// }

// int ListInsert(SqList *L, int i, int e)
// {
//     int k;
//     if (L->length == 20) /* 顺序线性表已经满 */
//         return 0;
//     if (i < 1 || i > L->length + 1) /* 当i比第一位置小或者比最后一位置后一位置还要大时 */
//         return 0;

//     if (i <= L->length) /* 若插入数据位置不在表尾 */
//     {
//         for (k = L->length - 1; k >= i - 1; k--) /* 将要插入位置之后的数据元素向后移动一位 */
//             L->data[k + 1] = L->data[k];
//     }

//     // 如果最开始长度为空，则插入第一个元素
//     L->data[i - 1] = e; /* 将新元素插入 */
//     L->length++;

//     return 1;
// }

// int ListDelete(SqList *L, int i, int *e)
// {
//     int k;
//     if (L->length == 0)
//         return 0;
//     if (i < 1 || i > L->length)
//         return 0;

//     *e = L->data[i - 1];
//     if (i < L->length) /* 若插入数据位置不在表尾 */
//     {
//         for (k = i; k < L->length; ++k) /* 将要插入位置之后的数据元素向后移动一位 */
//             L->data[k - 1] = L->data[k];
//     }
//     L->length--;

//     return 1;
// }

#include <stdio.h>

#define MAXSIZE 20    // 定义存储空间初始分配量
typedef int ElemType; // 定义变量，int可以替换

#define OK 1;
#define ERROR 0;

typedef int Status;

typedef struct
{
    int data[MAXSIZE]; // 存储数据元素
    int length;        // 标识数据长度
} SqList;

Status GetElem(SqList, int, ElemType *);
Status GetIndex(SqList, ElemType);
Status InitList(SqList *);
Status ListInsert(SqList *, int, ElemType);

int main(int argc, char const *argv[])
{
    SqList L;
    int i, j;
    InitList(&L);
    for (j = 1; j <= 5; j++)
        i = ListInsert(&L, 1, j);
    printf("%d\n", L.data[1]);
    // for (int i = 0; i < MAXSIZE; i++)
    // {
    //     // 向数组中添加数据
    //     L.data[i] = i * 19;

    //     // 每添加一次则长度就要增加1
    //     L.length++;
    // }

    // ElemType iNum = 0, oNum = 0;
    // printf("请输入你需要找哪一个位置的数字：");
    // scanf("%d", &iNum);
    // GetElem(L, iNum, &oNum);
    // printf("%d位置上的数字是：%d\n", iNum, oNum);

    // printf("请输入你需要找的数字：");
    // scanf("%d", &iNum);
    // GetIndex(L, iNum);
    // printf("%d数字的位置是：%d\n", iNum, GetIndex(L, iNum));

    return 0;
}
Status InitList(SqList *L)
{
    L->length = 0;
    return OK;
}

// 顺序线性表L存在，则1<=i<=ListLength(L);
// 返回第i个元素的值
// 注意最后参数的值是指针
Status GetElem(SqList L, int i, ElemType *e)
{
    // 顺序线性表长度不能为0或者大于数组的长度，即在1和长度之间
    if (i < 1 || i > L.length || L.length == 0)
    {
        return ERROR;
    }

    // 想要把值带出去就要使用指针, i-1才是索引值
    *e = L.data[i - 1];

    // 如果能执行到这一步说明他符合之前定义的标准
    return OK;
}

Status GetIndex(SqList L, ElemType e)
{
    int i;
    // 顺序线性表长度不能为0或者大于数组的长度，即在1和长度之间
    if (i == 0 || i >= L.length)
    {
        return ERROR;
    }
    for (i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
            break;
    }

    return i + 1;
}

Status ListInsert(SqList *L, int i, ElemType e)
{
    int k;
    if (L->length == MAXSIZE) /* 顺序线性表已经满 */
        return ERROR;
    if (i < 1 || i > L->length + 1) /* 当i比第一位置小或者比最后一位置后一位置还要大时 */
        return ERROR;

    if (i <= L->length) /* 若插入数据位置不在表尾 */
    {
        for (k = L->length - 1; k >= i - 1; k--) /* 将要插入位置之后的数据元素向后移动一位 */
            L->data[k + 1] = L->data[k];
    }
    L->data[i - 1] = e; /* 将新元素插入 */
    L->length++;

    return OK;
}