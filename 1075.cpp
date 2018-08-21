/**********************
author: yomi
date: 18.5.2
ps: 真不好意思说我折腾了好几个小时 其实这题真不难
首先我的思路缕的慢 然后记不住题 刚想出个好点子 做着做着还能给忘记
老师说 不要和别人拼自己的短板 难道我应该转专业吗 别闹了
我可以的
**********************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct peo{
    int id;
    int fen;
    int perfect;
    int num = 0;
}stu[10010];

int vis[10010][10];
int cmp(peo a, peo b)
{
    if(a.fen!=b.fen)
        return a.fen > b.fen;
    else if(a.perfect != b.perfect)
        return a.perfect > b.perfect;
    else
        return a.id < b.id;

}
int main()
{
    int n, p, m;
    int p_f[10];
    memset(p_f, 0, sizeof(p_f));
    scanf("%d%d%d", &n, &p, &m);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=p; j++){
            vis[i][j] = -2;
        }
    }
    for(int i=1; i<=p; i++){
        scanf("%d", &p_f[i]);
    }
    int a, b, c;
    for(int i=0; i<m; i++){
        scanf("%d%d%d", &a, &b, &c);
        if(vis[a][b] < c){
            vis[a][b] = c;
        }
    }
    int cnt = 0;
    int flag = 0;
    int pc = 0, total, count_ = 0;
    for(int i=1; i<=n; i++){
        flag = 0;
        pc = 0;
        total = 0, count_=0;
        for(int j=1; j<=p; j++){
            if(vis[i][j]!=-2){
               if(vis[i][j] == p_f[j]){
                    pc++;
               }
               if(vis[i][j]!=-1){
                    count_++;
                    total+=vis[i][j];
               }
               flag = 1;
            }
        }
        if(flag){
            stu[cnt].id = i;
            stu[cnt].fen = total;
            stu[cnt].num = count_;
            stu[cnt++].perfect = pc;
        }

    }
    sort(stu, stu+cnt, cmp);
    printf("1 %05d %d ", stu[0].id, stu[0].fen);
    for(int j=1; j<=p; j++){
        if(vis[stu[0].id][j]==-1)
            printf("0");
        else if(vis[stu[0].id][j]==-2)
            printf("-");
        else
            printf("%d", vis[stu[0].id][j]);
        if(j!=p)
            printf(" ");
    }
    printf("\n");
    int tmp = 1;
    for(int i=1; i<cnt; i++){
        if(stu[i].num == 0)
            continue;
        if(stu[i].fen == stu[i-1].fen){
            printf("%d ", tmp);
        }
        else{
            printf("%d ", i+1);
            tmp = i+1;
        }
        printf("%05d %d ", stu[i].id, stu[i].fen);
        for(int j=1; j<=p; j++){
            if(vis[stu[i].id][j]==-1)
                printf("0");
            else if(vis[stu[i].id][j]==-2)
                printf("-");
            else
                printf("%d", vis[stu[i].id][j]);
            if(j!=p)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
/**
7 4 20
20 25 25 30
00002 2 12
00007 4 17
00005 1 19
00007 2 25
00005 1 20
00002 2 2
00005 1 15
00001 1 18
00004 3 25
00002 2 25
00005 3 22
00006 4 -1
00001 2 18
00002 1 20
00004 1 15
00002 4 18
00001 3 4
00001 4 2
00005 2 -1
00004 2 0
Sample Output:
1 00002 63 20 25 - 18
2 00005 42 20 0 22 -
2 00007 42 - 25 - 17
2 00001 42 18 18 4 2
5 00004 40 15 0 25 -
**/
