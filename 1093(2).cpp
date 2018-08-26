/**********************
author: yomi
date: 18.8.26
ps: 三刷了 当初想得脑壳疼 现在十分钟搞定
能这么快也是与当初做过有关啊
**********************/
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
    long long int cnt_p=0, cnt_at=0, cnt_pat=0;
    string s;
    cin >> s;
    for(int i=0; i<s.length(); i++){
        if(s[i] == 'P'){
            cnt_p = (cnt_p+1)%1000000007;
        }
        else if(s[i] == 'A' && cnt_p){
            cnt_at = (cnt_p+cnt_at)%1000000007;
        }
        else if(s[i] == 'T' && cnt_at){
            cnt_pat = (cnt_pat+cnt_at)%1000000007;
        }
    }
    printf("%lld", cnt_pat%1000000007);
    return 0;
}
/**
Sample Input:
APAPAPT
Sample Output:
2
**/
