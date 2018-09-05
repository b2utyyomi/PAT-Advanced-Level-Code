/******************************
author:yomi
date:18.9.4
ps: 起初最后两个点过不去 现在最后一个过不去
倒数第二个是因为排名没有计算好


无奈去看柳神的博客 唉 晴神的代码也不更新了
注意：总加权分数取整数部分是要对最后的总和取整数部分，不能每次都直接用int存储，不然会有一个3分测试点不通过～

都是低级错误 oh my gosh
我这次怕是不行了 过了九月八号专心初试吧
******************************/
#include<iostream>
#include <map>
#include <cctype>
#include <algorithm>
using namespace std;
const int maxn = 100010;
struct mark
{
    string ID;
    int stuNum;
    int total;
    double f;
    string na;
}stu[maxn], sch[maxn];
map<string, int>mmap;
int n,f;
string ID, na;
int cmp(mark a, mark b)
{
    if(a.total !=b.total){
        return a.total > b.total;
    }
    else if(a.stuNum!=b.stuNum){
        return a.stuNum < b.stuNum;
    }
    return a.na < b.na;
}
int toMap(string s)
{
    int si = mmap.size();
    if(mmap.find(s) == mmap.end()){
        mmap[s] = si;
        sch[si].stuNum++;
        if(ID[0] == 'T'){
            sch[si].f += f*1.5;
        }
        else if(ID[0] == 'A'){
            sch[si].f += f;
        }
        else if(ID[0] == 'B'){
            sch[si].f += f/1.5;
        }
        sch[si].total = (int)sch[si].f;
        sch[si].na = na;

        return si;
    }
    else{
        int id = mmap[s];
        if(ID[0] == 'T'){
            sch[id].f += f*1.5;
        }

        else if(ID[0] == 'A'){
            sch[id].f += f;
        }
        else if(ID[0] == 'B'){
            sch[id].f += f/1.5;
        }
        sch[id].total = (int)sch[id].f;
        sch[id].stuNum++;
        return mmap[s];
    }
}
int main()
{

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> ID >> f >> na;
        int len = na.length();
        for(int j=0; j<len; j++){
            na[j] = tolower(na[j]);
        }
        int id = toMap(na);
    }
    int msi = mmap.size();
    sort(sch, sch+msi, cmp);
    cout << msi << endl;
    int cnt = 1;
    cout << 1 << ' ';
    cout << sch[0].na << ' ' << sch[0].total << ' ' << sch[0].stuNum << endl;
    int last = cnt;
    cnt++;
    for(int i=1; i<msi; i++){
        //cout << stu[i-1].total << ' ' << stu[i].total << endl;
        if(sch[i].total !=sch[i-1].total){
            cout << cnt << ' ';
            last = cnt;

        }
        else{
            cout << last << ' ';
        }
        cout << sch[i].na << ' ' << sch[i].total << ' ' << sch[i].stuNum << endl;
        cnt++;
    }
     // cout << sch[msi-1].na << ' ' << sch[msi-1].total << ' ' << sch[msi-1].stuNum;
    return 0;
}
/**
Sample Input:

10
A57908 85 Au
B57908 54 LanX
A37487 60 au
T28374 67 CMU
T32486 24 hypu
A66734 92 cmu
B76378 71 AU
A47780 45 lanx
A72809 100 pku
A03274 45 hypu

Sample Output:

5
1 cmu 192 2
1 au 192 3
3 pku 100 1
4 hypu 81 2
4 lanx 81 2

**/
