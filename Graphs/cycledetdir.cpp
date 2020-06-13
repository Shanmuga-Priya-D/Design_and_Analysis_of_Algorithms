#include<iostream>
using namespace std;
struct ga;
struct gv //Graph Vertex
{
	int data;
	bool instack,processed;
	ga *firstarc;
	gv *nextvertex;
};
struct ga //Graph Arc
{
	gv *content;
	ga *nextarc;
};
bool visited[20];
bool instack[20];


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
		temp->instack=temp->processed=false;
		temp->firstarc=NULL;
		temp->nextvertex=NULL;
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
void display()
{
gv* t=first;
while(t!=NULL)
{
ga* ae=t->firstarc;
cout<<endl<<t->data<<endl;
cout<<endl<<"the neighbours of  "<<t->data<<"  are  "<<endl;
while(ae!=NULL)
{
cout<<ae->content->data<<" ";
ae=ae->nextarc;
}
t=t->nextvertex;
}
}
bool cycleutil(int v)
{
if(visited[v]==false)
{
visited[v]=true;
instack[v]=true;


gv* t=first;
while(t!=NULL&&t->data!=v)
t=t->nextvertex;


                ga* arc=t->firstarc;
		while(arc!=NULL)
		{
                   if(visited[arc->content->data]==false&&cycleutil(arc->content->data))
                         return true;
                   else if(instack[arc->content->data]==true)
                            return true;
			arc=arc->nextarc;
		}


instack[v]=false;
}
return false;
}
bool cycle()
{

gv* t=first;
while(t!=NULL)
{
visited[t->data]=false;
instack[t->data]=false;
t=t->nextvertex;
}
t=first;
while(t!=NULL)
{
if(cycleutil(t->data))
  return true;
t=t->nextvertex;
}
return false;
}

};


int main()
{
	graph g;
        
	int ch;
 	int x,y;int n,ed;

        cout<<"enter number of vertices :";
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
cout<<"Enter characters to add edge: ";
cin>>x>>y;
if(g.insertarc(x,y))
cout<<"Edge inserted between "<<x<<" and "<<y<<"."<<endl;
else
cout<<"Either one or both vertices not present in graph.\n";
}
//g.display();
if(g.cycle())
    cout<<"graph contains cycle";
else
    cout<<"graph doesnt contain cycle";


return 0;
}


