/**********************
author: yomi
date: 18.3.6
ps:
**********************/
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
vector<int>vec[101];
bool vis[101];
int level[101], book[101];
int maxdepth;
void dfs(int id, int depth)
{
    if(vec[id].size() == 0){
        book[depth]++;
        maxdepth = max(depth, maxdepth);
        return;
    }
    for(int i=0; i<vec[id].size(); i++){
        dfs(vec[id][i], depth+1);
    }

}
void bfs()
{
    queue<int>q;
    q.push(1);
    level[1]=0;
    while(!q.empty()){
        int id = q.front();
        q.pop();
        if(vec[id].size() == 0){
            book[level[id]]++;
            maxdepth = max(maxdepth, level[id]);
        }
        else{
            for(int i=0; i<vec[id].size(); i++){
                level[vec[id][i]] = level[id]+1;
                q.push(vec[id][i]);
            }
        }
    }
}
int main()
{
    memset(vis, 0, sizeof(vis));
    int n, m, t, id1, id2;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> id1 >> t;
        for(int j=0; j<t; j++){
            cin >> id2;
            vec[id1].push_back(id2);
        }
    }
    //dfs(1, 0);
    bfs();
    for(int i=0; i<=maxdepth; i++){
        cout << book[i];
        if(i!=maxdepth)
            cout << ' ';
    }
    return 0;
}

/**
2 1
01 1 02
**/









