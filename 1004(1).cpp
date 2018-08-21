/**********************
author: yomi
date: 18.2.27
ps:
**********************/
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
int maxdepth = -1;
vector<int>vec[100];

int book[100], level[100];

void dfs(int id, int depth)
{
    if(vec[id].size() == 0){
        book[depth]++;
        maxdepth = max(maxdepth, depth);
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
    level[1] = 0;
    while(!q.empty()){
        int id = q.front();
        q.pop();
        if(vec[id].size() == 0){
            maxdepth = max(maxdepth, level[id]);
            book[level[id]]++;
        }
        for(int i=0; i<vec[id].size(); i++){
            q.push(vec[id][i]);
            level[vec[id][i]] = level[id]+1;
        }
    }
}
int main()
{
    int m, n, t, id1, id2;
    memset(book, 0, sizeof(book));
    cin >> m >> n;
    for(int i=0; i<n; i++){
        cin >> id1 >> t;
        for(int j=0; j<t; j++){
            cin >> id2;
            vec[id1].push_back(id2);
        }
    }
    //dfs(1, 0);
    bfs();
    int cnt = 0;
    for(int i=0; i<=maxdepth; i++){
        if(cnt)
            cout << ' ';
        cout << book[i];
        cnt++;
    }

    return 0;
}

/**
2 1
01 1 02

**/
