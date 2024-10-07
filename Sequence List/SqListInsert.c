#include <stdio.h>

typedef struct
{
    int data[20]; /* 数组，存储数据元素 */
    int length;   /* 线性表当前长度 */
} SqList;

/* 初始化顺序线性表 */
int InitList(SqList *L)
{
    L->length = 0;
    return 1;
}

int ListInsert(SqList *L, int i, int e);
int ListDelete(SqList *L, int i, int *e);


int main(int argc, char const *argv[])
{
    SqList L;
    InitList(&L);
    ListInsert(&L, 1, 5);
    ListInsert(&L, 2, 955);
    ListInsert(&L, 3, 99);
    ListInsert(&L, 4, 19);

    for (int i = 0; i < (&L)->length; ++i)
    {
        printf("%d\n", L.data[i]);
    }

    int s = 0;
    ListDelete(&L, 1, &s);
    for (int i = 0; i < (&L)->length; ++i)
    {
        printf("%d\n", L.data[i]);
    }
    return 0;
}

int ListInsert(SqList *L, int i, int e)
{
    int k;
    if (L->length == 20) /* 顺序线性表已经满 */
        return 0;
    if (i < 1 || i > L->length + 1) /* 当i比第一位置小或者比最后一位置后一位置还要大时 */
        return 0;

    if (i <= L->length) /* 若插入数据位置不在表尾 */
    {
        for (k = L->length - 1; k >= i - 1; k--) /* 将要插入位置之后的数据元素向后移动一位 */
            L->data[k + 1] = L->data[k];
    }

    // 如果最开始长度为空，则插入第一个元素
    L->data[i - 1] = e; /* 将新元素插入 */
    L->length++;

    return 1;
}

int ListDelete(SqList *L, int i, int *e)
{
    int k;
    if (L->length == 0)
        return 0;
    if (i < 1 || i > L->length)
        return 0;

    *e = L->data[i - 1];
    if (i < L->length) /* 若插入数据位置不在表尾 */
    {
        for (k = i; k < L->length; ++k) /* 将要插入位置之后的数据元素向后移动一位 */
            L->data[k - 1] = L->data[k];
    }
    L->length--;

    return 1;
}