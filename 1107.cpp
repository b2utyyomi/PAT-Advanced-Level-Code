/**********************
author: yomi
date: 18.8.25
ps: 学了立马用 果然惨不忍睹 一个半小时才搞定 虽然一次过 但是中间BUG太多
和题解相比还是不够简洁啊
**********************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int father[1010];
int isRoot[1010], cnt[1010];
int n, max_;
vector<int>vec[1010];
bool vis[1010];
void init()
{
    for(int i=1; i<=max_; i++){
        father[i] = i;
        isRoot[i] = 0;
    }
}
int cmp(int a,int b)
{
    return a>b;
}
int findFather(int v)
{
    if(v == father[v]){
        return v;
    }
    else{
        int F = findFather(father[v]);
        father[v] = F;
        return F;
    }
}
void Union(int a, int b)
{
    int fa = findFather(a);
    int fb = findFather(b);
    if(fa!=fb){
        father[fa] = fb;
    }
}
int main()
{
    char ch;
    int t, first, next, a;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> t >> ch;
        for(int j=0; j<t; j++){
            cin >> a;
            vec[i].push_back(a);
            vis[a] = true;
            max_ = max(a, max_);
        }
    }
    init();
    for(int i=0; i<n; i++){
        int a = vec[i][0];
        for(int j=1; j<vec[i].size(); j++){
            Union(a, vec[i][j]);
        }
    }
    for(int i=1; i<=max_; i++){
        isRoot[findFather(i)] = 1;
    }
    int ans = 0;
    for(int i=1; i<=max_; i++){
        if(isRoot[i] == 1 && vis[i]){
            ans++;
        }
    }
    for(int i=0; i<n; i++){
        cnt[father[vec[i][0]]]++;
    }
    //cout << father[2] << endl;
    sort(cnt, cnt+1010, cmp);
    cout << ans << endl;
    for(int i=0; i<ans-1; i++){
        cout << cnt[i] << ' ';
    }
    cout << cnt[ans-1];
    return 0;
}
/**
Sample Input:
8
3: 2 7 10
1: 4
2: 5 3
1: 4
1: 3
1: 4
4: 6 8 1 5
1: 4
Sample Output:
3
4 3 1
**/
