/**********************
author: yomi
date: 18.8.6
ps:
**********************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 200;
struct Node
{
    int lchild;
    int rchild;
}node[maxn];
int num = 0;
int n;
bool vis[maxn];
int convert(char c)
{
    if(c == '-'){
        return -1;
    }
    else{
        vis[c-'0'] = true;
        return c-'0';
    }
}
int find_root()
{
    for(int i=0; i<n; i++){
        if(vis[i] == false){
            return i;
        }
    }
}
void post(int root)
{   if(root == -1)
        return;
    post(node[root].lchild);
    post(node[root].rchild);
    swap(node[root].lchild,node[root].rchild);
}
void level(int root)
{
    if(root == -1)
        return;
    queue<int>q;
    while(!q.empty())
        q.pop();
    q.push(root);
    while(!q.empty()){
        int a = q.front();
        if(num!=n-1)
            printf("%d ", a);
        else
            printf("%d\n", a);
        num++;
        q.pop();
        if(node[a].lchild!=-1)
            q.push(node[a].lchild);
        if(node[a].rchild!=-1)
            q.push(node[a].rchild);
    }
}
void in(int root)
{
    if(root == -1)
        return;
    in(node[root].lchild);
    if(num!=n-1)
        printf("%d ", root);
    else
        printf("%d", root);
    num++;
    in(node[root].rchild);
}
int main()
{
    memset(vis, 0, sizeof(vis));
    char lchild, rchild;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        getchar();
        scanf("%c %c", &lchild, &rchild);
        node[i].lchild = convert(lchild);
        node[i].rchild = convert(rchild);
    }
    int root = find_root();
    post(root);
    level(root);
    num = 0;
    in(root);
    return 0;
}
/**
8
1 -
- -
0 -
2 7
- -
- -
5 -
4 6
**/
