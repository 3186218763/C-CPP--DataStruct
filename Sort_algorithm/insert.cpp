//插入排序:当原始序列已经基本有序时再将一个新的数据插入进来比较方便，也比较高效率。

#include <iostream>
using namespace std;

int count = 0;

void insert(int arr[], int len);
void sprintrr(int arr[], int len);
int main()
{

    int arr[] = {1, 6, 2, 4, 21, 12, 64, 12};
    insert(arr, 6);
    sprintrr(arr, 6);
    return 0;
}


void insert(int arr[], int len)
{
  int temp, i, j;
  for (i = 1; i <len; i++)
  {
    int temp = arr[i];
    for (j = i - 1; j >= 0 && temp < arr[j]; j--)
    {
        arr[j + 1] = arr[j];
        count++;
    }
    arr[j + 1] = temp;
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