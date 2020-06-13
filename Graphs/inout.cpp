#include<iostream>
using namespace std;
struct ga;
struct gv //Graph Vertex
{
	char data;
	bool instack,processed;
	ga *firstarc;
	gv *nextvertex;
        int in;
        int out;
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
		temp->instack=temp->processed=false;
		temp->firstarc=NULL;
		temp->nextvertex=NULL;
                temp->in=0;
                temp->out=0;
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
int inout(ga* a)
{
int o=0;
while(a!=NULL)
{
o++;
a->content->in++;
a=a->nextarc;
}
return o;
}
void deg()
{
gv* t=first;
while(t!=NULL)
{
ga* arc=t->firstarc;
t->out=inout(arc);
t=t->nextvertex;
}

}
void display()
{
gv* t=first;
while(t!=NULL)
{
cout<<endl<<"for "<<t->data<<endl;
cout<<endl<<"indegree is "<<t->in<<endl;
cout<<endl<<"outdegree is "<<t->out<<endl;
t=t->nextvertex;
}
}
};

int main()
{
	graph g;
        
	int ch;
 	char x,y;int n,ed;

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
g.deg();
g.display();


return 0;
}

        





