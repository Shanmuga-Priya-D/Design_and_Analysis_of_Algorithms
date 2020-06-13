#include<iostream>
using namespace std;
int tim=0;
struct ga;
struct gv //Graph Vertex
{
	char data;
	ga *firstarc;
	gv *nextvertex;
	char color;
	gv *pred;
	int di;
};
gv* inc[100];
int cnt=0;
char s;
struct node //Node for queue
{
	gv *vertex;
	node *link;
};
class queue
{
	private:
	node *front,*rear;
	public:	
	int count;
	queue():count(0){front=rear=NULL;}
	void enqueue(gv *v)
	{
		node *temp=new node;
		temp->vertex=v;
		temp->link=NULL;
		if(front==NULL)
		front=rear=temp;
		else
		{
			rear->link=temp;
			rear=temp;
		}
		count++;
	}
	gv* dequeue()
	{
		node *temp=front;
		gv *v=temp->vertex;
		front=front->link;
		delete temp;
		count--;
		return v;
	}
};

struct ga //Graph Arc
{
	gv *content;
	ga *nextarc;
};
class graph
{
	private:
	gv *first;
	int count;
	public:
	graph():count(0){first=NULL;}
	void insertvertex(char x)
	{
		gv *temp=new gv;
		temp->data=x;
		temp->firstarc=NULL;
		temp->nextvertex=NULL;
                temp->pred=NULL;
                if(x==s)
                {
                temp->color='g';
		temp->di=0;
                }
                else 
                {
                temp->color='w';
		temp->di=9999; 
                }
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
	bool insertarc(char x,char y)
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
void bfs()
{
gv *t,*u;
t=first;
queue q;
while(t!=NULL&&t->data!=s)
t=t->nextvertex;
cout<<endl<<"source vertex is"<<t->data<<endl;
q.enqueue(t);
while(q.count!=0)
{
u=q.dequeue();
cout<<endl<<"dequed data"<<u->data<<endl;
ga* arc=t->firstarc;
while(arc!=NULL)
{
if(arc->content->color=='w')
{
arc->content->color='g';
arc->content->di=u->di+1;
arc->content->pred=t;
cout<<endl<<" to be enqueued data"<<arc->content->data<<endl;
q.enqueue(arc->content);
cout<<endl<<"enqueued data"<<arc->content->data<<endl;
}
arc=arc->nextarc;
}
u->color='b';
cout<<"bfs";
cout<<endl<<u->data<<endl;
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
};

int main()
{
	graph g;
        
	int ch;
 	char x,y;int n,ed;
cout<<"enter source vertex :";
cin>>s;
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
cout<<"Enter characters to add edge: ";
cin>>x>>y;
if(g.insertarc(x,y))
cout<<"Edge inserted between "<<x<<" and "<<y<<"."<<endl;
else
cout<<"Either one or both vertices not present in graph.\n";
}
g.display();
g.bfs();


return 0;
}


