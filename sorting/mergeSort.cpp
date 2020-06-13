#include<iostream>
#include<fstream>
#include<iomanip>
#include<time.h>
#include<stdlib.h>
using namespace std;
long int count=0;
void merge(int *a,int p,int q,int r)
{

int n1=q-p+1;
int n2=r-q;
int L[n1+1];
int R[n2+1];
int i,j,k;
for(i=1;i<=n1;i++)
   L[i]=a[p+i-1];
for(j=1;j<=n2;j++) 
   R[j]=a[q+j];
L[n1+1]=99999;
R[n2+1]=99999;
i=1;j=1;
for(k=p;k<=r;k++)
{
count++;
if(L[i]<=R[j])
{
a[k]=L[i];
i++;
}
else
{
a[k]=R[j];
j++;
}
}
}

void mergesort(int *a,int p,int r)
{
if(p<r)
{
int q;
q=(p+r)/2;
mergesort(a,p,q);
mergesort(a,q+1,r);
merge(a,p,q,r);
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

mergesort(a,0,n-1);

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
