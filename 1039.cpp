/**********************
author: yomi
date: 18.7.31
ps: �����˼��䱩���ķ�ʽ ÿ��ֻ��ͨ���������еĿ� ȥ�ж�������Ƿ�ѡ�����ſ�
��Ȼ��ʱ ��map ��Ȼ��ʱ �����map��С��鲻��ƽ�� �Ĳ��Ķ���23'
һ����� ��Ŷ �����ַ�����ϣ
���һ�������������
��ϣ��set��ʱ
��ϣ��sort��ʱ  �������sort���� ����string����
����� �������� �����ϱض�
**********************/
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cctype>
using namespace std;
const int maxn = 26*26*26*10+10;
vector<int>vec[maxn];
int hash_(char *s)
{
    int len=strlen(s);
    int id = 0;
    for(int i=0; i<len-1; i++){
        id = 26*id+(s[i]-'A');
    }
    id = 10*id+(s[len-1]-'0');
    return id;
}
int main()
{
    int n, k;
    //cin >> n >> k;
    scanf("%d%d", &n, &k);
    int m1, m2;
    char temp[10];
    for(int i=0; i<k; i++){
        //cin >> m1 >> m2;
        scanf("%d%d", &m1, &m2);
        for(int i=0; i<m2; i++){
            //cin >> s;
            scanf("%s", temp);
            int id = hash_(temp);
            vec[id].push_back(m1);
        }
    }

    for(int i=0; i<n; i++){
        scanf("%s", temp);
        printf("%s ", temp);
        int id = hash_(temp);
        printf("%d", vec[id].size());
        sort(vec[id].begin(), vec[id].end());
        for(int j=0; j<vec[id].size(); j++){
            printf(" %d", vec[id][j]);
        }
        if(i!=n-1)
            printf("\n");
    }
    return 0;
}
/**
11 5
4 7
BOB5 DON2 FRA8 JAY9 KAT3 LOR6 ZOE1
1 4
ANN0 BOB5 JAY9 LOR6
2 7
ANN0 BOB5 FRA8 JAY9 JOE4 KAT3 LOR6
3 1
BOB5
5 9
AMY7 ANN0 BOB5 DON2 FRA8 JAY9 KAT3 LOR6 ZOE1
ZOE1 ANN0 BOB5 JOE4 JAY9 FRA8 DON2 AMY7 KAT3 LOR6 NON9
**/
