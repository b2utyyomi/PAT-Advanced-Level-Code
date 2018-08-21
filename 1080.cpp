/**********************
author: yomi
date: 18.5.5
ps: cin果然又超时，我又估算错了，我发誓，大于一万的数据都用scanf
小于一万的话就耍耍小脾气用cin吧
**********************/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
struct people
{
    int ge, gi;
    int finall;
    int choice[6];
    int rankk;
    int id;
}peo[40010];
int graduate[110];
int ans[110][500];///40000/100 = 400 第二维下标小于400-->段错误
int cnt[110], last[110];
bool vis[40010];
bool cmp(people a, people b)
{
    if(a.finall!=b.finall)
        return a.finall > b.finall;
    else if(a.ge != b.ge)
        return a.ge > b.ge;
    return a.id<b.id;
}
int main()
{
    int n, m, k;
    memset(vis, false, sizeof(vis));
    memset(cnt, 0, sizeof(cnt));
    memset(last, 0, sizeof(last));
    //cin >> n >> m >> k;
    scanf("%d%d%d", &n, &m , &k);
    for(int i=0; i<m; i++){
        //cin >> graduate[i];
        scanf("%d", &graduate[i]);
    }
    for(int i=0; i<n; i++){
        //cin >> peo[i].ge >> peo[i].gi;
        scanf("%d%d", &peo[i].ge ,&peo[i].gi);
        for(int j=0; j<k; j++){
            //cin >> peo[i].choice[j];
            scanf("%d", &peo[i].choice[j]);
        }
        peo[i].finall = (peo[i].ge+peo[i].gi)/2;
        peo[i].id = i;
    }
    sort(peo, peo+n, cmp);
    int temp = 0;
    for(int i=1; i<n; i++){
        if(peo[i].finall == peo[i-1].finall && peo[i].ge == peo[i-1].ge){
            peo[i].rankk = temp;
        }
        else{
            peo[i].rankk = i;
            temp = i;
        }
    }
//    for(int i=0; i<n; i++){
//        cout << peo[i].rankk << ' ' << peo[i].id <<' ' << peo[i].finall << ' ' << peo[i].ge << endl;
//    }
    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++){
            if(!vis[peo[i].id]){
                int no = peo[i].choice[j];
                if(cnt[no] < graduate[no]){
                    vis[peo[i].id] = true;
                    ans[no][cnt[no]++] = peo[i].id;
                    last[no] = peo[i].rankk;
                }
                else{//此处前一个人的排名是该公司录取的最后一名的排名
                    if(peo[i].rankk == last[no]){
                        vis[peo[i].id] = true;
                        ans[no][cnt[no]++] = peo[i].id;
                        last[no] = peo[i].rankk;
                    }
                }
            }

        }
    }
    for(int i=0; i<m; i++){
        sort(ans[i], ans[i]+cnt[i]);
        for(int j=0; j<cnt[i]; j++){
            //cout << ans[i][j];
            printf("%d", ans[i][j]);
            if(j!=cnt[i]-1)
               printf(" ");
        }
        printf("\n");
    }
    return 0;
}
/**
11 6 3
2 1 2 2 2 3
100 100 0 1 2
60 60 2 3 5
100 90 0 3 4
90 100 1 2 0
90 90 5 1 3
80 90 1 0 2
80 80 0 1 2
80 80 0 1 2
80 70 1 3 2
70 80 1 2 3
100 100 0 2 4
**/
