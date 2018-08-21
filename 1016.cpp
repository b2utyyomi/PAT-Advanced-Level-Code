/**********************
author: yomi
date: 18.4.18
ps:
**********************/
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

struct fee1
{
    string na;
    string t;
    string d;
}f[1010], f_on[1010], f_off[1010];
int fee[24];/// = {10,10,10,10,10,10,20,20,20,15,15,15,15,15,15,15,20,30,20,15,15,10,10,10};

bool cmp(fee1 a, fee1 b)
{
    if(a.na !=b.na)
        return a.na < b.na;
    else
        return a.t < b.t;
}
int main()
{
    int n, cnt1=0, cnt2=0;
    for(int i=0; i<24; i++){
        cin >> fee[i];
    }
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> f[i].na >> f[i].t >> f[i].d;
        if(f[i].d == "on-line"){
            f_on[cnt1++] = f[i];
        }
        else{
            f_off[cnt2++] = f[i];
        }
    }
    sort(f_on, f_on+cnt1, cmp);
    sort(f_off, f_off+cnt2, cmp);
    int sum = 0;
    double total = 0;
    string temp = f_on[0].na;
    cout << temp << ' ' << f_on[0].t.substr(0, 2) << endl;
    for(int i=0, j=0; i<cnt1, j<cnt2;){
        //cout << f[i].na << f[i].t << f[i].d << endl;
        if(f_on[i].na == f_off[j].na){
            sum = 0;
            string mon_on = f_on[i].t.substr(0, 2);
            if(f_on[i].na != temp){
                cout << "Total: $" <<  total << endl;
                total = 0;
                cout << f_on[i].na << ' ' << mon_on << endl;
                temp = f_on[i].na;

            }
            string hh_on = f_on[i].t.substr(6, 2);
            string mm_on = f_on[i].t.substr(9, 2);
            istringstream is1, is2;
            is1.str(hh_on); is2.str(mm_on);
            int h_on, m_on;
            is1 >> h_on;
            is2 >> m_on;
            //cout << h << ' ' << m << endl;
            string hh_off = f_off[j].t.substr(6, 2);
            string mm_off = f_off[j].t.substr(9, 2);
            istringstream is3, is4;
            is3.str(hh_off); is4.str(mm_off);
            int h_off, m_off;
            is3 >> h_off;
            is4 >> m_off;
            int sum_on = h_on*60+m_on;
            int sum_off = h_off*60+m_off;
            sum += sum_off-sum_on;
            cout << f_on[i].t.substr(3, 8) << ' ' << f_off[j].t.substr(3, 8) << ' ';
            cout << sum << ' ';
            /// statistic
            /// hh
            double mon = fee[h_on]*(60-m_on);
            for(int tt=h_on+1; tt<=h_off-1; tt++){
                mon += fee[tt]*60;
            }
            mon += fee[h_off]*m_off;
            cout << "$" << mon/100 << endl;
            total += mon/100;
            i++;
            j++;
        }
        else{
            if(f_on[i].na == f_off[j+1].na && j+1<cnt2){
                j++;
            }
            else if(f_on[i+1].na == f_off[j].na && i+1 < cnt1){
                i++;
            }

        }

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
CYJJ 01:01:05:59 on-line
aaa 01:01:01:03 on-line
aaa 01:02:00:01 on-line
CYLL 01:28:15:41 on-line
aaa 01:05:02:24 on-line
aaa 01:04:23:59 off-line

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
