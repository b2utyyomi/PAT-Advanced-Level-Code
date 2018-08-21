/**********************
author: yomi
date: 18.8.21
ps:
**********************/
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int n;
struct Node
{
    int data;
    int l, r;
}node[110];
bool vis[110];
queue<int>q;
int level[110], cnt, in[110], cnt1;
void bfs()
{
    while(!q.empty())
        q.pop();
    q.push(0);
    vis[0] = true;
    while(!q.empty()){
        int a = q.front();
        level[cnt++] = node[a].data;
        q.pop();
        if(node[a].l!=-1){
            q.push(node[a].l);
        }
        if(node[a].r!=-1){
            q.push(node[a].r);
        }
    }

}
void in_order(int index)
{
    if(node[index].l!=-1)
        in_order(node[index].l);
    node[index].data = in[cnt1++];
    if(node[index].r!=-1)
        in_order(node[index].r);
}
int main()
{

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> node[i].l >> node[i].r;
    }
    for(int i=0; i<n; i++){
        cin >> in[i];
    }
    sort(in, in+n);
    in_order(0);
    bfs();
    for(int i=0; i<cnt-1; i++){
        cout << level[i] << ' ';
    }
    cout << level[cnt-1];
    return 0;
}
/**
9
1 6
2 3
-1 -1
-1 4
5 -1
-1 -1
7 -1
-1 8
-1 -1
73 45 11 58 82 25 67 38 42
**/


