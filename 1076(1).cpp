/**********************
author: yomi
date: 18.8.23
ps: 遍历图还是邻接表吧 不然整不好 超时了可咋整
唉 昨天晚上欠下的债 只能现在来还了
还是没能折腾出来 讲道理一点也不难 哎 找题解了
**********************/
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
int n, l, t, u, qcnt, q, ans, lnow;
const int maxn = 1010;
struct Node
{
    int id;
    int level;
};
vector<Node>g[maxn];
bool vis[maxn];
void bfs(int s)
{
    queue<Node>q;
    while(!q.empty())
        q.pop();
    Node start;
    start.id = s;
    start.level=0;
    q.push(start);
    vis[start.id] = true;
    while(!q.empty()){
        Node topNode=q.front();
        cout << topNode.id << ' ';
        q.pop();
        ///ans为什么不写在这里是我的问题
        ///写这就会计算根结点 我觉得再减去一就是正确结果 但是2为根节点时，三层以内 搜不到6
        ///迷呀
        int u = topNode.id;
        for(int i=0; i<g[u].size(); i++){
            Node next = g[u][i];
            if(!vis[next.id])
            {
                next.level=topNode.level+1;
                q.push(next);
                ans++;
                vis[next.id] = true;
            }
        }
        if(topNode.level>=l)
            break;

    }
}
int main()
{
    cin >> n >> l;
    for(int i=1; i<=n; i++){
        cin >> t;
        for(int j=0; j<t; j++){
            cin >> u;
            Node a;
            a.id = i;
            g[u].push_back(a);
        }
    }
    cin >> qcnt;
    for(int i=0; i<qcnt; i++){
        memset(vis, false, sizeof(vis));
        ans = 0;
        cin >> q;
        bfs(q);
        cout << endl;
        cout << ans << endl;
    }

    return 0;
}
/**
Sample Input:
7 3
3 2 3 4
0
2 5 6
2 3 1
2 3 4
1 4
1 5
2 2 6
Sample Output:
4
5
**/
