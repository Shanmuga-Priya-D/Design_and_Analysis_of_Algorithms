#include<iostream>
using namespace std;
int m[20][20];
int v,e;
int u,vi,w;


struct node
{
int data;
int pred;
int d,f;
char color;
}ve[10],inc[20],temp;
int tim=0;
int cnt=0;
void dfs_visit(int s)
{

tim+=1;
ve[s].d=tim;
ve[s].color='G';
int i;
for(i=1;i<=v;i++)
{
if(m[s][i]==1)
{
if(ve[i].color=='w')
{
ve[i].pred=s;
dfs_visit(i);
}
}
}
ve[s].color='b';
tim+=1;
ve[s].f=tim;
inc[cnt].data=s;
inc[cnt].d=ve[s].d;
inc[cnt].f=ve[s].f;
cnt++;
	
}
void dfs()
{
int i;
for(i=1;i<=v;i++)
{
 if(ve[i].color=='w')
  {
   dfs_visit(i);
  }
}

            for(int i=0;i<cnt;i++)
		{
			for(int j=0;j<cnt-1-i;j++)
			{
				if(inc[j].f<inc[j+1].f)
				{
					temp=inc[j];
					inc[j]=inc[j+1];
					inc[j+1]=temp;
				}
			}
		}
		cout<<"\n LIST OF VERTICES:\n";
		for(int i=0;i<cnt;i++)
		{
			cout<<inc[i].data<<":"<<inc[i].d<<"/"<<inc[i].f<<"\n";
		}
	

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
//for(i=1;i<=v;i++)
  //ve[i]=NULL;
for(i=1;i<=v;i++)
{
ve[i].data=i;
ve[i].color='w';
ve[i].d=0;
ve[i].f=0;
ve[i].pred=0;
}

dfs();

return 0;
}
