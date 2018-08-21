/**********************
author: yomi
date: 18.5.1
ps: 段错误第一次 第二次成交
**********************/
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
struct mark
{
    string no;
    int f;
}m1[30010], m3[30010];
int cmp(mark a, mark b)
{
    if(a.f!=b.f)
        return a.f > b.f;
    else
        return a.no<b.no;
}
int main()
{
    map<string, int>f_rank, l_num, l_rank;
    int T, n;
    cin >> T;
    int cnt = 0;
    for(int j=1; j<=T; j++){
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> m1[i].no >> m1[i].f;
            l_num[m1[i].no] = j;
            m3[cnt++] = m1[i];
        }
        sort(m1, m1+n, cmp);
        l_rank[m1[0].no] = 1;
        for(int i=1; i<n; i++){
            if(m1[i-1].f == m1[i].f){
                l_rank[m1[i].no] = l_rank[m1[i-1].no];
            }
            else{
                l_rank[m1[i].no] = i+1;
            }
        }
    }
    sort(m3, m3+cnt, cmp);
    cout << cnt << endl;
    cout << m3[0].no << ' ' << "1" << ' ' << l_num[m3[0].no] << ' '
        << l_rank[m3[0].no] << endl;
    int tmp = 1;
    for(int i=1; i<cnt; i++){
        if(m3[i].f!=m3[i-1].f){
            cout << m3[i].no << ' ' << i+1 << ' ' << l_num[m3[i].no] << ' '
        << l_rank[m3[i].no] << endl;
            tmp = i+1;
        }
        else{
            cout << m3[i].no << ' ' << tmp << ' ' << l_num[m3[i].no] << ' '
        << l_rank[m3[i].no] << endl;
        }


    }
    return 0;
}

/**
2
5
1234567890001 95
1234567890005 100
1234567890003 95
1234567890002 77
1234567890004 85
4
1234567890013 65
1234567890011 25
1234567890014 100
1234567890012 85
*/
