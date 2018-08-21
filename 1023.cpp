/**********************
author: yomi
date: 18.7.29
ps:
**********************/
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
int cnt2[10];
struct bign
{
    int num[50];
    int len;
    bign()
    {
        memset(num, 0, sizeof(num));
        len = 0;
    }
}b, ans;
void add()
{
    int cnt = 0;
    int carry = 0;
    for(int i=0; i<b.len; i++){
        int tmp = 0;
        tmp = b.num[i]+b.num[i]+carry;
        ans.num[cnt++] = tmp%10;
        cnt2[tmp%10]++;
        carry = tmp/10;
    }
    if(carry){
        ans.num[cnt++] = carry;
        cnt2[carry]++;
    }
    ans.len = cnt;
}
int main()
{
    string s;
    cin >> s;
    int cnt1[10];
    memset(cnt1, 0, sizeof(cnt1));
    memset(cnt2, 0, sizeof(cnt2));
    int len = s.length();
    b.len = len;
    for(int i=0; i<len; i++){
        int t = s[i]-'0';
        b.num[len-i-1] = t;
        cnt1[t]++;
    }
    add();
    int j = 0;
    for(j = 0; j<9; j++){
        if(cnt1[j]!=cnt2[j]){
            break;
        }
    }
    if(j == 9){
        cout << "Yes" << endl;
    }
    else
        cout << "No" << endl;
    for(int i=ans.len-1; i>=0; i--){
        cout << ans.num[i];
    }

    return 0;
}


