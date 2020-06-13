#include<iostream>
using namespace std;
struct node
{
int vertex;
node* next;

char color;
int pie;

int st;
int ft;

};
int tim=0;
node* g[20];
int visited[20];

int n;
/*struct nod
{
int data;
nod* link;
};
nod* root;
void insert(int v)
{
nod* nn=new nod;
nn->data=v;
nn->link=root;
root=nn;
}
void display()
	   {
		     if(root==NULL)
		       cout<<"list is empty.";
		     else
		     {
		       cout<<"The elements in the list are:"<<endl;
		       nod *t=root;
		       while(t!=NULL)
		       {
		   	  cout<<t->data<<" ";   
			  t=t->link;
		       }  
		     }
		     cout<<endl;
	   }*/
void dfs_visit(int u)
{
tim=tim+1;
g[u]->st=tim;
g[u]->color='g';
while(g[u]!=NULL)
{
 if(g[u]->next->color=='w')
  {
  g[u]->next->pie=u;
  dfs_visit(g[u]->next->vertex);
  }
}
cout<<endl<<g[u]->vertex<<endl;
g[u]->color='b';
tim=tim+1;
g[u]->ft=tim;
//insert(g[u]->vertex);
}

void dfs()
{
int i;
node* p=NULL;
for(i=0;i<n;i++)
{
g[i]->color='w';
g[i]->pie=0;
}
for(i=0;i<n;i++)
{
  if(g[i]->color=='w')
   {
    p=g[i];
    dfs_visit(p->vertex);
   }
}
}

node* createNode(int v)
{
    node* newNode = new node;
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}
void addEdge(int src, int dest)
{
    // Add edge from src to dest
     node* newNode = createNode(dest);
    newNode->next = g[src];
    g[src] = newNode;
 
    
}
void read_graph()
{
int i,vi,vj;
char ch;
cout<<"enter number of vertices";
cin>>n;

for(int i=0;i<n;i++)
{
g[i]=new node;
}
for(int i=0;i<n;i++)
{
g[i]->vertex=0;
g[i]->next=NULL;
g[i]->color='\0';
g[i]->pie=0;
g[i]->st=0;
g[i]->ft=0;
}
do
{

cout<<"enter the vertices for edge";
cin>>vi>>vj;
addEdge(vi,vj);
  cout<<"Do you want to add edges?(y/n)";
   cin>>ch;
}while(ch=='y');

}


int main()
{
int i;
read_graph();
dfs();
//display();
return 0;
}
