/**********************
author: yomi
date: 18.5.4
ps:
**********************/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct people
{
    string na;
    string id;
    int fen;
}peo[100010];
int cmp(people a, people b)
{
    return a.fen > b.fen;
}
int main()
{
    int n, a, b;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> peo[i].na >> peo[i].id >> peo[i].fen;
    }
    sort(peo, peo+n, cmp);
    cin >> a >> b;
    int flag = 1;
    for(int i=0; i<n; i++){
        if(peo[i].fen >=a && peo[i].fen<=b){
            cout << peo[i].na << ' ' << peo[i].id << endl;
            flag = 0;
        }
    }
    if(flag)
        cout << "NONE";
    return 0;
}

/**
4
Tom CS000001 59
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95
60 100
**/
