/**********************
author: yomi
date: 18.5.26
ps: 算法想到了 和 题解并没有太大出入 但是在实现过程中我的问题就暴露出来了
思维不够灵活 要充分利用下标 否则超时
**********************/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int pos[100010];
int main()
{
    int n, cnt=0, tmp;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &tmp);
        pos[tmp] = i;
    }
    int k=0;
    int pos3 = 0;
    while(1){
        if(pos[0] == 0){
            for(; k<n; k++){
                if(pos[k]!=k){
                    pos3 = k;
                    break;
                }
            }
            if(k == n){
                break;
            }
            pos[0] = pos[pos3];
            pos[pos3] = 0;
            cnt++;
        }
        else{
            swap(pos[0], pos[pos[0]]);
            cnt++;
        }

    }

//    for(int i=0; i<n; i++){
//        cout << pos[i] << ' ';
//    }
//    cout << endl;
    cout << cnt << endl;
    return 0;
}
/*
10 3 5 7 2 6 4 9 0 8 1

9
**/
