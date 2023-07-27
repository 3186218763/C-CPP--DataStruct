//堆排序:堆积是一个近似完全二叉树的结构,利用这个结构来排序

#include <iostream>
using namespace std;

int count = 0;

void swap(int *a, int *b);
void heapify(int arr[], int len, int i);
void heap_sort(int arr[], int len);
void sprintrr(int arr[], int len);

int main()
{
    int arr[] = {1, 6, 2, 4, 21, 12, 64, 12};
    heap_sort(arr, 8);
    sprintrr(arr, 8);

    return 0;
}

void swap(int *a, int *b) 
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

/**
 * @param arr 存储堆的数组
 * @param len 数组的长度
 * @param i 维护节点的下标
*/
void heapify(int arr[], int len, int i)
{
    int father = i;
    int l_son = i * 2 + 1;
    int r_son = i * 2 + 2;

    if (l_son < len && arr[father] < arr[l_son])
        father = l_son;
    if (r_son < len && arr[father] < arr[r_son])
        father = r_son;
    if (father != i)
    {
        swap(&arr[father], &arr[i]);
        count++;
        heapify(arr, len, father);
    }
}

// 堆排序入口
void heap_sort(int arr[], int len)
{
    int i;
    // 建堆
    for (i = len / 2 - 1; i >= 0; i--)
        heapify(arr, len, i);

    // 排序
    for (i = len - 1; i > 0; i--)
    {
        swap(&arr[i], &arr[0]);
        heapify(arr, i, 0);
    }
}

void sprintrr(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"count= "<<count;
}