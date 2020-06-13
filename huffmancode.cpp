#include<iostream>
using namespace std;
float sum;
float f_sum;
struct NODE
{
        char data;
        int freq;
        NODE* left;
        NODE* right;
        //int len;
};
int front=0;
int rear=5;
NODE* extract_min(NODE** que)
{
        NODE* temp=que[front];
        front++;
        return temp;
}
void insert(NODE** que,NODE* z)
{
        int i;
        for(i=rear;z->freq < que[i]->freq && i>=front;i--)
        que[i+1]=que[i];
        que[i+1]=z;
        rear++;
}
NODE* huffman(char a[100],int f[100],int n)
{
        NODE** que=new NODE*[100];
        for(int i=0;i<n;i++)
        {
                que[i]=new NODE[1];
                que[i]->data=a[i];
                que[i]->freq=f[i];
                que[i]->left=que[i]->right=NULL;
        }
        for(int i=0;i<n-1;i++)
        {
                NODE* z=new NODE;
                z->left=extract_min(que);
                z->right=extract_min(que);
                z->freq=z->left->freq+z->right->freq;
                z->data='*';
                insert(que,z);
        }
        return extract_min(que);
}
void printArr(int arr[], int n)
{
        int i;
        for (i = 0; i < n;i++)
                cout <<arr[i];
        cout << "\n";
}

int isLeaf(NODE* root)
{
        return !(root->left) && !(root->right);
}
void print(NODE* root,int a[100],int t)
{
        //int sum;
        if(root->left)
        {
                a[t]=0;
                print(root->left,a,t+1);
        }
        if(root->right)
        {
                a[t]=1;
                print(root->right,a,t+1);
        }
        if(isLeaf(root))
        {
                cout<<root->data<<"|";
                printArr(a,t);
                //root->len=t;
                sum+=t*(root->freq);
        }
}

int main()
{
        int top=0;
        int a[10];
        int n;
        char arr[6]={'f','e','c','b','d','a'};
        int f[6]={5,9,12,13,16,45};
        for(int i=0;i<6;i++)
           f_sum=f_sum+3*f[i];
        NODE* root;
        root=huffman(arr,f,6);
        print(root,a,top);
        cout<<"\n fixed sum:"<<f_sum;
        cout<<"\n variable sum:"<<sum;
        cout<<"\nRoot frequency:"<<root->freq;
        float cr= f_sum/sum;
        cout<<"\ncompression ratio:"<<cr;
        float sr= (1-cr)*100;
        cout<<"\nspace ratio:"<<sr;
        cout<<endl;
}

	

