#include<iostream>
using namespace std;
int coins[20],n,amt;
int a[100][100];
int min(int a , int b)
{
if(a<=b)
  return a;
else
  return b;
}
void fn()
{
int i,j;
for(i=1;i<=n;i++)
{
a[i][0]=0;
for(j=0;j<=amt;j++)
{
a[1][j]=j;
if(coins[i]>j)
   a[i][j]=a[i-1][j];
else
   a[i][j]=min(a[i-1][j],1+a[i][j-coins[i]]);
}
}
cout<<endl<<"the minimum nr of coins is"<<a[n][amt]<<endl;

i=n;j=amt;
while(j!=0)
{
if(a[i][j]!=a[i-1][j])
   {
   cout<<coins[i];
   j=j-coins[i];
   }
else
   i--;
}
}
int main()
{
cout<<"enter amount";
cin>>amt;
cout<<"enter nr of coins";
cin>>n;
cout<<"enter denominations";
for(int i=1;i<=n;i++)
cin>>coins[i];
fn();
return 0;
}
