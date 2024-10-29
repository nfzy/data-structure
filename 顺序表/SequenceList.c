#include <stdio.h>

#define MAX_SIZE 100 // 最大容量

typedef struct
{
    int data[MAX_SIZE]; // 静态数组
    int size;           // 当前元素数量
} SeqList;

// 创建顺序表
void initSeqList(SeqList *list)
{
    list->size = 0;
}

// 判断顺序表是否为空
int isEmpty(SeqList *list)
{
    return list->size == 0;
}

// 插入元素
int insert(SeqList *list, int index, int value)
{
    if (index < 0 || index > list->size || list->size >= MAX_SIZE)
    {
        return -1; // 插入失败
    }
    for (int i = list->size; i > index; i--)
    {
        list->data[i] = list->data[i - 1]; // 移动元素
    }
    list->data[index] = value; // 插入新元素
    list->size++;
    return 0; // 插入成功
}

// 删除元素
int delete(SeqList *list, int index)
{
    if (index < 0 || index >= list->size)
    {
        return -1; // 删除失败
    }
    for (int i = index; i < list->size - 1; i++)
    {
        list->data[i] = list->data[i + 1]; // 移动元素
    }
    list->size--;
    return 0; // 删除成功
}

// 测试
int main()
{
    SeqList list;
    initSeqList(&list);

    printf("顺序表是否为空: %d\n", isEmpty(&list));

    insert(&list, 0, 10);
    insert(&list, 1, 20);
    insert(&list, 1, 15); // 插入15在索引1的位置

    printf("当前元素数量: %d\n", list.size);
    for (int i = 0; i < list.size; i++)
    {
        printf("%d ", list.data[i]);
    }
    printf("\n");

    delete (&list, 1); // 删除索引1的元素

    printf("删除后元素数量: %d\n", list.size);
    for (int i = 0; i < list.size; i++)
    {
        printf("%d ", list.data[i]);
    }
    printf("\n");

    printf("顺序表是否为空: %d\n", isEmpty(&list));

    return 0;
}
