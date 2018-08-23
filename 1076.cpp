/**********************
author: yomi
date: 18.8.23
ps: ���������22��
���ü��������˼· Ȼ���ְ�BUGд���˻�
���ڵ�ͨ �״��ύ22�� �� �����ǲ�����
��������
������� �ҿ��� �ҵ���������������ᵽ�ĵ��ʹ��� �����Ƽ���bfs
���Ҿ������� ����bfs��һ��
**********************/
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 1010;
int g[maxn][maxn];
bool vis[maxn];
int n, L, u, v, t, qcnt, q, ans;
void dfs(int index, int level)
{
    if(level == L+1){
        return;
    }
    if(vis[index])
        return;
    ans++;
    //cout << "index: " << index << ' ';
    vis[index] = true;
    for(int i=1; i<=n; i++){
        if(!vis[i] && g[index][i]==1){
            dfs(i, level+1);
        }
    }

}
int main()
{
    //cin >> n >> L;
    scanf("%d%d", &n, &L);
    for(int i=1; i<=n; i++){
        scanf("%d", &t);
        for(int j=0; j<t; j++){
            scanf("%d", &u);
            g[u][i] = 1;
        }
    }
//    for(int i=1; i<=n; i++){
//        for(int j=1; j<=n; j++){
//            if(g[i][j]){
//                cout << i << ' ' << j << ' ' << g[i][j] << endl;
//            }
//        }
//    }
    scanf("%d", &qcnt);
    for(int i=0; i<qcnt; i++){
        ans = 0;
        memset(vis, false, sizeof(vis));
        scanf("%d", &q);
        dfs(q, 0);
        //cout << endl;
        printf("%d\n", ans-1);
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
