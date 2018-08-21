/**********************
author: yomi
date: 18.5.9
ps:
**********************/
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
    int cnt1[256], cnt2[256];
    memset(cnt1, 0, sizeof(cnt1));
    memset(cnt2, 0, sizeof(cnt2));
    string s1, s2;
    cin >> s1 >> s2;
    for(int i=0; i<s1.length(); i++){
        cnt1[s1[i]]++;
    }
    for(int i=0; i<s2.length(); i++){
        cnt2[s2[i]]++;
    }
    int len = 0;
    for(int i=0; i<256; i++){
        int t = 0;
        t = min(cnt1[i], cnt2[i]);
        len += t;
    }
    if(len == s2.length()){
        cout << "Yes" << ' ' << s1.length()-s2.length();
    }
    else{
        cout << "No" << ' ' << s2.length()-len;
    }
    return 0;
}
/**
ppRYYGrrYBR2258
YrR8RrY
**/
