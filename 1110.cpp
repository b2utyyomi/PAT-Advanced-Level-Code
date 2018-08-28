/**********************
author: yomi
date: 18.8.28
ps: 一般来讲二叉树不分左右是肯定不行的 我又走进岔路口了 一堆段错误
改道~
surface 抖屏抖得我要瞎了
拿手机找BUG吧 明天再改
**********************/
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
struct Node
{
    int l;
    int r;
}node[25];
bool vis[25];
vector<int>levelIndex[25];
int maxdepth;
void dfs(int index, int depth)
{
    //cout << index << endl;
    if(node[index].l == -1 && node[index].r == -1){
        maxdepth = max(depth, maxdepth);
        levelIndex[depth].push_back(index);
        return;
    }
    if(vis[index])
        return;
    vis[index] = true;
    levelIndex[depth].push_back(index);
    if(node[index].l!=-1){
        dfs(node[index].l, depth+1);
    }
    if(node[index].r!=-1){
        dfs(node[index].r, depth+1);
    }

}
bool isOK()
{
    for(int i=1; i<=maxdepth-2; i++){
        for(int j=0; j<levelIndex[i].size(); j++){
            int id = levelIndex[i][j];
            if(node[id].l == -1 || node[id].r == -1)
                return false;
        }
    }
    int flag = 1;
    int s = levelIndex[maxdepth-1].size();
    for(int j=s-1; j>=0; j--){
        int id = levelIndex[maxdepth-1][j];
        if(node[id].l==-1&&node[id].r!=-1){
            return false;
        }
        if(flag == 1){
            if(node[id].l!=-1 || node[id].r!=-1){
                flag = 0;
            }
        }

        else if(flag == 0){
            if(node[id].l==-1 || node[id].r==-1)
                return false;
        }
    }
    return true;
}
int main()
{
    int n;
    char l,r;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> l >> r;
        if(l == '-'){
            node[i].l = -1;
        }
        else{
            node[i].l = l-'0';
            vis[l-'0'] = true;
        }
        if(r == '-'){
            node[i].r = -1;
        }
        else{
            node[i].r = r-'0';
            vis[r-'0'] = true;
        }
    }
    int root;
    for(int i=0; i<n; i++){
        if(!vis[i]){
            root = i;
        }
    }
    memset(vis, 0, sizeof(vis));
    dfs(root, 1);
    if(isOK())
    {
        int s = levelIndex[maxdepth].size();
        int id = levelIndex[maxdepth][s-1];

        cout << "YES" << ' ' << id;
    }
    else{
        cout << "NO" << ' ' << root;
    }
//    cout << endl;
//    cout << maxdepth << endl;
//    for(int i=1; i<=maxdepth; i++){
//        for(int j=0; j<levelIndex[i].size(); j++){
//            cout << levelIndex[i][j] << ' ';
//        }
//        cout << endl;
//    }
    return 0;
}
/**
9
7 8
- -
- -
- -
0 1
2 3
4 5
- -
- -
**/
