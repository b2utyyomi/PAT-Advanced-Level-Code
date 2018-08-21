/**********************
author: yomi
date: 18.6.17
ps:
不会不会 虽然乙级刷过这道题 但是现在还是不会 要多多体会这种思想
我能想到的就只有暴力循环 T^T
int len = strlen(str);
循环中一定要利用事先计算好的len
**********************/
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <stdio.h>
#include <cstdlib>
using namespace std;
const int mod = 1000000007;
int plnum[100010];
char str[100010];
int main()
{
    memset(str, 0, sizeof(str));
    memset(plnum, 0, sizeof(plnum));
    scanf("%s", str);
    int len = strlen(str);
    ///计算每一个位置的左边有多少个p，并存在数组中
    for(int i=0; i<len; i++){///如果此处不用len,而是随时计算的话，会超时
        if(i > 0){
            plnum[i] = plnum[i-1];
        }
        if(str[i] == 'P'){
            plnum[i]++;
        }
    }
    int ans = 0, trnum = 0;
    for(int i=len-1; i>=0; i--){
        if(str[i] == 'T'){
            trnum++;
        }
        else if(str[i] == 'A'){
            ans = (ans+plnum[i]*trnum)%mod;
        }

    }
    printf("%d\n", ans);
    return 0;
}

/***
明显下面的解法更好

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int num_t=0, num_at=0, num_pat=0;
    ///cout << str.length() << endl;
    for(int i=str.size()-1; i>=0; i-- ){///天呐 我这就写了个size_t, 就死循环了
        if(str[i] == 'T'){
            num_t ++;
            ///num_t %= 1000000007;
        }
        if(str[i] == 'A'){
            num_at = (num_at+num_t) % 1000000007;///这里写个+=也错了 这就是优先级的事了
        }
        if(str[i] == 'P'){
            num_pat = (num_pat+num_at) % 1000000007;
        }
    }
    cout << num_pat;
    return 0;
}

**/
