// 0/1 knapsack 

#include<iostream>
using namespace std;
int wt,n;

int max(int a,int b)
{
if(a>b)
  return a;
else
  return b;
}
void kp(int w[],int p[])
{
int m[20][20];
int i;
for(i=0;i<=wt;i++)
   m[0][i]=0;
for(i=0;i<=n;i++)
   m[i][0]=0;

for(i=1;i<=n;i++)
{
  for(int j=1;j<=wt;j++)
  {
   if(i==0|j==0)
      m[i][j]=0;
 else if(w[i-1]<=j)
     m[i][j]=max(m[i-1][j],m[i-1][j-w[i-1]]+p[i-1]);
  else
     m[i][j]=m[i-1][j];
   }
  
}
cout<<endl<<"the maximum weight is"<<m[n][wt];
}

int main()
{
n=4;
wt=8;
int w[]={3,4,5,6};
int p[]={2,3,4,1};

kp(w,p);

return 0;
}

