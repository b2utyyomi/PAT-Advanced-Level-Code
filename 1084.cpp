/**********************
author: yomi
date: 18.5.9
ps:
**********************/
#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
using namespace std;

int main()
{
    string s1, s2;
    bool vis[100];
    int cnt[100];
    memset(cnt, 0, sizeof(cnt));
    memset(vis, false, sizeof(vis));
    getline(cin, s1);
    getline(cin, s2);
    for(int i=0; i<s2.length(); i++){
        s2[i] = toupper(s2[i]);
        vis[s2[i]] = true;
    }
    for(int i=0; i<s1.length(); i++){
        s1[i] = toupper(s1[i]);
        if(vis[s1[i]] == false && cnt[s1[i]] == 0){
            cout << s1[i];
            cnt[s1[i]] = 1;
        }
    }
    return 0;
}
/**
7_This_is_a_test
_hs_s_a_es
*/
