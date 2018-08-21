/**********************
author: yomi
date: 18.7.17
ps:
**********************/
#include <iostream>
#include <algorithm>
using namespace std;

struct stu
{
    int id;
    int grade[4];
}s[2010];
int Rank[10000010][4];
int now=0;
char course[4] = {'A', 'C', 'M', 'E'};
int cmp(stu a, stu b)
{
    return a.grade[now] > b.grade[now];
}
int main()
{
    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> s[i].id;
        for(int j=1; j<4; j++){
            cin >> s[i].grade[j];
            s[i].grade[0] += s[i].grade[j];
        }
    }
    for(now=0; now<4; now++){
        sort(s,s+n,cmp);
        int id = s[0].id;
        Rank[id][now] = 1;
        for(int i=1; i<n; i++){
            id = s[i].id;
            if(s[i].grade[now] == s[i-1].grade[now]){
                Rank[id][now] = Rank[s[i-1].id][now];
            }
            else{
                Rank[id][now] = i+1;
            }
            //cout << Rank[id][now] << endl;
        }
    }

    int id;
    for(int i=0; i<m; i++){
        cin >> id;
        int flag = 1;
        for(int j=0; j<n; j++){
            if(id == s[j].id){
                flag = 0;
                int Min = 10000, te;
                for(int t=0; t<4; t++){
                    if(Rank[id][t] < Min){
                        Min = Rank[id][t];
                        te = t;
                    }
                }
                cout << Min << ' ' << course[te] << endl;

            }
        }
        if(flag)
            cout << "N/A" << endl;

    }
    return 0;
}
/**
5 6
310101 98 85 88
310102 70 95 88
310103 82 87 84
310104 91 91 91
310105 85 90 90
310101
310102
310103
310104
310105
999999
**/
