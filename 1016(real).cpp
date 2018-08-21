/**********************
author: yomi
date: 18.4.19
ps: 从开始做 到 AC 用了一周多的时间 就问还有谁
我不会放弃我自己 永远不会 做的慢也比不做强
**********************/
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstdio>
using namespace std;
struct fee1
{
    string na;
    string t;
    string d;
}f[1010];
int fee[24];
bool cmp(fee1 a, fee1 b)
{
    if(a.na != b.na){
        return a.na < b.na;
    }
    else
        return a.t < b.t;
}
int main()
{
    for(int i=0; i<24; i++){
        cin >> fee[i];
    }
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> f[i].na >> f[i].t >> f[i].d;
    }
    sort(f, f+n, cmp);
//    for(int i=0; i<n; i++){
//        cout << f[i].na << ' ' << f[i].t << ' ' << f[i].d << endl;
//    }
    double total = 0, once;
    int flag = 1;
    string tmp = f[0].na;
    for(int i=0; i<n; i++){
        once = 0;
        if(i+1 < n && f[i].na == f[i+1].na && f[i].d == "on-line" && f[i+1].d == "off-line"){
            //00:07:00 01:07:00 1440 $213.00
            istringstream  is1, is2, is3, is4, is5, is6;
            is1.str(f[i].t.substr(3, 2));
            is2.str(f[i].t.substr(6, 2));
            is3.str(f[i].t.substr(9, 2));
            int day1, hour1, minute1, day2, hour2, minute2;
            is1 >> day1;
            is2 >> hour1;
            is3 >> minute1;
            is4.str(f[i+1].t.substr(3, 2));
            is5.str(f[i+1].t.substr(6, 2));
            is6.str(f[i+1].t.substr(9, 2));
            is4 >> day2;
            is5 >> hour2;
            is6 >> minute2;
            int time = 0;
            while(day1 < day2 || hour1 < hour2 || minute1 < minute2){
                time++;
                minute1++;
                once += fee[hour1];
                if(minute1 == 60){
                    hour1++;
                    minute1 = 0;
                }
                if(hour1 == 24){
                    day1++;
                    hour1 = 0;
                }
            }
            string month = f[i].t.substr(0, 2);
            if(flag){
               cout << f[i].na << ' ' << month << endl;
               tmp = f[i].na;
            }
            if(tmp!=f[i].na && total){
                cout << "Total amount: $";
                printf("%.2f\n", total/100);
                total = 0;
                cout << f[i].na << ' ' << month << endl;
                tmp = f[i].na;
            }

            cout << f[i].t.substr(3, 8) << ' ' << f[i+1].t.substr(3, 8) << ' ' << time << ' ' <<"$";
            total += once;
            printf("%.2f\n", once/100);
            flag = 0;
            i++;
        }
        else if(total && flag == 0 && f[i].na != tmp){
           cout << "Total amount: $";
           printf("%.2f\n", total/100);
           total = 0;
           flag = 1;
        }

    }
    if(total){
       cout << "Total amount: $";
       printf("%.2f\n", total/100);
       total = 0;
       flag = 1;
    }
    return 0;
}
/**
For each test case, all dates will be within a single month.

Each "on-line" record is paired with the chronologically next record
for the same customer provided it is an "off-line" record.
Any "on-line" records that are not paired with an "off-line" record are ignored,
as are "off-line" records not paired with an "on-line" record.

It is guaranteed that at least one call is well paired in the input.
You may assume that no two records for the same customer have the same time.
Times are recorded using a 24-hour clock.
**/
/**
10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
10
CYLL 01:01:06:01 on-line
CYLL 01:28:16:05 off-line
CYJJ 01:01:07:00 off-line
CYLL 01:01:08:03 off-line
CYJJ 01:00:07:00 on-line
aaa 01:01:01:03 on-line
aaa 01:02:23:59 on-line
CYLL 01:28:15:41 on-line
aaa 01:05:02:24 on-line
aaa 01:04:01:00 off-line

10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
5
aaa 01:01:01:03 on-line
aaa 01:02:00:01 on-line
CYLL 01:28:15:41 on-line
aaa 01:05:02:24 off-line
aaa 01:04:23:59 off-line

10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
10
CYLL 01:01:06:01 on-line
CYLL 01:28:16:05 off-line
CYJJ 01:01:07:00 off-line
CYLL 01:01:08:03 off-line
CYJJ 01:01:05:59 on-line
aaa 01:01:01:03 on-line
aaa 01:02:00:01 on-line
CYLL 01:28:15:41 on-line
aaa 01:05:02:24 on-line
aaa 01:04:23:59 off-line


CYJJ 01
00:07:00 01:07:00 1440 $213.00
Total amount: $213.00
CYLL 01
01:06:01 01:08:03 122 $24.40
28:15:41 28:16:05 24 $3.85
Total amount: $28.25
aaa 01
02:23:59 04:01:00 1501 $219.10
Total amount: $219.10

CYJJ 01
01:05:59 01:07:00 61 $12.10
Total amount: $12.10
CYLL 01
01:06:01 01:08:03 122 $24.40
28:15:41 28:16:05 24 $3.85
Total amount: $28.25
aaa 01
02:00:01 04:23:59 4318 $638.80
Total amount: $638.80
**/

