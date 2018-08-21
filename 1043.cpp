/**********************
author: yomi
date: 18.7.
ps:
**********************/
#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
    int data;
    node* lchild;
    node* rchild;
};
int pre[1500];
int post[1500];
int in[1500];
int flag = 1, cnt = 0, flag1 = 0, t = 0;
int cmp(int a, int b)
{
    return a>b;
}

void post_order(node* root)
{
    if(root!=NULL){
        post_order(root->lchild);
        post_order(root->rchild);
        post[cnt++] = root->data;
        return;
    }
}
node* create(int preL, int preR, int inL, int inR)
{
//    if(flag == 0)
//        return NULL;
    if(preL>preR){
        return NULL;
    }
    int k = -1;
    if(flag1){
        for(int i=inR; i>=inL; i--){
            if(in[i] == pre[preL]){
                k = i;
                break;
            }
        }
    }
    else{
        for(int i=inL; i<=inR; i++){
            if(in[i] == pre[preL]){
                k = i;
                break;
            }
        }
    }

    if(k == -1)
        return NULL;

    int numLeft = k-inL;
    node* root = new node;
    root->data = pre[preL];
    root->lchild = create(preL+1, preL+numLeft, inL, k-1);
    root->rchild = create(preL+numLeft+1, preR, k+1, inR);
    t++;
    return root;

}
int main()
{
    int n;
    cin >> n;
    flag = 1;
    node* root;
    for(int i=1; i<=n; i++){
        cin >> pre[i];
        in[i] = pre[i];
    }
    sort(in+1, in+n+1);

    root = create(1, n, 1, n);



    if(t != n){
        flag1 = 1;
        t = 0;
        sort(in+1, in+n+1, cmp);
        root = create(1, n, 1, n);
        //cout << t << endl;
    }
    if(t != n)
        cout << "NO";
    else{
        cout << "YES" << endl;
       // cout << root->data << endl;
        post_order(root);

        for(int i=0; i<cnt-1; i++){
            cout << post[i] << ' ';
        }
        cout << post[cnt-1];
    }

    return 0;
}
/**
7
8 6 5 7 10 8 11
Sample Output 1:
YES
5 7 6 8 11 10 8
Sample Input 2:
7
8 10 11 8 6 7 5
Sample Output 2:
YES
11 8 10 7 5 6 8
Sample Input 3:
7
8 6 8 5 10 9 11
**/
