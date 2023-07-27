//冒泡排序：基于交换的排序，每一轮将序列的最大值放在序列的尾部（或者是把最小值放首部）*/
#include <iostream>
using namespace std;

int count = 0;

void buffer(int arr[], int len);
void sprintrr(int arr[], int len);
int main()
{

    int arr[] = {1, 6, 2, 4, 21, 12, 64, 12};
    buffer(arr, 6);
    sprintrr(arr, 6);
    return 0;
}

//优化后面的冒泡排序
void buffer(int arr[], int len)
{
    int flag = 1;
    while (len-- && flag)
    {
        flag = 0;
        for (int i = 0; i < len; i++)
        {
            if (arr[i + 1] < arr[i])
            {
                int temp = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = temp;
                flag = 1;
                count++;
            }
            
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