#include<iostream>
using namespace std;

struct ga;
struct gv //Graph Vertex
{
           int  data;
	ga *firstarc;
	gv *nextvertex;
	gv *pred;
	int visited;
};

struct ga //Graph Arc
{
        
	gv *content;
	ga *nextarc;
};
int cnt=0;
class graph
{
	private:
	gv *first;
	int count;
	public:
	graph():count(0){first=NULL;}
	void insertvertex(int x)
	{
		gv *temp=new gv;
		temp->data=x;
		temp->firstarc=NULL;
		temp->nextvertex=NULL;
		temp->visited=-1;
		temp->pred=NULL;
		//Insertion
		if(first==NULL)
		first=temp;
		else
		{
			gv *t=first;
			while(t->nextvertex!=NULL)
			t=t->nextvertex;
			t->nextvertex=temp;
		}
		count++;
		cout<<"Vertex inserted!!"<<endl;
	}
	bool insertarc(int x,int y)
	{
		gv *xtemp=NULL,*ytemp=NULL;
		gv *xt=first,*yt=first;
		while(xt!=NULL&&xt->data!=x)
		xt=xt->nextvertex;		
		while(yt!=NULL&&yt->data!=y)
		yt=yt->nextvertex;	
		if(xt==NULL||yt==NULL) //Vertex not found
		return false;
		else
		{
			xtemp=xt;
			ytemp=yt;
		}
		//Insertion at x arc
		ga *xarc=new ga;
		xarc->content=ytemp;
		xarc->nextarc=NULL;
               
		if(xtemp->firstarc==NULL)
		xtemp->firstarc=xarc;
		else
		{
			ga *xa=xtemp->firstarc;
			while(xa->nextarc!=NULL)
			xa=xa->nextarc;
			xa->nextarc=xarc;
		}
                
	}
void dfs(gv* c)
{
c->visited=1;

ga* arc=c->firstarc;
while(arc!=NULL)
{
if(arc->content->visited==-1)
     dfs(arc->content);
arc=arc->nextarc;
}



}
int  mothervertex()
{
gv* tmp=NULL;
gv* t=first;


while(t!=NULL)
{
if(t->visited==-1)
{
dfs(t);
tmp=t;
}
t=t->nextvertex;
}




gv* c=first;
while(c!=NULL)
{
c->visited=-1;
c=c->nextvertex;
}
dfs(tmp);

gv* e=first;
while(e!=NULL)
{
if(e->visited==-1)
   return -1;
e=e->nextvertex;
}


return tmp->data;

}
};

int main()
{
	graph g;
        
	int ch;
 	int x,y;int n,ed;
int a;

        cout<<"enter number of vertces :";
        cin>>n;
 int i;
for(i=1;i<=n;i++)
{
cout<<"enter character to insert: ";
cin>>x;
g.insertvertex(x);
}
cout<<"enter number of edges :";
cin>>ed;
for(i=1;i<=ed;i++)
{
cout<<"Enter characters to add edge : ";
cin>>x>>y;
if(g.insertarc(x,y))
cout<<"Edge inserted between "<<x<<" and "<<y<<"."<<endl;
else
cout<<"Either one or both vertices not present in graph.\n";
}
cout<<endl<<"mother vertex is "<<g.mothervertex();

return 0;
}

