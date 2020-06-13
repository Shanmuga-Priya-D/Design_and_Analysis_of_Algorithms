#include<iostream>
using namespace std;
int tim=0;
struct ga;
struct gv //Graph Vertex
{
           int  data;
	ga *firstarc;
	gv *nextvertex;
	gv *pred;
	int key;
};
gv* inc[100];
int cnt=0;
struct ga //Graph Arc
{
        int w;
	gv *content;
	ga *nextarc;
};
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
		temp->key=9999;
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
	bool insertarc(int x,int y,int z)
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
                xarc->w=z;
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
void prims(int x)
{
gv* xt=first;
gv* z=first;
bool inmst[20];
int parent[20];
while(z!=NULL)
{
inmst[z->data]=false;
cout<<endl<<inmst[z->data];
z=z->nextvertex;
}
cout<<endl;
queue q;
gv* t;
while(xt!=NULL&&xt->data!=x)
xt=xt->nextvertex;
cout<<endl<<"enqueued data"<<xt->data<<endl;
q.enqueue(xt);
xt->key=0;
while(q.count!=0)
{
t=q.dequeue();
cout<<endl<<"dequed data"<<t->data<<endl;
inmst[t->data]=true;

ga* s=t->firstarc;
while(s!=NULL)
{
if(inmst[s->content->data]==false&&s->content->key>s->w)
{
s->content->key=s->w;
q.enqueue(s->content);
cout<<endl<<"enqueued data"<<s->content->data;
parent[s->content->data]=t->data;
}
s=s->nextarc;
}
}
cout<<endl<<"prims"<<endl;
gv* i=first;
while(i->nextvertex!=NULL)
{ 
cout<<endl<<parent[i->nextvertex->data]<<"    "<<i->nextvertex->data<<endl;
i=i->nextvertex;
}
}	


void ds()
{
gv* xt=first;
gv* z=first;
bool inmst[20];
int parent[20];
while(z!=NULL)
{
inmst[z->data]=false;
z=z->nextvertex;
}
gv* i=first;
while(i!=NULL)
{
cout<<endl<<inmst[i->data]<<"     "<<i->data<<endl;
i=i->nextvertex;
}
}
};

int main()
{
	graph g;
        
	int ch;
 	int x,y,z;int n,ed;
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
cout<<"Enter characters to add edge and weight: ";
cin>>x>>y>>z;
if(g.insertarc(x,y,z))
cout<<"Edge inserted between "<<x<<" and "<<y<<"."<<endl;
else
cout<<"Either one or both vertices not present in graph.\n";
}
cout<<"enter source vertex"<<endl;
cin>>a;
g.prims(a);
//g.ds();
return 0;
}

