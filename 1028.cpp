/**********************
author: yomi
date: 18.5.2
cin, cout超时 改为scanf就过了 像这种大输入 记住了 再也不要用cin了
考场上可没有时间可以浪费啊
ps:
 if C = 1 then the records must be sorted in increasing order according to ID's;
  if C = 2 then the records must be sorted in non-decreasing order according to names;
  and if C = 3 then the records must be sorted in non-decreasing order according to
  grades. If there are several students who have the same name
    or grade, they must be sorted according to their ID's in increasing order.
**********************/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
struct people
{
    char id[10];
    char na[10];
    int fen;
}peo[100010];
int cmp1(people a, people b)
{
    return strcmp(a.id,b.id)< 0;
}
int cmp2(people a, people b)
{
    if(strcmp(a.na ,b.na)!=0)
        return strcmp(a.na ,b.na) < 0;
    else
        return strcmp(a.id,b.id)< 0;
}
int cmp3(people a, people b)
{
    if(a.fen!=b.fen)
        return a.fen < b.fen;
    else
        return strcmp(a.id,b.id)< 0;
}

int main()
{
    int n, c;
    //cin >> n >> c;
    scanf("%d%d", &n, &c);
    for(int i=0; i<n; i++){
        //cin >> peo[i].id >> peo[i].na >> peo[i].fen;
        scanf("%s%s%d", peo[i].id, peo[i].na, &peo[i].fen);
    }
    if(c == 1)
        sort(peo, peo+n, cmp1);
    else if(c == 2)
        sort(peo, peo+n, cmp2);
    else if(c == 3)
        sort(peo, peo+n, cmp3);
    for(int i=0; i<n; i++){
        printf("%s %s %d\n", peo[i].id, peo[i].na, peo[i].fen);
    }
    return 0;
}
/**
Sample Input 1
3 1
000007 James 85
000010 Amy 90
000001 Zoe 60
Sample Output 1
000001 Zoe 60
000007 James 85
000010 Amy 90
Sample Input 2
4 2
000007 James 85
000010 Amy 90
000001 Zoe 60
000002 James 98
Sample Output 2
000010 Amy 90
000002 James 98
000007 James 85
000001 Zoe 60
Sample Input 3
4 3
000007 James 85
000010 Amy 90
000001 Zoe 60
000002 James 90
Sample Output 3
000001 Zoe 60
000007 James 85
000002 James 90
000010 Amy 90
**/
