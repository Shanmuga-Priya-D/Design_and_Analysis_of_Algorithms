#include<iostream>
using namespace std;

struct ga;
struct gv //Graph Vertex
{
           int  data;
	ga *firstarc;
	gv *nextvertex;
	gv *pred;
	int flag;
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
		temp->flag=-1;
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
                //Insertion at y arc
		ga *yarc=new ga;
		yarc->content=xtemp;
		yarc->nextarc=NULL;
		if(ytemp->firstarc==NULL)
		ytemp->firstarc=yarc;
		else
		{
			ga *ya=ytemp->firstarc;
			while(ya->nextarc!=NULL)
			ya=ya->nextarc;
			ya->nextarc=yarc;
		}
	}
void dfs(gv* c)
{
c->flag=1;
cout<<c->data;

ga* arc=c->firstarc;
while(arc!=NULL)
{
if(arc->content->flag==-1)
     dfs(arc->content);
arc=arc->nextarc;
}



}
void connect()
{
gv* t=first;
while(t!=NULL)
{
if(t->flag==-1)
{
dfs(t);
cnt++;
cout<<endl;
}
t=t->nextvertex;
}
cout<<endl<<"no of connected components is  "<<cnt;
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
g.connect();

return 0;
}

