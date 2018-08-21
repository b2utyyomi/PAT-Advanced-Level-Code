/**********************
author: yomi
date: 18.7.28
ps:
**********************/
#include <iostream>
#include <string>
#include <cstring>
#include<cstdio>
#include <algorithm>
using namespace std;
char temp[1000];
int n;
string deal(string s, int &e)
{
    while(s.size()!=0 && s[0] == '0'){
        s.erase(s.begin());
    }
    string ans = "";
    int len = s.length();
    ///0.xxx    &&  xxx.xxx
    ///.xxx && xxx.xxx
    if(s[0] == '.'){
        int j = -1;
        for(int i=1; i<len; i++){
            if(s[i]!='0'){
                e = -i+1;
                j = i;
                break;
            }
        }
        if(j!=-1){
            while(j<len && (int)ans.length()<n){
                ans += s[j];
                j++;
            }
        }
        while(ans.length() < n){
            ans += '0';
        }
    }
    else{
        int pos = s.find('.');
        if(pos!=-1){
            e = pos;
        }
        else{
            e = len;
        }
        for(int i=0; i<len; i++){
            if(ans.length() == n){
                break;
            }
            if(s[i]!='.'){
                ans += s[i];
            }
        }
        //cout << ans.length() << ' ' << n << endl;
        int t = n-(int)ans.length();
        for(int i=0; i<t; i++){
            ans += '0';
        }
        //cout << t << endl;
    }
    return ans;

}
int main()
{
    //while(1){
    int e1=0, e2=0;
    string in1, in2;
    cin >> n >> in1>> in2;
    string s1 = deal(in1, e1);
    string s2 = deal(in2, e2);
    if(s1 == s2 && e1 == e2){
        cout << "YES 0." << s1 << "*10^" << e1 << endl;
    }
    else{
        cout << "NO 0." << s1 << "*10^" << e1 << " 0."<< s2 << "*10^" << e2 <<  endl;
    }

//}
    return 0;
}
/**
4 0000 0000.00  --->
NO 0.00*10^0 0.*10^0

3 12300 12358.9
YES 0.123*10^5
**/
