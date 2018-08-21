/**********************
author: yomi
date: 18.8.5
ps: 简单的小题 出了几处bug 浪费了不少时间
**********************/
#include <iostream>
#include <stack>
#include <sstream>
#include <cstdio>
using namespace std;
struct node
{
    node* lchild;
    node* rchild;
    int data;
};
int in_order[50];
int pre_order[50];
int post_order[50];
int cnt1 = 0;
node *create(int preL, int preR, int inL, int inR)
{
    if(preL>preR){///忘了写
        return NULL;
    }

    node *root = new node;
    root->data = pre_order[preL];
    int k;
    for(k = inL; k<=inR; k++){
        if(in_order[k] == pre_order[preL]){
            break;
        }
    }
    int numLeft = k-inL;
    root->lchild = create(preL+1, preL+numLeft, inL, k-1);///赋给左孩子忘了写
    root->rchild = create(preL+numLeft+1, preR, k+1, inR);
    return root;
}
void post(node *root)
{
    if(root == NULL)
        return;
    post(root->lchild);
    post(root->rchild);
    post_order[cnt1++] = root->data;
}
int main()
{
    int n, cnt = 1, cnt2 = 1;

    cin >> n;
    getchar();
    stack<int>st;
    string s;

    while(!st.empty()){///写在了for循环里 错了呗
        st.pop();
    }

    for(int i=0; i<2*n; i++){
        getline(cin, s);
        stringstream is;
        is.str(s);
        int d;
        string op;
        is >> op ;
        is >> d;
        if(op == "Push"){
            st.push(d);
            pre_order[cnt2++] = d;
        }
        else if(op == "Pop"){
            in_order[cnt++] = st.top();
            st.pop();
        }
    }
//    for(int i=1; i<=n; i++){
//        cout << in_order[i] << ' ';
//    }
//    cout << endl;
    node* root;
    root = create(1, n, 1, n);
    post(root);
    for(int i=0; i<cnt1-1;i++){
        cout << post_order[i] << ' ';
    }
    cout << post_order[cnt1-1];
    return 0;
}
/**
6
Push 1
Push 2
Push 3
Pop
Pop
Push 4
Pop
Pop
Push 5
Push 6
Pop
Pop
**/
