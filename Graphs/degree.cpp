#include<iostream>
using namespace std;
int m[20][20];
int v,e;
int u,vi,w;


int deg(int q)
{
int d=0;
for(int i=1;i<=v;i++)
{
if(m[q][i]==1)
 d++;
}
return d;
}
   
int main()
{
cout<<"enter number of vertices: ";
cin>>v;
cout<<"enter number of edges: ";
cin>>e;
int i,j;
for(i=1;i<=v;i++)
{
 for(j=1;j<=v;j++)
  {
   m[i][j]=9999;
  }
}
for(i=1;i<=v;i++)
  m[i][i]=0;
for(int k=1;k<=e;k++)
{
cout<<"enter two vertices to add edges "<<endl;
cin>>u>>vi;
m[u][vi]=1;
}
int d=0;
cout<<endl<<"degrees are"<<endl;
for(i=1;i<=v;i++)
{
d=deg(i);
cout<<endl<<"degree of  "<<i<<" is "<<d<<endl;
}

return 0;
}
