/**********************
author: yomi
date: 18.5.4
ps:
**********************/
#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;
struct people
{
    int flag;
    int perfect;
    int id;
    int total;
    int score[6];
}peo[10010];
void init(int n, int p)
{
    for(int i=1; i<=n; i++){
        for(int j=1; j<=p; j++){
            peo[i].score[j] = -2;
        }
        peo[i].total = 0;
        peo[i].perfect = 0;
        peo[i].flag = 1;

    }
}
bool cmp(people a, people b)
{
    if(a.total != b.total){
        return a.total > b.total;
    }
    else if(a.perfect !=b.perfect)
    {
        return a.perfect > b.perfect;
    }
    else
        return a.id < b.id;
}
int main()
{
    int n, p, m, a, b, c;
    int p_f[6];
    scanf("%d%d%d", &n, &p, &m);
    init(n, p);
    for(int i=1; i<=p; i++){
        scanf("%d", &p_f[i]);
    }
    for(int i=0; i<m; i++){
        scanf("%d%d%d", &a, &b, &c);
        if(peo[a].score[b] < c){
            peo[a].score[b] = c;
        }
        peo[a].id = a;

    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=p; j++){
            if(peo[i].score[j] >= 0){
                peo[i].total += peo[i].score[j];
                if(peo[i].score[j] == p_f[j])
                    peo[i].perfect++;
                peo[i].flag = 0;
            }
        }
    }
    sort(peo+1, peo+n+1, cmp);
    int tmp = 1;
    printf("1 %05d %d", peo[1].id, peo[1].total);
    for(int j=1; j<=p; j++){
        if(peo[1].score[j] == -2)
            printf(" -");
        else if(peo[1].score[j] == -1)
            printf(" 0");
        else
         printf(" %d", peo[1].score[j]);


    }
    printf("\n");
    int cnt = 2;
    int temp = 1;
    for(int i=2; i<=n; i++){
//        if(peo[i].total == 0){   ///错了 错了 是不能通过编译器的不能输出 总分为零可以
//            continue; //通过编译器的还是得输出
//        }
        if(peo[i].flag == 1)///
            continue;
        if(peo[i].total == peo[temp].total)/// i-1? 不是的 前一个可能是非法数据
            printf("%d %05d %d", tmp, peo[i].id, peo[i].total);
        else{
            printf("%d %05d %d", cnt, peo[i].id, peo[i].total);
            tmp = cnt;
        }
        for(int j=1; j<=p; j++){
            if(peo[i].score[j] == -2)
                printf(" -");
            else if(peo[i].score[j] == -1)
                printf(" 0");
            else
             printf(" %d", peo[i].score[j]);

        }
        temp = i;
        printf("\n");
        cnt++;
    }
    return 0;
}
/**
7 4 21
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
00003 3 0


1 00002 63 20 25 - 18
2 00005 42 20 0 22 -
2 00007 42 - 25 - 17
2 00001 42 18 18 4 2
5 00004 40 15 0 25 -
**/
