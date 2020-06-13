#include<iostream>
using namespace std;

void fn(int a[],int n,int sum)
{
int i,j;
int d[n+1][sum+1];
for(i=0;i<=n;i++)
d[i][0]=1;
for(i=1;i<=sum;i++)
d[0][i]=0;
for(i=1;i<=n;i++)
{
for(j=1;j<=sum;j++)
{
if(j<a[i-1])
   d[i][j]=d[i-1][j];
else
   d[i][j]=d[i-1][j]||d[i-1][j-a[i-1]];
}
}
if(d[n][sum]==0)
cout<<endl<<"subset doesnot exists"<<endl;
else
cout<<endl<<"subset exists"<<endl;
}
int main()
{
int n,sum;
cout<<"enter nr of array elements";
cin>>n;
int a[n];
cout<<"enter array elements";
for(int i=0;i<n;i++)
cin>>a[i];
cout<<"enter sum";
cin>>sum;
fn(a,n,sum);
return 0;
}
