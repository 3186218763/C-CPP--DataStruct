//计数排序:只适用于一定范围的整数
#include <iostream>
using namespace std;


void count_sort(int arr[], int len);
void sprintrr(int arr[], int len);
int main()
{

    int arr[] = {1, 6, 2, 4, 21, 12, 64, 12};
    count_sort(arr, 6);
    sprintrr(arr, 6);
    return 0;
}


void count_sort(int arr[], int len)
{
    int i = 0;
    int j = 0;
    int MAX = arr[i];
    for (i = 1; i < len; i++)
    {
        if (arr[i] > MAX)
        {
            MAX = arr[i];
        }
    }
    MAX += 1;
    int Sum[MAX] = {0};
    
    for (i = 0; i < len; i++)
    {
       Sum[arr[i]]++;
    }
    i = 0;
    j = 0;
    while (i < MAX)
    {
        if (Sum[i] > 0)
        {
            arr[j] = i;
            Sum[i]--;
            j++;
        }
        i++;
    }

}
void sprintrr(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout<<arr[i]<<" ";
    }
}