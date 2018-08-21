/**********************
author: yomi
date: 18.2.25
ps:
**********************/
#include <iostream>
#include <algorithm>
using namespace std;
struct people
{
    string no;
    string in;
    string out;
}peo[10010];

int cmp1(people a, people b)
{
    return a.in<b.in;
}

int cmp2(people a, people b)
{
    return a.out>b.out;
}
int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> peo[i].no >> peo[i].in >> peo[i].out;
    }
    sort(peo, peo+n, cmp1);
    cout << peo[0].no << ' ';
    sort(peo, peo+n, cmp2);
    cout << peo[0].no;
    return 0;
}

/**
3
CS301111 15:30:28 17:00:10
SC3021234 08:00:00 11:25:25
CS301133 21:45:00 21:58:40

**/
