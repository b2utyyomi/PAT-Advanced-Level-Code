/**********************
author: yomi
date: 18.8.24
ps: 我死了。。。
模拟题真心让我崩溃啊
一个小时做完了 一交全答案错误 改十分钟再交就8分
我弃疗了
树图刚刚给了我希望 模拟这盆冷水浇得真是棒棒哒
我得冷静一下
重新出发喽
看了题解 这个思路没差啊 注意点我自己也都发现了 那为什么我不对呢
下面让我们来荡起双桨 啊不 让我们来揭开代号为1017的精英特工的神秘面纱
行了 神经发完了
看题
抄题解了 T^T 我写的太不简洁了 垃圾桶里留做纪念吧
**********************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
    int come, time;
} tempcustomer;
bool cmp1(node a, node b) {
    return a.come < b.come;
}
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<node> custom;
    for(int i = 0; i < n; i++) {
        int hh, mm, ss, time;
        scanf("%d:%d:%d %d", &hh, &mm, &ss, &time);
        int cometime = hh * 3600 + mm * 60 + ss;
        if(cometime > 61200) continue;
        tempcustomer = {cometime, time * 60};
        custom.push_back(tempcustomer);
    }
    sort(custom.begin(), custom.end(), cmp1);
    vector<int> window(k, 28800);
    double result = 0.0;
    for(int i = 0; i < custom.size(); i++) {
        int tempindex = 0, minfinish = window[0];
        for(int j = 1; j < k; j++) {
            if(minfinish > window[j]) {
                minfinish = window[j];
                tempindex = j;
            }
        }
        if(window[tempindex] <= custom[i].come) {
            window[tempindex] = custom[i].come + custom[i].time;
        } else {
            result += (window[tempindex] - custom[i].come);
            window[tempindex] += custom[i].time;
        }
    }
    if(custom.size() == 0)
        printf("0.0");
    else
        printf("%.1f", result / 60.0 / custom.size());
    return 0;
}
/*
///8’
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <sstream>
#include <string>
using namespace std;
const int maxn = 10010;
struct people
{
    string t;
    int pr;
    int time;
}p[maxn];
int cmp(people a, people b)
{
    return a.time < b.time;
}
int main()
{
    int n, k, come, start1, h, m, s, start[110], total=0;
    char ch;
    for(int i=0; i<101; i++)
        start[i] = 8*3600;
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> p[i].t >> p[i].pr;
        string temp = p[i].t;
        if(temp > "17:00:00"){
            p[i].time = -1;
            continue;
        }

        stringstream is;
        is.str(temp);
        is >> h >> ch >> m >> ch >> s;
        p[i].time = h*3600+m*60+s;
        if(p[i].time < 8*3600){
            total += 8*3600-p[i].time;
            p[i].time = 8*3600;
        }
        if(p[i].pr > 60){
            p[i].pr = 60;
        }
    }
    sort(p, p+n, cmp);
    int cnt = 0, cnt1=0;
    while(cnt < n){
        sort(start, start+k);
        for(int i=0; i<k; i++){
            if(cnt >=n)
                break;
            if(p[cnt].time == -1){
                cnt++;
                cnt1++;
                continue;
            }
            if(start[i]>p[cnt].time){
                total += start[i]-p[cnt].time;
                start[i] += p[cnt].pr*60;
            }
            else{
                start[i] = p[cnt].time+p[cnt].pr*60;
            }
            cnt++;
        }
    }
    if(n-cnt1 <=0)
        printf("0.0");
    else{
        double ans = total*1.0/(n-cnt1)/60;
        printf("%.1f", ans);

    }
    return 0;
}
*/
/**
7 3
07:55:00 16
17:00:01 2
07:59:59 15
08:01:00 60
08:00:00 30
08:00:02 2
08:03:00 10
**/



