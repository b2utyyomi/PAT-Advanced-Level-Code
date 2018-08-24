/**********************
author: yomi
date: 18.8.24
ps:
**********************/
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
char s[1010];
int main()
{
    int b, ans[1010], cnt=0, yu=0;
    scanf("%s", s);
    scanf("%d", &b);
    int len = strlen(s), num=0;
    if(len < 5){
        sscanf(s, "%d", &num);
        printf("%d %d",num/b, num%b);
    }
    else{
        for(int i=0; i<len; i++){
            int t = s[i]-'0';
            //cout << num << endl;
            if(t<b && i!=len-1 && num == 0){
                num += 10*t;
                ans[cnt++] = 0;
            }
            else if(t<b && i == len-1 && yu == 0){
                yu = t;
                ans[cnt++] = 0;
            }
            else{
                num += t;
                ans[cnt++] = num/b;
                yu = num%b;
                num = yu*10;
            }
        }
        int flag = 0;
        for(int i=0; i<cnt; i++){
            if(flag == 0 && ans[i] == 0)
                continue;
            printf("%d", ans[i]);
            flag = 1;
        }
        printf(" %d", yu);
    }
    return 0;
}
/**
输入样例：
123456789050987654321 7
输出样例：
17636684150141093474 3
**/

/** 18-1-25 **/
/** 可怕 怎么能写出这么恶心的
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int powe(int n)
{
    int sum = 1;
    for(int i=0; i<n; i++){
        sum *= 10;
    }
    return sum;
}
int toint(string s)
{
    int sum = 0;
    int cnt=0;
    for(int i=s.length()-1; i>=0; i--){
        sum += (s[cnt++]-'0')*powe(i);
    }
    return sum;
}
string tostring(int n)
{
    string s = ""       ;
    while(n){
        s += (n%10)+'0';
        n /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}
int main()
{
    int n;
    string s;
    //while(1){
    cin >> s >> n;
    int flag1 = 0;
    string ans = "";
    string temp = "";
    int flag = 0;
    int res;
    int y = 0;
    int flag2 = 0;
    for(int i=0; i<s.length(); i++){/// 1002 2
        if(s[i] == '0' && flag == 0){
            ans += "0";
        }
        else if((s[i]-'0')<=n && i+1 <s.length() && flag == 0){
            if(i!=0 && s[i]-'0' < n)
                ans += "0";
            temp += "";
            temp += s[i];
            temp += s[i+1];
            int bcs = toint(temp);
            int sh = bcs/n;
            y = bcs%n;
            if(y==0)
                flag = 0;
            else
                flag = 1;
            if(sh != 0)
                ans += tostring(sh);
            else
                ans += "0";
            //s[i+1] = y+'0';
            i++;
            temp = "";
            temp+=tostring(y);
        }
        else if((s[i]-'0')<=n && i+1==s.length() && flag == 0){
            if((s[i]-'0') < n){
                ans += "0";
                flag2 = 1;
            }

            else{
                ans += "1";
                flag2 = 2;
            }

        }
        else if((s[i]-'0')>n && flag == 0){
            temp += "";
            temp += s[i];
            int bcs = toint(temp);
            int sh = bcs/n;
            y = bcs%n;
            if(y == 0)
                flag = 0;
            else
                flag = 1;
            ans += tostring(sh);
            temp = "";
            temp += tostring(y);
        }
        else if(flag == 1){
            temp += s[i];
            int bcs = toint(temp);
            int sh = bcs/n;
            y = bcs%n;
            if(y == 0)
                flag = 0;
            else
                flag = 1;
            ans += tostring(sh);
            temp = "";
            temp += tostring(y);
        }

        if(flag2 == 1)
            res = s[s.length()-1]-'0';
        else
            res = y;
    }
    if(flag1 == 0)
        cout << ans << " " << res;
    //}
    return 0;
}
/// 123456789050987654321 7


**/

