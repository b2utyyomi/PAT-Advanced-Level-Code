/**********************
author: yomi
date: 18.5.10
ps:
**********************/
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    string s1, s2;
    bool vis[256];
    memset(vis, false, sizeof(vis));
    getline(cin, s1);
    getline(cin, s2);
    for(int i=0; i<s2.length(); i++){
        vis[s2[i]] = true;
    }
    for(int i=0; i<s1.length(); i++){
        if(!vis[s1[i]])
            cout << s1[i];
    }
    return 0;
}
/**
They are students.
aeiou

Thy r stdnts.
**/
