/**********************
author: yomi
date: 18.6.21
ps:
Each input file contains one test case which gives a positive integer N in the range (0, 10000).
���벻һ����4λ��Ŷ
������һ��sprintf��sscanf�ͳ��˺ܶ��鷳
���ò�˵ ������ĺܷ��㣬 Ҫ�����ϰ����
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
    while(1){ /// ��������д��ans!=6174 �����һ������ ���ǵ��߼���ʵ�ֶ�û������
        sprintf(s, "%04d", ans);///���ǵ��Ҿ��뵽�˱߽�����
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
