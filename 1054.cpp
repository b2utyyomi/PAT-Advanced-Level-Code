/**********************
author: yomi
date: 18.7.
ps:
**********************/
#include <iostream>
#include <cstdio>
#include <map>
using namespace std;


int main()
{
    int m, n;
    string h;
    char temp[20];
    map<string, int>mmap;
    scanf("%d%d", &m, &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%s", &temp);
            h = temp;
            mmap[h]++;
        }
    }
    string ans = "";
    int max_ = 0;
    for(map<string, int>::iterator iter=mmap.begin(); iter!=mmap.end(); ++iter){
        if(iter->second > max_){
            max_ = iter->second;
            ans = iter->first;
        }
    }
    cout << ans;
    return 0;
}
/**
5 3
0 0 255 16777215 24
24 24 0 0 24
24 0 24 24 24
**/
