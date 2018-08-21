/**********************
author: yomi
date: 18.2.24
ps: 这种题遇见的很多了， 但是却经常忘记0这种情况 记住了哈
**********************/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string num[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
int main()
{
    string s;
    cin >> s;
    int sum = 0;
    int flag = 0;
    for(int i=0; i<s.length();i++){
        sum += (s[i]-'0');
    }
    s = "";
    while(sum){
        s += sum%10+'0';
        sum /= 10;
    }
    reverse(s.begin(), s.end());
    int cnt = 0;
    for(int i=0; i<s.length(); i++){
        if(cnt)
            cout << ' ';
        cout << num[s[i]-'0'];
        flag = 1;
        cnt++;
    }
    if(flag == 0)
        cout << "zero";
    return 0;
}
