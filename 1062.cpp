/**********************
author: yomi
date: 18.4.24
ps:注意到10^5， 数据太大了， 用cin，会超时的
**********************/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

struct student{
    int de;
    int cai;
    char no[9];///开大一点喽 不然会自动加上截断字符的 答案就不对了
}a[100010], b[100010], c[100010], d[100010];
bool cmp(student a, student b)
{
    if((a.de+a.cai) != (b.de+b.cai))
        return (a.de+a.cai) > (b.de+b.cai);
    else if(a.de!=b.de){
        return a.de > b.de;
    }
    else
        return strcmp(a.no, b.no) < 0;
}
int main()
{
    int n, h, l, vir, tal;
    scanf("%d%d%d",&n, &l, &h);
    char s[9];
    int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
    for(int i=0; i<n; i++){
        //cin >> s >> vir >> tal;
        scanf("%s%d%d", s, &vir, &tal);
        if(vir >= h && tal >= h){
            strcpy(a[cnt1].no, s);
           // a[cnt1].no
            a[cnt1].de = vir;
            a[cnt1++].cai = tal;
        }
        else if(vir >=h && tal < h && tal >= l){
            strcpy(b[cnt2].no, s);
            b[cnt2].de = vir;
            b[cnt2++].cai = tal;
        }
        else if(vir >= tal && vir < h && tal<h && vir >= l && tal >= l){
            strcpy(c[cnt3].no, s);
            c[cnt3].de = vir;
            c[cnt3++].cai = tal;
        }
        else if(vir >= l && tal >= l){
            strcpy(d[cnt4].no, s);
            d[cnt4].de = vir;
            d[cnt4++].cai = tal;
        }
    }
    sort(a, a+cnt1, cmp);
    sort(b, b+cnt2, cmp);
    sort(c, c+cnt3, cmp);
    sort(d, d+cnt4, cmp);
    //cout << cnt1+cnt2+cnt3+cnt4 << endl;
    printf("%d\n", cnt1+cnt2+cnt3+cnt4);
    for(int i=0; i<cnt1; i++){
        //cout << a[i].no << ' ' << a[i].de << ' ' << a[i].cai << endl;
        printf("%s %d %d\n", a[i].no, a[i].de, a[i].cai);
    }
    //cout << endl;
    for(int i=0; i<cnt2; i++){
        //cout << b[i].no << ' ' << b[i].de << ' ' << b[i].cai << endl;
        printf("%s %d %d\n", b[i].no, b[i].de, b[i].cai);
    }
   // cout << endl;
    for(int i=0; i<cnt3; i++){
        //cout << c[i].no << ' ' << c[i].de << ' ' << c[i].cai << endl;
        printf("%s %d %d\n", c[i].no, c[i].de, c[i].cai);
    }
    //cout << endl;
    for(int i=0; i<cnt4; i++){
        //cout << d[i].no << ' ' << d[i].de << ' ' << d[i].cai << endl;
        printf("%s %d %d\n", d[i].no, d[i].de, d[i].cai);
    }

    return 0;
}
/**
14 60 80
10000001 64 90
10000002 90 60
10000011 85 80
10000003 85 80
10000004 80 85
10000005 82 77
10000006 83 76
10000007 90 78
10000008 75 79
10000009 59 90
10000010 88 45
10000012 80 100
10000013 90 99
10000014 66 60

12
10000013 90 99
10000012 80 100
10000003 85 80
10000011 85 80
10000004 80 85
10000007 90 78
10000006 83 76
10000005 82 77
10000002 90 60
10000014 66 60
10000008 75 79
10000001 64 90
**/
