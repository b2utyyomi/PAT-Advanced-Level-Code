/**********************
author: yomi
date: 18.7.
ps:
**********************/
#include <iostream>
#include <map>
#include <cstdio>
#include <cstring>
#include <string>
#include <cctype>
#include <sstream>
using namespace std;
string tendigit[12] = {"tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
string digit[13] = {"jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
int main()
{
    int T;
    map<string, int>mmap;
    mmap.clear();
    mmap["tret"] = 0;
    for(int i=1; i<13; i++){
        mmap[digit[i-1]] = i;
    }
    for(int i=1; i<13; i++){
        mmap[tendigit[i-1]] = i*13;
    }
    cin >> T;
    int f = T;
    //getchar();
    string s;
    int cnt = 0;
    while(T--){
        if(cnt == 0)
            getchar();
        cnt++;
        getline(cin, s);
        if(isdigit(s[0])){
            if(s.length() == 1 && s[0] == '0'){
                cout << "tret";
            }
            else{
                int n;
                stringstream is;
                is.str(s);
                is >> n;
                if(n<13){
                    cout << digit[n-1];
                }
                else{
                    if(n%13){
                        int t = n/13;
                        cout <<tendigit[t-1] << ' ';
                        cout << digit[n-13*t-1];
                    }
                    else if(13){
                        cout << tendigit[n/13-1];
                    }

                }
            }
        }
        else{
            stringstream is;
            is.str(s);
            string t;
            int ans = 0;
            while(is >> t){
                ans += mmap[t];
            }
            cout << ans;
        }
        if(cnt != f)
            cout << endl;

    }
    return 0;
}
/**
4
29
5
elo nov
tam
**/




