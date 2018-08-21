/**********************
author: yomi
date: 18.8.10
ps:代码十分钟拿下 找bug找了二十分钟 自己写的bug 跪着也要找出来
**********************/
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <cctype>
using namespace std;

int main()
{
    string s, word = "";
    map<string, int>mmap;
    mmap.clear();
    getline(cin, s);       // 01234
    int pos = -1, cnt = 0;
    for(int i=0; i<s.length(); i++){
        if(!isdigit(s[i]) && !isalpha(s[i])){
            if(word!=""){
                mmap[word]++;
            }
            word = "";
        }
        else{
            s[i] = tolower(s[i]);
            word+=s[i];
        }
        //cout << word << endl;
    }
    if(word!=""){///bug
        mmap[word]++;
    }
    map<string, int>::iterator iter;
    int maxC = 0;
    string ans;
    for(iter=mmap.begin(); iter!=mmap.end(); iter++){
        if(iter->second > maxC){
            maxC = iter->second;
            ans = iter->first;
        }
        //cout << iter->first << ' ' << iter->second << endl;
    }
    cout << ans << ' ' << maxC;
    return 0;
}
/**
Can1: "Can a can can a can?  It can!"
**/






