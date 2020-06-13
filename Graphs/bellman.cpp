#include<iostream>
using namespace std;

struct edge
{
int src;
int dest;
int wt;
};
void bell(int nv,edge e[],int s,int ne)
{
int u,v,w,i,j=0;
int dis[50];

for(i=0;i<nv;i++)
    dis[i]=9999;

dis[s]=0;

for(i=0;i<nv-1;i++)
{
 for(j=0;j<ne;j++)
 {
  u=e[j].src;
  v=e[j].dest;
  w=e[j].wt;
  
  if(dis[u]!=9999 && dis[u]+w<dis[v])
    {
     dis[v]=dis[u]+w;
    }
  }

}

for(j=0;j<ne;j++)
{
  u=e[j].src;
  v=e[j].dest;
  w=e[j].wt;
  
  if(dis[u]+w<dis[v])
  {
  cout<<"\n\n NEGATIVE CYCLE PRESENT ..!!\n";
  return;
  }
}


cout<<"\nvertex"<<"  distance from source";
for(i=0;i<nv;i++)
{
cout<<endl<<i<<"\t"<<dis[i];
}

}








int main()
{
int nv,ne,src_graph;
edge e[20];
cout<<"enter number of vertices: ";
cin>>nv;

cout<<"\nenter source vertex of the graph: ";
cin>>src_graph;

cout<<"\nenter number of edges: ";
cin>>ne;

int i;
for(i=0;i<ne;i++)
{
cout<<"\n for edge "<<i+1<<"=>";
cout<<"\n enter source vertex: ";
cin>>e[i].src;
cout<<"\n enter destination vertex: ";
cin>>e[i].dest;
cout<<"\n enter edge weight: ";
cin>>e[i].wt;
}
bell(nv,e,src_graph,ne);

return 0;
}



