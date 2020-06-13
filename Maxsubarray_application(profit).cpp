//Maximum Sub-Array - Comparison of brute-force method &
//divide & conquer methods
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<time.h>
#include<iomanip>
using namespace std;

long int count=0;

struct SubArray
{
int low, high;
double sum;
    SubArray()
    {}
   SubArray(int l, int h, double s)
    {
    low = l;
    high = h;
    sum = s;
    }
};

SubArray MaxCrossingSubArray(double a[],int low, int mid,int high)
{
double leftSum, rightSum, Sum;
int maxLeft, maxRight;
leftSum = -99999;
Sum = 0;
  for(int i=mid;i>=low;i--)
  {
  count++;
  Sum = Sum + a[i];
    if(Sum > leftSum)
     {
     leftSum = Sum;
     maxLeft = i;
     }
   }

rightSum = -99999;
Sum = 0;
   for(int i=mid+1;i<=high;i++)
   {
   count++;
   Sum = Sum + a[i];
     if(Sum > rightSum)
      {
       rightSum = Sum;
       maxRight = i;
      }
    }

return SubArray(maxLeft,maxRight,leftSum+rightSum);
}

SubArray MaximumSubArrayDC(double a[], int low, int high)
{
SubArray leftSubArray, rightSubArray, crossSubArray;
if(low == high)
{
return SubArray(low,high,a[low]);
}
int mid;
count++;
mid = (low+high)/2;
leftSubArray = MaximumSubArrayDC(a, low, mid);
rightSubArray = MaximumSubArrayDC(a, mid+1, high);
crossSubArray = MaxCrossingSubArray(a,low,mid,high);

//Finding max between the three

if(leftSubArray.sum>=rightSubArray.sum)
{
if(leftSubArray.sum>=crossSubArray.sum)
{
return leftSubArray;
}
else
{
return crossSubArray;
}
}
else
{
if(rightSubArray.sum>=crossSubArray.sum)
{
return rightSubArray;
}
else
{
return crossSubArray;
}
}

}

SubArray MaximumSubArrayBF(double a[], int low, int high)
{
double maxSum,Sum;
int left,right;
maxSum = a[low];
left = 0;
right = 0;
for(int i=low;i<=high;i++)
{
Sum = 0;
for(int j=i;j<=high;j++)
{
count++;
Sum = Sum + a[j];
if(Sum>maxSum)
{
maxSum = Sum;
left = i;
right = j;
}
}
}
return SubArray(left,right,maxSum);
}
int main()
{
cout<<showpoint<<setprecision(12);
int n;
double a[n-1];
double b[n];
cout<<"\nEnter n: ";
cin>>n;
cout<<"enter array elements";
for(int i=0;i<n;i++)
{
cin>>b[i];
}
for(int i=0;i<n;i++)
{
cout<<b[i]<<"index is"<<i<<endl;
}

for(int i=0;i+1<n;i++)
  a[i]=b[i+1]-b[i];
/*
n=3
a[0]=b[1]-b[0]
a[1]=b[2]-b[1]

*/
for(int i=0;i<n-1;i++)
{
cout<<endl<<a[i];
}
n=n-1;
count = 0;
SubArray max;
max = MaximumSubArrayBF(a,0,n-1);
cout<<"\n\nBrute-Force Method: ";
cout<<"\nMaximum Sub Array: purchasing item on day"<<max.low<<"for a price"<<b[max.low]<<"and selling it on day"<<max.high<<"for a price"<<b[max.high+1]<<"profit gained  is"<<max.sum;

cout<<"\nTotal Active Operations: "<<count;

//Divide-and-Conquer Approach
count = 0;
max = MaximumSubArrayDC(a,0,n-1);
cout<<"\n\nDivide-and-Conquer Approach: ";
cout<<"\nMaximum Sub Array: ("<<max.low<<","<<max.high<<", "<<max.sum<<")";

cout<<"\nTotal Active Operations: "<<count;

}
