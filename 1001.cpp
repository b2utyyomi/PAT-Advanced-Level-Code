/**********************
author: yomi
date: 18.2.8
ps:
**********************/
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

void tos(long long int c)
{
    string s = "";
    while(c){
        s += (c%10)+'0';
        c /= 10;
    }
 /// 999,991
    string ss = "";
    reverse(s.begin(), s.end());
    for(int i=s.length()-1; i>=0; i--){
        if(i%3 == 2 && s.length()-i-1){
            ss = ss+",";
        }
        ss += s[s.length()-i-1];
    }
    cout << ss;
}
int main()
{
    long long int a, b, c;
    cin >> a >> b;
    c = a+b;
    if(c < 0)
        cout << "-";
    else if(c == 0)
        cout << "0";
    tos(abs(c));
    return 0;
}
