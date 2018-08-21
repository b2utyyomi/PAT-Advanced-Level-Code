/**********************
author: yomi
date: 18.6.21
ps:
Each input file contains one test case which gives a positive integer N in the range (0, 10000).
输入不一定是4位数哦
尝试了一下sprintf和sscanf就出了很多麻烦
不得不说 他们真的很方便， 要多多练习才行
**********************/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int cmp(char a, char b)
{
    return a>b;
}
int main()
{
    char s[10], s1[10];
    int n, n1, ans;
    scanf("%s", s);
    sscanf(s,"%d", &n);
    ans = n;
    int cnt = 0;
    while(1){ /// 本来这里写的ans!=6174 结果差一分满分 考虑到逻辑和实现都没有问题
        sprintf(s, "%04d", ans);///机智的我就想到了边界数据
        sprintf(s1, "%04d", ans);
        sort(s, s+4);
        sort(s1, s1+4, cmp);

        sscanf(s1,"%d", &n1);
        sscanf(s,"%d", &n);

        if(strcmp(s, s1) == 0){
            printf("%04d - %04d = 0000\n", n1, n);
            break;
        }
        ans = n1-n;
        printf("%04d - %04d = %04d\n", n1, n, ans);
        if(ans == 6174)
            break;
    }

    return 0;
}

/**

6767


7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
**/
