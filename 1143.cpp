/******************************
author:yomi
date:18.9.5
ps: 只是过了样例呀 半个小时不到虽然就写好了 然而一点用没有呀 碎了碎了 明天再看
******************************/
#include<iostream>
#include <algorithm>
using namespace std;
const int maxn = 10010;
int pre[maxn];
int in[maxn];
bool vis[maxn];
int flag;
struct node
{
    int data;
    node* l;
    node* r;
};
int maxdepth = 1, father;
node* create(int preL, int preR, int inL, int inR)
{
    if(preL > preR){
        return NULL;
    }
    node* root = new node;
    root->data= pre[preL];
    int j, k = 0;
    for(int i=inL; i<=inR; i++){
        k++;
        if(in[i] == pre[preL]){
            j = i;
            break;
        }
    }

    root->l = create(preL+1, preL+k-1, inL, j-1);
    root->r = create(preL+k, preR, j+1, inR);
    return root;
}
void dfs(node* root, int depth, int u)
{
    if(flag == 1){
        return;
    }
    if(root->data == u){
        maxdepth = depth;
        flag = 1;
        return;
    }
    if(root->l){
        if(root->l->data == u){
            father = root->data;
        }
        dfs(root->l, depth+1, u);
    }

    if(root->r){
        if(root->r->data == u){
            father = root->data;
        }
        dfs(root->r, depth+1, u);
    }
}
int main()
{
    int n,u, v, m;
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        cin >> pre[i];
        in[i] = pre[i];
        vis[pre[i]] = true;
    }
    sort(in+1, in+1+m);
    for(int i=0; i<n; i++){
        cin >> u >> v;
        if(!vis[u] && vis[v]){
            cout << "ERROR: " << u <<" is not found." << endl;
        }
        else if(!vis[v] && vis[u]){
            cout << "ERROR: " << v <<" is not found." << endl;
        }
        else if(!vis[u] && !vis[v]){
            cout << "ERROR: " << u << " and " << v << " are not found." << endl;
        }
        else{
            node* root = create(1, m, 1, m);
            maxdepth = 1;
            flag = 0;
            dfs(root, 1, u);
            int dep1 = maxdepth;
            int fu = father;
            maxdepth = 1;
            flag = 0;
            dfs(root, 1, v);
            int fv = father;
            int dep2 = maxdepth;
            if(fu == v){
                cout << v << " is an ancestor of " << u << "." << endl;
            }
            else if(fv == u){
                cout << u << " is an ancestor of " << v << "." << endl;
            }
            else{
                cout << "LCA of " << u << " and " << v << " is " << max(dep1, dep2)-1 <<"." << endl;;
            }
        }
    }
    return 0;
}
/**
Sample Input:

6 8
6 3 1 2 5 4 8 7
2 5
8 7
1 9
12 -3
0 8
99 99

Sample Output:

LCA of 2 and 5 is 3.
8 is an ancestor of 7.
ERROR: 9 is not found.
ERROR: 12 and -3 are not found.
ERROR: 0 is not found.
ERROR: 99 and 99 are not found.

**/
