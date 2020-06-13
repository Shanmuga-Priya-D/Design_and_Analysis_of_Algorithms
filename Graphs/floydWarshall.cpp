#include<iostream>
using namespace std;
int m[20][20];
int v,e;
int u,vi,w;
void print()
{
for(int i=1;i<=v;i++)
{
cout<<"\n minimum cost with respect to node:"<<i<<endl;
for(int j=1;j<=v;j++)
 {
 cout<<m[i][j]<<"\t";
 }
}
}
void fw()
{
for(int k=1;k<=v;k++)
{
 for(int i=1;i<=v;i++)
  {
   for(int j=1;j<=v;j++)
    {
     if(m[i][k]+m[k][j]<m[i][j])
     { 
      m[i][j]=m[i][k]+m[k][j];
     }  
    }
  }
}
print();
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
cout<<"enter u,v,w"<<endl;
cin>>u>>vi>>w;
m[u][vi]=w;
}
fw();
return 0;
}
