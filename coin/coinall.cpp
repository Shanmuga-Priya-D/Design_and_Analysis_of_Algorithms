#include<iostream>
using namespace std;
void fn(int n,int amt,int a[])
{
int d[n+1][amt+1];
int i,j;
for(i=0;i<n;i++)
d[i][0]=1;
for(i=0;i<=amt;i++)
{
if(i%a[0]==0)
   d[0][i]=1;
else
   d[0][i]=0;
}

for(i=1;i<n;i++)
{
for(j=1;j<=amt;j++)
{
if(a[i]>j)
   d[i][j]=d[i-1][j];
else
   d[i][j]=d[i-1][j]+d[i][j-a[i]];
}
}

cout<<endl<<"all possible solution is  "<<d[n-1][amt]<<endl;
for(i=0;i<n;i++)
{
for(j=0;j<=amt;j++)
{
cout<<d[i][j];
}
cout<<endl;
}
}
int main()
{
int n,amt;
cout<<"enter the nr of coins";
cin>>n;
cout<<"enter amount";
cin>>amt;
int a[n];
cout<<"enter coin denominations";
for(int i=0;i<n;i++)
cin>>a[i];
fn(n,amt,a);
return 0;
}

