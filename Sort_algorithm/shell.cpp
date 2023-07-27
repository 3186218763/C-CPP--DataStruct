//希尔排序:优化版的插入排序。优化的地方就是步长增大了。原来的插入排序是的步长是1，而希尔排序的步长可以很大，然后逐渐减小直到1形成插入排序。
//经典的shell 1, 4, 13, ... ,3*n +1
#include <iostream>
using namespace std;

int count = 0;

void shell(int arr[], int len);
void sprintrr(int arr[], int len);
int main()
{

    int arr[] = {1, 6, 2, 4, 21, 12, 64, 12};
    shell(arr, 6);
    sprintrr(arr, 6);
    return 0;
}


void shell(int arr[], int len)
{

  int temp, i, j;
  int gap = 1;
  int MAX = len / 3;
  while(gap < MAX) gap = 3 * gap + 1;

  //上面求出最合适的步长
  
  while (gap >= 1)
  {
    for (i = gap; i <len; i++)
    {
      temp = arr[i];
      for (j = i - gap; j >= 0 && arr[j] > temp; j -= gap) //每次减一个步长
      {
          arr[j + gap] = arr[j];
          count++;
      }
      arr[j + gap] = temp;
    } 

    gap /= 3 ;
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