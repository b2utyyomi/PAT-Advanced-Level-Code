/**********************
author: yomi
date: 18.8.23
ps: ����ͼ�����ڽӱ�� ��Ȼ������ ��ʱ�˿�զ��
�� ��������Ƿ�µ�ծ ֻ������������
����û�����ڳ��� ������һ��Ҳ���� �� �������
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
        ///ansΪʲô��д���������ҵ�����
        ///д��ͻ�������� �Ҿ����ټ�ȥһ������ȷ��� ����2Ϊ���ڵ�ʱ���������� �Ѳ���6
        ///��ѽ
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
