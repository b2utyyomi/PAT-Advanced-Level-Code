/**********************
author: yomi
date: 18.5.31
ps:
**********************/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct station
{
    double price;
    double distance;
}s[30010];
int cmp(station a, station b)
{
    return a.distance < b.distance;
}
int main()
{
    double maxc, d, p;
    int m;
    double ans = 0.0;
    scanf("%lf%lf%lf%d", &maxc, &d, &p, &m);
    for(int i=0; i<m; i++){
        scanf("%lf%lf", &s[i].price, &s[i].distance);
    }
    sort(s, s+m, cmp);
//    for(int i=0; i<m; i++){
//        cout << s[i].price << ' ' << s[i].distance << endl;
//    }
    s[m].price = 0.00;
    s[m].distance = d;
    if(s[0].distance != 0){
        printf("The maximum travel distance = 0.00");
    }
    else{
        int now = 0,k = -1;
        double nowtank = 0;
        while(now<m){
            k = -1;
            //double cheap = s[now].price;
            double cheap = 10000.0;
            for(int i=now+1; i<=m; i++){
                if(s[i].distance-s[now].distance > maxc*p*1.0){
                    break;
                }
                if(s[i].price < cheap){
                    k = i;
                    cheap = s[i].price;
                    if(s[i].price < s[now].price){
                        break;
                    }
                }


            }
            if(k == -1)
                break;
            double need = (s[k].distance-s[now].distance)/p;
            if(s[now].price<=cheap){
                //ans += cheap*(maxc-nowtank);
                ans += s[now].price*(maxc-nowtank);
                nowtank = maxc-need;
            }
            else{
                if(need > nowtank){
                    ans += (need-nowtank)*s[now].price;
                    nowtank = 0;
                }
                else{
                    nowtank -= need;
                }
            }
            now = k;
        }
        if(now != m){
            double last = maxc*p*1.0;/// nowtank*p???
            printf("The maximum travel distance = %.2f", s[now].distance+last);
        }
        else{
            printf("%.2f", ans);
        }
    }
    return 0;
}
/**
50 1300 12 8
6.00 1250
7.00 600
7.00 150
7.10 0
7.20 200
7.50 400
7.30 1000
6.85 300
**/
