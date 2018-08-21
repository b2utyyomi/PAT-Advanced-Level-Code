/**********************
author: yomi
date: 18.8.20
ps:
**********************/
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

struct Node
{
    vector<int>child;
    int id;
}node[1010];
bool vis[1010];
int depth = 1, ans[1010];

void dfs(int index)
{
    if(node[index].child.size() == 0){
        return;
    }
    vis[index] = true;
    for(int i=0; i<node[index].child.size(); i++){
        if(!vis[node[index].child[i]]){
            ans[depth]++;
            depth++;
            dfs(node[index].child[i]);
            depth--;
        }
    }


}
int main()
{
    int n, m, id, t, d;
    memset(ans, 0, sizeof(ans));
    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> id >> t;
        for(int j=0; j<t; j++){
            cin >> d;
            node[id].child.push_back(d);
        }
    }
    dfs(1);
    int flag = 1;
    int Max = 0, ind;
    for(int i=1; i<1010; i++){
        if(ans[i] == 0)
            break;
        if(ans[i] > Max){
            Max = ans[i];
            flag = 0;
            ind = i;
        }
    }
    if(flag == 0)
        cout << Max << ' ' << ind+1;
    else{
        cout << "1 1";
    }
    return 0;
}
/**
Sample Input:
23 13
21 1 23
01 4 03 02 04 05
03 3 06 07 08
06 2 12 13
13 1 21
08 2 15 16
02 2 09 10
11 2 19 20
17 1 22
05 1 11
07 1 14
09 1 17
10 1 18
Sample Output:
9 4
**/
