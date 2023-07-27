//冒泡排序的优化版本。核心思想：使用轴，每一轮左右递归后，把轴放到中间，使得轴的左边都比轴小，轴的右边都比轴大。
#include <iostream>
using namespace std;

int count = 0;

void quick_1(int arr[], int left, int right);
void quick_2(int arr[], int left, int right);
void sprintrr(int arr[], int len);
int main()
{

    int arr[] = {1, 6, 2, 4, 21, 12, 64, 12};
    quick_1(arr, 0, 5);
    sprintrr(arr, 6);
    return 0;
}

//快速排序 双向版本
void quick_2(int arr[], int left, int right)
{
    if (left >= right) return;
    int i = left;
    int j = right;
    int pivot = arr[i];
    while(i < j)
    {
        while (i < j && arr[j] >= pivot) 
            j--;
        arr[i] = arr[j];
        while (i < j && arr[i] <= pivot) 
            i++;
        arr[j] = arr[i];

        count++;
    }
    
    arr[i] = pivot;
    quick_2(arr, left, i - 1);
    quick_2(arr, i + 1, right);
    
}

//快速排序 单向版本
void quick_1(int arr[], int left, int right)
{
    if (left >= right) return;
    int pivot = arr[left];
    int i = left + 1;
    int j = left + 1;
    while (j <= right)
    {
        if (arr[j] < pivot)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;

            count++;
        }
        j++;
    }
    int temp = arr[left];
    arr[left] = arr[i - 1];
    arr[i - 1] = temp;

    quick_1(arr, left, i - 2);
    quick_1(arr, i, right);
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