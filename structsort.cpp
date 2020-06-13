#include<iostream>
#include<string.h>
using namespace std;
struct cric
{
char pname[20];
char tname[20];
int avg;
}player[10],temp;

int main()
{
for(int i=0;i<3;i++)
{
cout<<"enter player name:";
cin>>player[i].pname;
cout<<"enter team name:";
cin>>player[i].tname;
cout<<"enter average:";
cin>>player[i].avg;
cout<<endl;
}
int n=3;
for(int i=0;i<n-1;i++)
{
for(int j=0;j<n-i-1;j++)
{
if(strcmp(player[j].tname,player[j+1].tname)>0)
{
temp=player[j];
player[j]=player[j+1];
player[j+1]=temp;
}
}
}
for(int i=0;i<n;i++)
{
cout<<player[i].pname<<"\t"<<player[i].tname<<"\t"<<player[i].avg;
cout<<endl;
}

return 0;
}
