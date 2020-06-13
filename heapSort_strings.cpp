#include<iostream>
#include<fstream>
#include<time.h>
#include<stdlib.h>
#include<iomanip>
#include<string.h>
using namespace std;

long int count=0;

//Heap Sort: 1. MaxHeapify
void MaxHeapify(char a[][10], int n, int i)
{
   int left, right;
   left = 2*i + 1;
   right = 2*i + 2;
   int max=i;
   if(left<=n-1 && strcmp(a[left],a[max])>0)
   {
    max = left;
   }
   if(right<=n-1 && strcmp(a[right],a[max])>0)
   {
    max = right;
   }
   if(max!=i)
    {
    count++;
    swap(a[i],a[max]);
    MaxHeapify(a,n,max);
    }
 count++;
}
//Heap Sort: 2. BuildMaxHeap
void BuildMaxHeap(char a[][10],int n)
{
   for(int i=n/2;i>=0;i--)
    {
     MaxHeapify(a,n,i);
    }
}
//Heap Sort: 3. Heap Sort
void HeapSort(char a[][10],int n)
{
   BuildMaxHeap(a,n);
   for(int i=n-1;i>=1;i--)
    {
     count++;
     swap(a[0],a[i]);
     n--;
     MaxHeapify(a,n,0);
    }
}
int main()
{
cout<<showpoint<<setprecision(12);
ofstream outf;
ifstream inf;
int n;
char a[5][10];
cout<<"\nEnter n:";
cin>>n;
cout<<"enter array elements";
for(int i=0;i<n;i++)
cin>>a[i];

clock_t st,end;
double etime;
st=clock();

HeapSort(a,n);

end=clock();
etime=(double)(end-st)/CLOCKS_PER_SEC;

cout<<"output is";
for(int i=0;i<n;i++)
{
cout<<a[i]<<endl;
}
cout<<"\n\nHeap Sort:";
cout<<"\nTotal Active Operations: "<<count;
cout<<"\n"<<"time taken for execution"<<showpoint<<setprecision(10)<<etime;


return 0;
}
