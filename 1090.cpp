/**********************
author: yomi
date: 18.8.20
ps:
**********************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 101010;
vector<int>child[maxn];
bool vis[maxn];
int n, d, depth = 1, num, maxdepth;
double p, r, ans = 0.0;
int cmp(int a, int b)
{
    return a>b;
}
void dfs(int index, int depth)
{
    if(child[index].size() == 0){
        ans = max(ans, p);
        if(depth > maxdepth){
            maxdepth = depth;
            num=1;
        }
        else if(depth == maxdepth){
            num++;
        }
        return;
    }
    vis[index] = true;
    for(int i=0; i<child[index].size(); i++){
        if(!vis[child[index][i]]){

            p = p*(r/100.0+1);
            dfs(child[index][i], depth+1);

            p = p/(r/100.0+1);

        }
    }

}
int main()
{
    memset(vis, false, sizeof(vis));
    scanf("%d%lf%lf", &n, &p, &r);
    int k = 0;
    for(int i=0; i<n; i++){
        scanf("%d", &d);
        if(d == -1)
        {
            k = i;
            continue;
        }
        child[d].push_back(i);
    }
    dfs(k, 1);
    printf("%.2f %d",ans, num);
    return 0;
}
/**
Sample Input:
9 1.80 1.00
1 5 4 4 -1 4 5 3 6
Sample Output:
1.85 2
**/




