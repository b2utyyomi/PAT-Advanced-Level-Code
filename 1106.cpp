/**********************
author: yomi
date: 18.8.23
ps: 算法实现零障碍 这题干都出现快五次了 我都要背下来了
然而我还是出了BUG T^T 入门级别的小BUG 好在半小时内搞定了这道题
**********************/
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
int n, t, d;
double p, r,lowest=0x3fffffff;
vector<int>node[100010];
vector<double>cnt;
bool vis[100010];
void dfs(int index, int depth)
{
    int s = node[index].size();
    if(s == 0){
        if(p<=lowest){
            lowest = p;
            cnt.push_back(lowest);
        }
        return;
    }
    vis[index] = true;
    for(int i=0; i<s; i++){
        if(!vis[node[index][i]]){
            p=p*(r/100+1);
            dfs(node[index][i], depth+1);
            p = p/(r/100+1);
        }

    }
}
int main()
{
    scanf("%d%lf%lf", &n, &p, &r);
    for(int i=0; i<n; i++){
        scanf("%d", &t);
        for(int j=0; j<t; j++){
            scanf("%d", &d);
            node[i].push_back(d);
        }
    }
    dfs(0, 1);
    printf("%.4f %d", lowest, count(cnt.begin(), cnt.end(), lowest));
    return 0;
}
/**
Sample Input:
10 1.80 1.00
3 2 3 5
1 9
1 4
1 7
0
2 6 1
1 8
0
0
0
Sample Output:
1.8362 2
**/
