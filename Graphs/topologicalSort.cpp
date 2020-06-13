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
	int d,f;
};
gv* inc[100];
int cnt=0;
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
		temp->color='W';
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
	void dfsvisit(gv* t)
	{
		tim+=1;
		t->d=tim;
		t->color='G';
		ga* arc=t->firstarc;
		while(arc!=NULL)
		{
			if(arc->content->color=='W')
			{
				arc->content->pred=t;
				dfsvisit(arc->content);
			}
			arc=arc->nextarc;
		}
		t->color='B';
		tim+=1;
		t->f=tim;
		inc[cnt++]=t;
		
	}
	void dfs()
	{
		gv* t=first;
		while(t!=NULL)
		{
			if(t->color=='W')
			{
				dfsvisit(t);
			}
				t=t->nextvertex;
		}
		for(int i=0;i<cnt;i++)
		{
			for(int j=0;j<cnt-1-i;j++)
			{
				if(inc[j]->f<inc[j+1]->f)
				{
					gv* temp=inc[j];
					inc[j]=inc[j+1];
					inc[j+1]=temp;
				}
			}
		}
		cout<<"\n LIST OF VERTICES:\n";
		for(int i=0;i<cnt;i++)
		{
			cout<<inc[i]->data<<":"<<inc[i]->d<<"/"<<inc[i]->f<<"\n";
		}
	
	}	
};
int main()
{
	graph g;
	int ch;
 	char x,y;
	do
	{
		cout<<"1-Insert Vertex, 2-Insert Edge, 3-Depth first search,0-Exit\n";
		cout<<"Enter choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
			cout<<"Enter character to insert: ";
			cin>>x;
			g.insertvertex(x);
			break;
			case 2:
			cout<<"Enter characters to add edge: ";
			cin>>x>>y;
			if(g.insertarc(x,y))
			cout<<"Edge inserted between "<<x<<" and "<<y<<"."<<endl;
			else
			cout<<"Either one or both vertices not present in graph.\n";
			break;
			case 3:
			g.dfs();
			break;
			case 0:
			break;
			default:
			cout<<"Invalid choice!";
		}
	}while(ch);
}

