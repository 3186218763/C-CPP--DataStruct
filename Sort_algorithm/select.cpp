//选择排序：基本思想就是冒泡排序。每一轮找序列中的最小值和第i元素（从第一个元素开始）


#include <iostream>
using namespace std;

int count = 0;

void select(int arr[], int len);
void sprintrr(int arr[], int len);
int main()
{

    int arr[] = {1, 6, 2, 4, 21, 12, 64, 12};
    select(arr, 6);
    sprintrr(arr, 6);
    return 0;
}


void select(int arr[], int len)
{
  for (int i = 0; i < len; i++)
  {
    int k = i;
    for (int j = i + 1; j < len; j++)
    {
        if (arr[j] < arr[k])
        {   
            k = j;
        }
        count++;
        int temp = arr[i];
        arr[i] = arr[k];
        arr[k] = temp;
    }
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