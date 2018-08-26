/**********************
author: yomi
date: 18.8.26
ps: �ڴ泬��22�� �޷����
**********************/
///ĤһĤ����Ĵ����Լ�����
/**
��⣺
1.�ϲ����򣬳�ʱ���ڴ棨�ᣩ
2.ά���������У��Ƚ϶�ͷ��С,ѭ������:ԭ�ȵĲ��Ե����ͨ���ģ�
�����°�PAT�����ڴ����ƣ����ڴ棨�ᣩ
3.��2�Ļ������Ż�����һ�����д�ú󣬰ѵڶ������б߶���
�ߺ͵�һ�����бȽϣ�ѡ����ӡ��������Բ���һ��
����ڶ������У�������ڴ�����⡣
˼·����һ���������зֱ���n, m��Ԫ�أ�
������Ҫ�Ӷ�ͷ�޳���n + m �C 1�� / 2��Ԫ�أ�
���𰸾���������ͷ����Сֵ���������մ��ڵ�һ
�ڶ��������е����Ҫ�ֿ����������ڵڶ��������У�
����������ʱ�Ϳ�����ǰ�ó��𰸲��˳��������ڵ�һ�������У�
Ҫ���γ��Ӳ����ҵ��𰸡�
ע�⣺������Ԫ���������Ϻ�
��INT_MAX����У�һ��������������Ϊ�գ����㴦��
���ǣ���Ŀ��long int��Ϊ�ڴ�����ԭ�򣬲�����Ϊ���մ𰸣�
ֻ�Ǹ������ݣ�����ÿ�����������ĸ������ݰ�����ΪINT_MAX���ɡ�
**/
#include <iostream>
#include <climits>
#include <queue>
using namespace std;
int main() {
    queue<int> a, b;
    long long tnum;
    int n, m, num, cnt = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%lld", &tnum);
        num = min((long long)INT_MAX, tnum);
        a.push(num);
    }
    a.push(INT_MAX);
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%lld", &tnum);
        int num = min((long long)INT_MAX, tnum);
        b.push(num);
        if(cnt == (n + m - 1) / 2) {
            printf("%d", min(a.front(), b.front()));
            return 0;
        }
        if(a.front() < b.front())
            a.pop();
        else
            b.pop();
        cnt++;
    }
    b.push(INT_MAX);
    for(; cnt < (n + m - 1) / 2; cnt++) {
        if(a.front() < b.front())
            a.pop();
        else
            b.pop();
    }
    printf("%d", min(a.front(), b.front()));
    return 0;
}
/**
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int ansn, ans, flag;
vector<int>a, b;
void merge_(int L1, int R1, int L2, int R2)
{
    int cnt = 1;
    int i=L1, j = L2;
    while(i<R1 && j<R2){
        if(a[i] <= b[j]){
            if(cnt == ansn){
                flag = 1;
                ans = a[i];
                break;
            }
            i++;
        }
        else{
            if(cnt == ansn){
                ans = b[j];
                flag = 1;
                break;
            }
            j++;
        }
        cnt++;
    }
    while(i<R1){
        if(cnt == ansn && !flag){
            ans = a[i];
            break;
        }
        cnt++;
        i++;
    }
    while(j<R2){
        if(cnt == ansn && !flag){
            ans = b[j];
            break;
        }
        cnt++;
        j++;
    }
}
int main()
{
    int n, m, aa, bb;
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d", &aa);
        a.push_back(aa);
    }
    scanf("%d", &m);
    for(int i=1; i<=m; i++){
        scanf("%d", &bb);
        b.push_back(bb);
    }
    ansn = (n+m+1)/2;
    //cout << ansn << endl;
    merge_(0, n, 0, m);
    printf("%d", ans);
    return 0;
}
**/
/**
Sample Input:
4 11 12 13 14
5 9 10 15 16 17
Sample Output:
13
**/
