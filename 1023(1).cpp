/**********************
author: yomi
date: 18.8.23
ps:练手速 用小水题弥补我刚刚受到的心灵创伤
**********************/
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
const int maxn = 50;
struct number
{
    int len;
    int d[maxn];
    number()
    {
        memset(d, 0, sizeof(d));
        len = 0;
    }
}a, b, c;
string s;
int cnt[15], cnt2[15];
bool ok()
{
    for(int i=s.length()-1; i>=0; i--){
        a.d[a.len++] = s[i]-'0';
    }
    int carry = 0;
    for(int i=0; i<a.len; i++){
        cnt2[a.d[i]]++;
        int temp = carry+a.d[i]+a.d[i];
        carry = temp/10;
        c.d[c.len++] = temp%10;
        cnt[temp%10]++;
    }
    while(carry){
        c.d[c.len++] = carry%10;
        cnt[carry%10]++;
        carry/=10;
    }
    for(int i=0; i<10; i++){
        if(cnt[i]!=cnt2[i]){
            return false;
        }
    }
    return true;
}
int main()
{
    cin >> s;
    if(ok())
    {
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    for(int i=c.len-1; i>=0; i--){
        cout << c.d[i];
    }
    return 0;
}
/**
Sample Input:
1234567899
Sample Output:
Yes
2469135798
**/
