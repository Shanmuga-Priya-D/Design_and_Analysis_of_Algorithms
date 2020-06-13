#include<iostream>
using namespace std;
int wt,n;
struct product
{
float we;
float pr;
int pid;
float r;//ratio
}p[10],temp;
void sort()
{
for(int i=0;i<n-1;i++)
{
 for(int j=0;j<n-i-1;j++)
   {
    if(p[j].r<p[j+1].r)
     {
      temp=p[j];
      p[j]=p[j+1];
      p[j+1]=temp;
     }
    }
 }
}


void kp()
{
int i=0;
int tot_pr;
while(wt!=0)
{
wt=wt-p[i].we;
tot_pr=tot_pr+p[i].pr;
i++;
}

cout<<endl<<"total profit is"<<tot_pr;
}
int main()
{
n=7;
wt=15;
int i;
//float w[]={1,3,5,4,1,3,2};
//float p[]={5,10,15,7,8,9,4};

for(i=0;i<n;i++)
{
cout<<"enter product "<<i+1<<" details"<<endl;
p[i].pid=i+1;
cout<<"enter weight  ";
cin>>p[i].we;
cout<<"enter profit  ";
cin>>p[i].pr;
}
for(i=0;i<n;i++)
{
cout<<"product "<<i+1<<" details"<<endl;
cout<<"id "<<p[i].pid;
cout<<"weight "<<p[i].we;  
cout<<"profit "<<p[i].pr<<endl;
}
float r[20];
for(int i=0;i<n;i++)
{
p[i].r=p[i].pr/p[i].we;
}
//kp(w,p);

for(int i=0;i<n;i++)
{
cout<<p[i].r<<endl;
}
sort();
cout<<"after sorting"<<endl;
for(i=0;i<n;i++)
{
cout<<"product "<<i+1<<" details"<<endl;
cout<<"id "<<p[i].pid;
cout<<"weight "<<p[i].we;  
cout<<"profit "<<p[i].pr<<endl;
}
cout<<"------------------------------";
kp();
return 0;
}

