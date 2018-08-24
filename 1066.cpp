/**********************
author: yomi
date: 18.8.24
ps: Ä£°åÌâ
**********************/
#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
    int v, height;
    node* lchild;
    node* rchild;
}*root;
int getHeight(node* root)
{
    if(root == NULL){
        return 0;
    }
    return root->height;
}
void updateHeight(node* root)
{
    root->height = max(getHeight(root->lchild), getHeight(root->rchild))+1;
}
int getBalanceFactor(node* root)
{
    return getHeight(root->lchild)-getHeight(root->rchild);
}
void L(node* &root)
{
    node* temp=root->rchild;
    root->rchild=temp->lchild;
    temp->lchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void R(node* &root)
{
    node* temp=root->lchild;
    root->lchild=temp->rchild;
    temp->rchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}
void insert(node* &root, int v)
{
    if(root == NULL)
    {
        root = new node;
        root->height = 1;
        root->lchild = root->rchild = NULL;
        root->v = v;
        return;
    }
    if(v<root->v){
        insert(root->lchild, v);
        updateHeight(root);
        if(getBalanceFactor(root) == 2){
            if(getBalanceFactor(root->lchild) == 1){
                R(root);
            }
            else if(getBalanceFactor(root->lchild) == -1){
                L(root->lchild);
                R(root);
            }
        }
    }
    else{
        insert(root->rchild, v);
        updateHeight(root);
        if(getBalanceFactor(root) == -2){
            if(getBalanceFactor(root->rchild) == -1){
                L(root);
            }
            else if(getBalanceFactor(root->rchild) == 1){
                R(root->rchild);
                L(root);
            }
        }
    }
}
int main()
{
    int n, v;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> v;
        insert(root, v);
    }
    cout << root->v << endl;
    return 0;
}





