/**********************
author: yomi
date: 18.6.19
ps: ���������λ��û���һ������Ԫ��д���㷨���Ҹе�һ˿˿����
���磺
5
5 2 3 4 1
0 1 2 3 4

1 2 3 4 5
4 1 2 3 0
�޸�֮��
˼·��A1093, ������֮ǰɨ��Ľ����������ĺ�ʵ��
��Ȼ ���Ե�2��ʽ����
��������д�ĸ�ʽ����ȽϺ����� ������д��Ҳ����
���ϵĴ��������ķ�1093�������������
����AC
**********************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 100010;
int b[maxn], c[maxn];
bool flag[maxn];
int main()
{
    int n, cnt = 0, Min=0x7fffffff, Max = -2;
    memset(flag, true, sizeof(flag));
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%lld", &b[i]);
        if(Max > b[i]){
            flag[i] = false;
        }
        Max = max(b[i], Max);
    }
    for(int i=n-1; i>=0; i--){
        if(Min < b[i]){
            flag[i] = false;
        }
        Min = min(b[i], Min);
    }
    for(int i=0; i<n; i++){
        if(flag[i]){
            c[cnt++] = b[i];
        }
    }
    printf("%d\n", cnt);///�����ֵ�
    if(cnt){
        for(int i=0; i<cnt-1; i++){
            printf("%d ", c[i]);
        }
        printf("%d", c[cnt-1]);
    }
    else{
        printf("\n");
    }
    return 0;
}

/**
5
1 3 2 4 5
**/
