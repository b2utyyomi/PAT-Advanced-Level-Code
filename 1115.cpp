/******************************
author:yomi
date:18.8.29
ps: 写着写着就把根节点写没了 调了又调 共花了一个小时解决问题 一次过T^T
******************************/
#include<iostream>
#include <queue>
using namespace std;
const int maxn = 10010;
int maxlayer;
struct node
{
    int data;
    int layer;
    node* l;
    node* r;
};
vector<node*>vec[maxn];
node* insert_node(node *t, node* root)
{

    if(t->data <= root->data && root->l == NULL){
        root->l = t;
        return root;
    }
    else if(root->r == NULL && t->data > root->data){
        root->r = t;
        return root;
    }

    if(t->data <= root->data && root->l!=NULL){
        insert_node(t, root->l);
    }
    else if(t->data > root->data && root->r != NULL){
        insert_node(t, root->r);
    }
    return root;
}
void in_order(node *root)
{
    if(root->l){
        in_order(root->l);
    }
    cout << root->data << endl;
    if(root->r){
        in_order(root->r);
    }
}
void level(node* root)
{
    queue<node*>q;
    while(!q.empty())
        q.pop();
    q.push(root);
    root->layer = 1;
    while(!q.empty()){
        node* a = q.front();
        //cout << a->data << endl;
        vec[a->layer].push_back(a);
        maxlayer = max(maxlayer, a->layer);
        q.pop();
        if(a->l){
            a->l->layer = a->layer+1;
            q.push(a->l);
        }

        if(a->r){
            a->r->layer = a->layer+1;
            q.push(a->r);
        }

    }

}
int main()
{
    int n, d;
    cin >> n;
    node* root;
    root = new node;
    cin >> d;
    root->l = NULL;
    root->r = NULL;
    root->data = d;
    for(int i=1; i<n; i++){
        cin >> d;
        node *t = new node;
        t->data = d;
        t->l = NULL;
        t->r = NULL;
        root = insert_node(t, root);

    }
    //in_order(root);
    level(root);
//    for(int i=0; i<=maxlayer; i++){
//        for(int j=0; j<vec[i].size(); j++){
//            cout << vec[i][j]->data << ' ';
//        }
//        cout << endl;
//    }
    int n1 = vec[maxlayer].size(), n2 = vec[maxlayer-1].size();
    cout << n1 << " + " << n2 << " = " << n1+n2 << endl;
    return 0;
}
/**
Sample Input:

9
25 30 42 16 20 20 35 -5 28

Sample Output:

2 + 4 = 6

**/
