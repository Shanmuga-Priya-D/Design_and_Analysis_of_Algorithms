#include<iostream>
#include<fstream>
#include<iomanip>
#include<time.h>
#include<stdlib.h>
using namespace std;
long int count=0;
void maxheapify(int *a,int n,int i)
{
int l,r,largest=i;
l=2*i+1;
r=2*i+2;
while(l<=n-1&&a[l]>a[largest])
   largest=l;
while(r<=n-1&&a[r]>a[largest])
   largest=r;
if(largest!=i)
{
count++;
swap(a[i],a[largest]);
maxheapify(a,n,largest);
}
count++;
}

void buildmaxheap(int *a,int n)
{
for(int i=n/2;i>=0;i--)
    maxheapify(a,n,i);
}
void heapsort(int *a,int n)
{
int i;
buildmaxheap(a,n);
for(i=n-1;i>=0;i--)
{
count++;
swap(a[0],a[i]);
n--;
maxheapify(a,n,0);
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

heapsort(a,n);

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
