#include<iostream>
#include<algorithm>
using namespace std;
struct activity
{
int st;
int ft;
}a[10];
/*void insertion(activity a[],int n)
{
int key,j;
for(int i=1;i<n;i++)
{
key=a[i].ft;
j=i-1;
while(j>=0&&a[j].ft>key)
{
a[j+1].ft=a[j].ft;
j=j-1;
}
a[j+1].ft=key;
}
}*/
bool comp(activity a1,activity a2)
{
return (a1.ft<a2.ft);
}

void print_activity(activity a[],int n)
{
sort(a,a+n,comp);
//insertion(a,n);
cout<<"the following activities are selected\n";
int i=0;
cout<<"("<<a[i].st<<","<<a[i].ft<<")\n";
for(int j=1;j<n;j++)
{
if(a[j].st>=a[i].ft)
{
cout<<"("<<a[j].st<<","<<a[j].ft<<")\n";
i=j;
}
}
}
int main()
{
int n;
cout<<"enter number of activities";
cin>>n;

for(int i=0;i<n;i++)
{
cout<<"enter start and end time for activity"<<i+1<<endl;
cin>>a[i].st>>a[i].ft;
}

print_activity(a,n);
return 0;

}
