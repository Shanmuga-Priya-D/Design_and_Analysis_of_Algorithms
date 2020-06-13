#include<iostream>
#include<fstream>
#include<iomanip>
#include<time.h>
#include<stdlib.h>
using namespace std;
long int count=0;
int getmax(int *a,int n)
{
int mx=a[0];
for(int i=1;i<n;i++)
{
if(a[i]>mx)
{
mx=a[i];
}
}
return mx;
}
void countsort(int *a,int n,int pos)
{
int c[10]={0};
int i;
int b[n];
for(i=0;i<n;i++)
{
c[(a[i]/pos)%10]++;
count++;
}
for(i=1;i<10;i++)
c[i]=c[i]+c[i-1];
for(i=n-1;i>=0;i--)
{
b[--c[(a[i]/pos)%10]]=a[i];
count++;
}
for(i=0;i<n;i++)
a[i]=b[i];
}

void radix(int *a,int n)
{
int mx=getmax(a,n);
for(int pos=1;mx/pos>1;pos=pos*10)
  countsort(a,n,pos);
}
int main()
{
ofstream outf;
ifstream inf;
int *a;
int i,n;
cout<<"enter n";
cin>>n;
a=new int[n];

outf.open("in.txt");
for(i=0;i<n;i++)
{
outf<<"\t"<<rand()%n;
}
outf.close();

count=0;
inf.open("in.txt");
for(i=0;i<n;i++)
{
inf>>a[i];
}
inf.close();

clock_t st,end;
double etime;

st=clock();

radix(a,n);

end=clock();

outf.open("out.txt");
for(i=0;i<n;i++)
{
outf<<"\t"<<a[i];
}
outf.close();

cout<<"total active operations"<<count<<endl;
cout<<"total time taken"<<etime<<endl;
}
