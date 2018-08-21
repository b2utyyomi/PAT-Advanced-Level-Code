/**********************
author: yomi
date: 18.3.26
ps:
**********************/
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

struct game
{
    char ch;
    double pro;
}g[10];
int cmp(game a, game b)
{
    return a.pro<b.pro;
}
int main()
{
    for(int i=0; i<9; i++){
        if((i+1)%3 == 1){
            g[i].ch = 'W';
        }
        else if((i+1)%3 == 2){
            g[i].ch = 'T';
        }
        else if((i+1)%3 == 0){
            g[i].ch = 'L';
        }
        cin >> g[i].pro;
    }
    for(int i=0; i<9; i+=3){
        sort(g+i, g+i+3, cmp);
    }

    for(int i=2; i<9; i+=3){
        cout << g[i].ch << ' ';
    }

    double sum = (g[2].pro*g[5].pro*g[8].pro*0.65-1)*2;
    printf("%.2f", sum);
    return 0;
}

/**
1.1 3.0 1.7
1.2 1.6 2.5
4.1 1.2 1.1
**/
