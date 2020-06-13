#include<iostream>
#include<math.h>
#include<fstream>
#include<time.h>
#include<cstdlib>
using namespace std;
long long count;
struct NODE
{
float data;
NODE* next;
};
NODE* append(NODE* first, float x)
{
NODE* nn = new NODE;
nn->data = x;
nn->next = NULL;
if(first == NULL)
return nn;
NODE* temp = first;
while(temp->next != NULL)
temp = temp->next;
temp->next = nn;
return first;
}
NODE* insertion_sort(NODE* first)
{
int cnt = 0;
NODE* temp = first;
while(temp != NULL)
{
cnt++;
temp = temp->next;
}
if(cnt <= 1)
return first;
float *a = new float[cnt];
int k = 0;temp = first;
while(temp != NULL)
{
a[k++] = temp->data;
temp = temp->next;
}
for(int i = 1;i < cnt;i++)
{
int j = i-1;
float temp = a[i];
while(j >= 0 && a[j] > temp)
{
count++;
a[j+1] = a[j];
j--;
}
count++;
a[j+1] = temp;
}
k = 0;
temp = first;
while(temp != NULL)
{
temp->data = a[k++];
temp = temp->next;
}
return first;
}
void print(NODE* first)
{
if(first == NULL)
return;
NODE* temp = first;
while(temp != NULL)
{
cout<<temp->data<<" ";
temp = temp->next;
}
}
void bucket_sort(float* a, int n)
{NODE* arr[n];
for(int i = 0;i < n;i++)
arr[i] = NULL;
for(int i = 0;i < n;i++)
{
int key = floor(n*a[i]);
arr[key] = append(arr[key], a[i]);
count++;
}
for(int i = 0;i < n;i++)
arr[i] = insertion_sort(arr[i]);
int j = 0;
for(int i = 0;i < n;i++)
{
//print(arr[i]);
NODE* temp = arr[i];
while(temp != NULL)
{
a[j++] = temp->data;
temp = temp->next;
}
}
}
int main()
{
int n;
ifstream inf;
ofstream outf;
cout<<"Enter n:"<<endl;
cin>>n;

double time_elapsed;
float a[n];
//Generating random nos. between 0 and 1 and writing them to the file
outf.open("input.txt");
for(int i=0;i < n;i++)
outf<<"\t"<<((float)rand()/RAND_MAX);
outf.close();//Sorting
inf.open("input.txt");
for(int i=0;i < n;i++)
inf>>a[i];
inf.close();

count = 0;
clock_t st,end;
double etime;
st=clock();

bucket_sort(a, n);

end=clock();
etime=(double)(end-st)/CLOCKS_PER_SEC;

cout<<"\nBUCKET SORT:"<<endl;
cout<<"No. of operations: "<<count<<endl;
cout<<"\n"<<"time taken for execution"<<showpoint<<setprecision(10)<<etime;
//Writing output to file
outf.open("output.txt");
for(int i=0;i < n;i++)
outf<<"\t"<<a[i];
outf.close();
//delete(a);
return 0;
}
