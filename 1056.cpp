/**********************
author: yomi
date: 18.8.1
ps: 我辛苦了 一次ac 仿佛看见了及格的希望
**********************/
#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
struct programmer
{
    int w;
    int r;
}p[10010];
int main()
{
    int np, ng, we, order;
    queue<int>q;
    while(!q.empty()){
        q.pop();
    }
    scanf("%d%d", &np, &ng);
    for(int i=0; i<np; i++){
        scanf("%d", &we);
        p[i].w = we;
        p[i].r = 0;
    }
    for(int i=0; i<np; i++){
        scanf("%d", &order);
        q.push(order);
    }
    int z = 0;
    while(q.size()>1){
//        z++;
//        if(z>5){
//            break;
//        }

        int s = q.size();
       // cout << q.size() << endl;
        int rr = s/ng;
        if(s%ng){
            rr++; /// 3
        }
        //if(q.size() == 2)
            //cout << rr << endl;
        int cnt = 0;///8 9 7 3
        for(int t=0; t<s; t+=ng){/// 0 3 6 9   +=ng这个bug呀 我辛苦了！！！
            int max_ = 0;
            int j = -1;
            for(int i=t+0; i<t+ng && i<s; i++){ /// 0+0
                cnt++;
                if(!q.empty()){
                    int k = q.front();
                    if(p[k].w > max_){
                        if(j!=-1){
                            p[j].r = rr+1;
                        }
                        j = k;
                        max_ = p[k].w;
                    }
                    else{
                        p[k].r = rr+1;
                    }
                    q.pop();
                }
            }
            if(j!=-1){
                q.push(j);
                p[j].r = 0;
            }
        }
        int max_ = 0;
        int j = -1;
        while(cnt < s){
            if(!q.empty()){
                int k = q.front();
                if(p[k].w > max_){
                    if(j!=-1){
                        p[j].r = rr+1;
                    }
                    j = k;
                    max_ = p[k].w;
                }
                else{
                    p[k].r = rr+1;
                }
                q.pop();
            }
            cnt++;
        }
        if(j!=-1){
            q.push(j);
            p[j].r = 0;
        }

    }
    p[q.front()].r = 1;
    for(int i=0; i<np-1; i++){
        printf("%d ", p[i].r);
    }
    printf("%d", p[np-1].r);



    return 0;
}
/**
11 3
25 18 0 46 37 3 19 22 57 56 10
6 0 8 7 10 5 9 1 4 2 3

5 5 5 2 5 5 5 3 1 3 5
**/
