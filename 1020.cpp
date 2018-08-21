/**********************
author: yomi
date: 18.8.4
ps:
**********************/
#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

struct node
{
    int data;
    node* lchild;
    node* rchild;
};
int pre[50];
int in[50], lev[50];
int n, cnt = 0;
void level(node* root)
{
    if(root == NULL)
        return;
    queue<node* >q;
    while(!q.empty()){
        q.pop();
    }
    q.push(root);
    while(!q.empty()){
        node* a = q.front();
        lev[cnt++] = a->data;
        q.pop();
        if(a->lchild){
            q.push(a->lchild);
        }
        if(a->rchild){
            q.push(a->rchild);
        }
    }

}
node* create(int preL, int preR, int inL, int inR)
{
    if(preL>preR){
        return NULL;
    }
    node* root=new node;
    root->data = pre[preR];
    int k;
    for(int i=inL; i<=inR; i++){
        if(in[i] == pre[preR]){
            k = i;
            break;
        }
    }
    int numLeft = k-inL;
    root->lchild = create(preL, preL+numLeft-1, inL, k-1);
    root->rchild = create(preL+numLeft, preR-1, k+1, inR);
    return root;
}
int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d", &pre[i]);
    }

    for(int i=1; i<=n; i++){
        scanf("%d", &in[i]);
    }
    node* root;
    root = create(1, n, 1, n);
    level(root);
    for(int i=0; i<cnt-1; i++){
        cout << lev[i] << ' ';
    }
    cout <<lev[cnt-1];
    return 0;
}
/**
7
2 3 1 5 7 6 4
1 2 3 4 5 6 7

4 1 6 3 5 7 2
**/
