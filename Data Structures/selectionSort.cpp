#include <iostream>
using namespace std;
void selectionsort(int arr[],int n)
{
    int i,j,key,temp;
    for (i=0;i<n-1;i++)
    {
        key=i;
        for (j=i+1;j<n;j++)
        {
            if (arr[j]<arr[key])
            key=j;
        }
        if (i!=key)
        {
            temp=arr[key];
            arr[key]=arr[i];
            arr[i]=temp;
        }
    }
}
int main()
{
    int arr[40];
    int n;
    cout<<"Enter the no of elements in array"<<endl;
    cin>>n;
    cout<<"Enter the elements"<<endl;
    for(int j=0;j<n;j++)
        cin>>arr[j];   
    selectionsort(arr,n);
    cout<<"Sorted Array"<<endl;
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    return 0;
}