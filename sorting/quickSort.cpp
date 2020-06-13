#include<iostream>
#include<fstream>
#include<iomanip>
#include<time.h>
#include<stdlib.h>
using namespace std;
long int count=0;


int partition(int *a,int p,int r)
{
int x=a[r];
int i=p-1;
int j;
for(j=p;j<=r-1;j++)
{
if(a[j]<=x)
{
i++;
swap(a[i],a[j]);
}
count++;
}
count++;
swap(a[i+1],a[j]);
return i+1;
}


void quicksort(int *a,int p,int r)
{
if(p<r)
{
int q;
q=partition(a,p,r);
quicksort(a,p,q-1);
quicksort(a,q+1,r);
}
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

quicksort(a,0,n-1);

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
