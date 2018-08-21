/**********************
author: yomi
date: 18.8.18
ps:
**********************/
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

const int maxn = 100010;
struct Node
{
    vector<int>child;
    int id;
    double data;
}node[maxn];
double sum = 0.0;
double p, r, price;
bool vis[maxn];
void dfs(int index)
{
    int cnt = node[index].child.size();
    if(cnt == 0){
        sum += p*node[index].data;
        return;
    }
    if(!vis[index]){
        p = p*(r/100+1);
        vis[index] = true;
        for(int i=0; i<cnt; i++){
            dfs(node[node[index].child[i]].id);
        }
        p/=(r/100+1);
    }

}
int main()
{
    int n, t, d;
    scanf("%d%lf%lf", &n, &p, &r);
    for(int i=0; i<n; i++){
        scanf("%d", &t);
        node[i].id = i;
        if(t>0){
            for(int j=0; j<t; j++){
                scanf("%d", &d);
                node[i].child.push_back(d);
            }
        }
        else if(t == 0){
            scanf("%lf", &node[i].data);
        }

    }
    price = p;
    dfs(0);
    printf("%.1f", sum);
    return 0;
}
/**
Sample Input:
10 1.80 1.00
3 2 3 5
1 9
1 4
1 7
0 7
2 6 1
1 8
0 9
0 4
0 3
Sample Output:
42.4
**/
