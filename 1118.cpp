/******************************
author:yomi
date:18.8.30
ps: from 1 to some number that is no more than 104. 我把我数组开到一百五十 两个段错误
改到10010就过了 所以题目这是写错了 不是104吧 这个并查集太裸了 非常好做啊 不到半小时就搞定
******************************/
#include<iostream>
using namespace std;
const int maxn = 10010;
int father[maxn+4];
int isRoot[maxn+4];
void init()
{
    for(int i=1; i<=maxn; i++){
        father[i] = i;
        isRoot[i] = 0;
    }
}
int findfather(int v)
{
    if(father[v] == v){
        return v;
    }
    else{
        int F = findfather(father[v]);
        father[v] = F;
        return F;
    }
}
void Union(int a, int b)
{
    int fa = findfather(a);
    int fb = findfather(b);
    if(fa!=fb){
        father[fa] = fb;
    }
}
int main()
{
    int T, t, qcnt, q1, q2, d, d1, max_=0;
    cin >> T;
    init();
    for(int i=0; i<T; i++){
        cin >> t;
        cin >> d;
        max_ = max(d, max_);
        for(int j=1; j<t; j++){
            cin >> d1;
            max_ = max(d1, max_);
            Union(d, d1);
        }
    }
    for(int i=1; i<=max_; i++){
        isRoot[findfather(i)]++;
    }
    int cnt = 0;
    for(int i=1; i<=max_; i++){
        if(isRoot[i]){
            cnt++;
        }
    }
    cout << cnt << ' ' << max_ << endl;
    cin >> qcnt;
    for(int i=0; i<qcnt; i++){
        cin >> q1 >> q2;
        //cout << father[q1] << ' ' << father[q2] << endl;
        if(father[q1] == father[q2])
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
/**
4
3 10 1 2
2 3 4
4 1 5 7 8
3 9 6 4
2
10 5
3 7

Sample Output:

2 10
Yes
No

**/
