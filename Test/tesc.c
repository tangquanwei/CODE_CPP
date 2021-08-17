#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct BinTree *Tree;
struct BinTree{
    int data;
    Tree left;
    Tree right;
};
int MaxHeight(int N);
Tree CBST(int *a,int Left,int right);
int LeftNodeNum(int N);
int compare(const void *elem1,const void *elem2);
Tree deleteQue(Tree *queue,int *front,int *rear,int N);
void insertQue(Tree *queue,int *rear,Tree T,int N);
int main(){
    int N;
    scanf("%d",&N);
    int i,j;
    int a[N];
    for(i=0;i<N;i++){
        scanf("%d",&a[i]);
    }
    qsort(a,N,sizeof(a[0]),compare);
//    int b = LeftNodeNum();
//    printf("%d",b);
    Tree T;
    T=CBST(a,1,N);
    Tree queue[N];
    int rear  =-1;
    int front =-1;
    Tree B;
    insertQue(queue,&rear,T,N);
    i=0;
    while(1){
     B = deleteQue(queue,&front,&rear,N);
     i++;
     if(!B)break;
     printf("%d",B->data);
     if(i!=N)printf(" ");
     if(B->left)insertQue(queue,&rear,B->left,N);
     if(B->right)insertQue(queue,&rear,B->right,N);
    }
}
Tree deleteQue(Tree *queue,int *front,int *rear,int N){
if(*rear==*front)return NULL;
*front = (*front)%N +1;
Tree B = queue[*front];
return B;
}
void insertQue(Tree *queue,int *rear,Tree T,int N){
*rear = (*rear)%N+1;
queue[*rear]=T;
return;
}
Tree CBST(int *a,int Left,int right){
    Tree T=(Tree)malloc(sizeof(struct BinTree));
    T->left=NULL;
    T->right=NULL;
    if(Left == right){T->data = a[Left-1];return T;}
    int node = Left+LeftNodeNum(right-Left+1);
    T->data=a[node-1];
    if(node == right){T->left = CBST(a,Left,node-1),T->right=NULL;return T;}
    T->left=CBST(a,Left,node-1);
    T->right=CBST(a,node+1,right);
    return T;
}
int LeftNodeNum(int N){
    if(N==1)return 0;
    int leftCmpTreeNum = (int)pow(2,MaxHeight(N)-2) -1;
    if(N-(leftCmpTreeNum)*2-1>=leftCmpTreeNum+1)
        leftCmpTreeNum = leftCmpTreeNum+leftCmpTreeNum+1;
    else leftCmpTreeNum =leftCmpTreeNum +N-(leftCmpTreeNum)*2-1;
    return leftCmpTreeNum;
}
int MaxHeight(int N){
    int i,j;
    for(i=0,j=0;i<N;i++){
        i = i*2;
        j++;
    }
    return j;
}
int compare(const void *elem1,const void *elem2){
    return *(int*)elem1 - *(int*)elem2;
}
