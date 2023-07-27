//归并排序：基于分而治之的思想。
#include <iostream>
using namespace std;

int count = 0;

//merge_simple 是简单的归并排序  拿两个已经有序的序列重新组合成个新的有序序列。
void merge_simple(int a[], int a_len, int b[], int b_len, int* temp);

//merge 是一般形式的归并排序
void merge(int arr[],int left,int mid,int right,int* temp);
void merge_sort(int arr[],int left,int right,int* temp);
void mergeSort(int arr[],int length);

void sprintrr(int arr[], int len);
int main()
{

    int a[5] = {1, 3, 5, 6, 7};
    int b[3] = {2, 8, 12};
    int temp[8];
    int arr[10] = {2, 1, 3, 22, 31, 6, 5, 33, 44, 26};
    //merge_simple(a, 5, b, 3, temp);
    mergeSort(arr, 10);
    //sprintrr(temp, 8);
    sprintrr(arr, 10);
    return 0;
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

void merge_simple(int a[], int a_len, int b[], int b_len, int* temp)
{
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < a_len && j < b_len)
    {
        if (a[i] < b[j])
        {
            temp[k] = a[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = b[j];
            k++;
            j++;
        }
        count++;
    }

    while (i < a_len)
    {
        temp[k] = a[i];
        k++;
        i++;

        count++;
    }
    while (j < b_len)
    {
       temp[k] = b[j];
       k++;
       j++;

       count++;
    }
    
}

void merge(int arr[],int left,int mid,int right,int* temp) {
    int i = left;
    int j = mid + 1;
    int k = left;
    while (i <= mid && j <= right) temp[k++] = arr[i] < arr[j] ? arr[i++] : arr[j++];
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];
    for (i = left;i <= right;i++)
        arr[i] = temp[i];

    count++;
}

void merge_sort(int arr[],int left,int right,int* temp) {
    if (left >= right) return;
    int mid = left + ((right - left) >> 1);
    count++;
    merge_sort(arr,left,mid,temp);
    merge_sort(arr,mid + 1,right,temp);
    merge(arr,left,mid,right,temp);
}

void mergeSort(int arr[],int length) {
    int* temp = new int[length];
    merge_sort(arr,0,length - 1,temp);
    delete(temp);
}
