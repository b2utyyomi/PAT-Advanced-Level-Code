/**********************
author: yomi
date: 18.8.26
ps: ʹ��string�Ļ� ��ʱ�� �ڴ泬���� ��Щ����Ǻ����׳��ֵ� �Ҿ͵�������
40000��ѧ�� 2500�ſ� ���ÿ��ѧ����ѡ��2500�ſεĻ�
����ż���vector �����Ϳ��Ա��ⳬʱ���ڴ���

**********************/
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 2600;
vector<int>course[maxn];
char name[40010][5];

int cmp(int a, int b)
{
    return strcmp(name[a], name[b]) <0;
}
int main()
{
    int n, k, t, id;
    scanf("%d%d", &n, &k);
    for(int i=0; i<n; i++){
        scanf("%s", name[i]);
        scanf("%d", &t);
        for(int j=0; j<t; j++){
            //cin >> id;
            scanf("%d", &id);
            //cout << name << endl;
            int ch = name[i][3]-'0';
            course[id].push_back(i);
        }
    }
    for(int i=1; i<=k; i++){
        //cout << i << ' ' << course[i].size() << endl;
        printf("%d %d\n", i, course[i].size());
        sort(course[i].begin(), course[i].end(), cmp);
        for(int j=0; j<course[i].size(); j++){
            printf("%s\n", name[course[i][j]]);

        }

    }
    return 0;
}
/**
10 5
ZOE1 2 4 5
ANN0 3 5 2 1
BOB5 5 3 4 2 1 5
JOE4 1 2
JAY9 4 1 2 5 4
FRA8 3 4 2 5
DON2 2 4 5
AMY7 1 5
KAT3 3 5 4 2
LOR6 4 2 4 1 5
**/
