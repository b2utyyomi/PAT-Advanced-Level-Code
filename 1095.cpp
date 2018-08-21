/**********************
author: yomi
date: 18.5.6
ps:很悲伤的故事 我一直纳闷为什么JH007BD能输出？原来算的是总时间呀
JH007BD 7:13:9
JH007BD 0:7:0
**********************/
#include <iostream>
#include<cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
struct car
{
    char no[10];
//    int h;
//    int m;
//    int s;
    int t;
    char q[10];
    //bool flag;
}c[10010], real[10010];
bool cmp(car a, car b)
{
    if(strcmp(a.no, b.no)!=0)
        return strcmp(a.no, b.no)<0;
   // else if(a.t!=b.t) 测试点2错误
    return a.t < b.t;

}
bool cmp1(car a, car b)
{
   // if(a.t!=b.t)
    return a.t < b.t;
}

int main()
{
    int n, t, lh=-1, lm=-1, ls=-1, longtim = -1;
    map<string, int>longtime;
    longtime.clear();
    scanf("%d%d", &n, &t);
    for(int i=0; i<n; i++){
        int h, m, s;
        scanf("%s%d:%d:%d%s", c[i].no, &h, &m , &s, c[i].q);
        c[i].t = s+m*60+h*3600;

    }
    sort(c, c+n, cmp);
    int j = 0;
    int cnt = 0;
    while(j<n){
        if(strcmp(c[j].q, "in") == 0)
        break;
        j++;
    }
    int cnt2 = 0;
    while(j<n){
        if(strcmp(c[j].no, c[j-1].no) == 0 && strcmp(c[j].q, "out") == 0&&strcmp(c[j-1].q, "in") == 0){
//            c[j-1].flag = true;
//            c[j].flag = true;
            real[cnt++] = c[j-1];
            real[cnt++] = c[j];
            int h1,h2, m1, m2, s1, s2;
            s1 = real[cnt-2].t;s2=real[cnt-1].t;
            int time = s2-s1;
            string s = real[cnt-1].no;
//            if(longtime.count(s) == 0){
//                longtime[s] = 0;
//            }
            longtime[s] += time;
            if(longtim<longtime[s]){
                longtim = longtime[s];
            }

        }
        j++;
    }

    int th, tm, ts;
    sort(real, real+cnt, cmp1);
    j = 0;
    int ans = 0;
    for(int i=0; i<t; i++){
        scanf("%d:%d:%d", &th, &tm, &ts);
//
        int thms = th*3600+tm*60+ts;
        while(j<cnt){
            if(real[j].t > thms){
                //j--;
                break;
            }

            if(strcmp(real[j].q, "in") == 0)
                ans++;
            else if(strcmp(real[j].q, "out") == 0)
                ans--;
            j++;
        }
        printf("%d\n", ans);
    }
    //cout << "1" << endl; TLE
//    for(map<string, int>::iterator iter=longtime.begin(); iter!=longtime.end(); ++iter){
//        int time = iter->second;
//        //cout << iter->first << ' ' << iter->second << endl;
//        if(time > longtim){
//            ls = time%60;
//            lh = time/3600;
//            lm = (time-ls-lh*3600)/60;
//            longtim = time;
//
//        }
//        //printf("%d:%d:%d\n", lh, lm, ls);
//    }
    //cout << "2" << endl;

    for(map<string, int>::iterator iter=longtime.begin(); iter!=longtime.end(); ++iter){
        if(iter->second == longtim){
            const char *p = iter->first.c_str();
            printf("%s ", p);
        }

    }
    ls = longtim%60;
    lh = longtim/3600;
    lm = (longtim-ls-lh*3600)/60;
    printf("%02d:%02d:%02d\n", lh, lm, ls);
    return 0;
}
/**
16 7
JH007BD 18:00:01 in
ZD00001 11:30:08 out
DB8888A 13:00:00 out
ZA3Q625 23:59:50 out
ZA133CH 10:23:00 in
ZD00001 04:09:59 in
JH007BD 05:09:59 in
ZA3Q625 11:42:01 out
JH007BD 05:10:33 in
ZA3Q625 06:30:50 in
JH007BD 12:23:42 out
ZA3Q625 23:55:00 in
JH007BD 12:24:23 out
ZA133CH 17:11:22 out
JH007BD 18:07:01 out
DB8888A 06:30:50 in
05:10:00
06:30:50
11:00:00
12:23:42
14:00:00
18:00:00
23:59:00
**/
