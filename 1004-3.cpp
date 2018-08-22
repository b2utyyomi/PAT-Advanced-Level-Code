/**********************
author: yomi
date: 18.8.22
ps: 要是考试出这种半小时就能搞定的题多好啊
**********************/
#include <iostream>
#include <vector>
using namespace std;

vector<int>node[110];
int n, m, maxdepth;
int cnt[110];
bool vis[110];
void dfs(int index, int depth)
{
    if(node[index].size() == 0){
        cnt[depth]++;
        //cout << "depth:" << depth << endl;
        maxdepth = max(depth, maxdepth);
        return;
    }
    vis[index] = true;
    for(int i=0; i<node[index].size(); i++){
        if(vis[node[index][i]] == false){
            dfs(node[index][i], depth+1); ///写出了小BUG depth++
        }
    }
}
int main()
{
    cin >> n >> m;
    int id, t, d;
    for(int i=0; i<m; i++){
        cin >> id >> t;
        for(int i=0; i<t; i++){
            cin >> d;
            node[id].push_back(d);
        }
    }
    dfs(1, 1);
    for(int i=1; i<maxdepth; i++){
        cout << cnt[i] << ' ';
    }
    cout << cnt[maxdepth];
    return 0;
}

/**
Sample Input
2 1
01 1 02
Sample Output
0 1
**/


