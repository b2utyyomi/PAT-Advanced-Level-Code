/**********************
author: yomi
date: 18.8.29
ps: 我的心拔凉拔凉的 30分的题也没做这么久过 最后一测试点有点坑吧
1000.这也是合法的 好吧 是我见识太少 其实乙级我做过这道题 但是我给忘了
字符串这种题 题目要是描述不清楚 那我就凉了 凉的透透的
另外每天看着群里大佬在那里显摆自己的进度与水平 我真的是觉得自己
心有余而力不足 这么个小题就要写这么久 我是一只在努力 但是人家就是比我快
算了 踏踏实实走好每一步吧
啊 我的心情就像外面乌云密布的天气 但是脸上却洋溢着幸福的表情
AC之后的笑容 心情复杂 赶紧滚去做数学题
**********************/
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstdio>
#include <sstream>
using namespace std;
double ans, num, sum;
bool isOK(string s)
{
    int cnt1 = 0, pos = -1;
    if(s.length() == 0)
        return false;
    for(int i=0; i<s.length(); i++){
        if(!isdigit(s[i]) && s[i]!='.'){
            return false;
        }
        if(s[i] == '.'){
            cnt1++;
            pos = i;
        }
    }
    if(cnt1>1){
        return false;
    }
    ///012345
    ///123.12
    ///123.
    if(cnt1 == 0 || pos==s.length()-1){
        stringstream is;
        is.str(s);
        is >> num;
        if(num>1000)
            return false;
    }
    else if(cnt1==1){
        if(s.length()-1-pos>2){
            return false;
        }
        stringstream is;
        is.str(s);
        is >> num;
        if(num>1000)
            return false;
    }
    return true;
}
int main()
{
    int n;
    int cnt = 0, flag = 0;
    string s, str;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> s;
        str = s;

        flag = 0;
        if(s[0] == '-'){
            s = s.substr(1, s.length()-1);

            flag = 1;
        }
        //cout << s << endl;
        if(isOK(s)){
            if(flag == 1){
                num = -num;
            }

            sum += num;
            cnt++;
        }
        else{
            //printf("ERROR:  is not a legal number", s);
            cout << "ERROR: " << str << " is not a legal number" << endl;
        }
    }
    if(cnt>=1){
        ans = sum/cnt;
        if(cnt == 1){
            printf("The average of 1 number is %.2f", ans);
        }
        else{
            printf("The average of %d numbers is %.2f", cnt, ans);
        }
    }
    else if(cnt==0){
        printf("The average of 0 numbers is Undefined");
    }

    return 0;
}
/**
Sample Input 1:
7
5 -3.2 aaa 9999 2.3.4 7.123 2.35
Sample Output 1:
ERROR: aaa is not a legal number
ERROR: 9999 is not a legal number
ERROR: 2.3.4 is not a legal number
ERROR: 7.123 is not a legal number
The average of 3 numbers is 1.38
**/
