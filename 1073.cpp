/**********************
author: yomi
date: 18.4.12
ps:
[+-][1-9]"."[0-9]+E[+-][0-9]+
符号是不会省略的 所以m完全没必要 我的问题就是1.23400E+05
会输出123400. 就这一个毛病 却没有定位准错误所在 加了不改加的东西
**********************/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <sstream>
using namespace std;

int main()
{
    //while(1){
        char ch;
    int flag1 = 0, flag2 = 0, m=1, m1 = 1;
    string s, s1, s2, s3;
    cin >> s;
    int len = s.length();
    if(s[0] == '+'){
        flag1 = 0;
    }
    else if(s[0] == '-'){
        flag1 = 1;
    }
    else{
        m = 0;
    }
    /// s[1] s[2]=='.'
    s1 = s[m];
    int pos = s.find('E');
    s2 = s.substr(m+2, pos-2-m);
    if(s[pos+1] == '+') flag2 = 0;
    else if(s[pos+1]=='-') flag2 = 1;
    s3 = s.substr(pos+2, len-pos+2);
    stringstream is;
    is.str(s3);
    long long int t;
    is >> t;

    if(flag1)
        cout << "-";
    if(t == 0){
        cout << s1 << "." << s2;
    }
    else{
        if(flag2){
            if(t != 0){
                cout << "0.";
                long long int num = t-1;
                for(int i=0; i<num; i++)
                    cout << "0";
                cout << s1 << s2;
            }


        }
        else{
                long long int num = t-s2.length();
                if(num > 0){
                    cout <<s1<< s2;
                    for(int i=0; i<num; i++){
                        cout << "0";
                    }
                }
                else if(num < 0){///-1.23400E+03
                    cout << s1;
                    num = t;
                    for(int i=0; i<num; i++){
                        cout << s2[i];
                    }
                    cout << '.';
                    for(int i=num; i<s2.length(); i++){
                        cout << s2[i];
                    }
                }
                else{
                    cout << s1 << s2;
                }

            }

        }
        cout << endl;
   // }


    return 0;
}
/**
Sample Input 1:
+1.23400E-03
Sample Output 1:
0.00123400
Sample Input 2:
-1.2E+10
Sample Output 2:
-12000000000
+1.23400E+05
+1.23400E-03
-1.2E+10
-1.23400E-03
-1.23400E+03
-1.23400E+00
-1.23400E+04
-1.23400E+10
-1.23400E-10
+1.23400E-03
+1.23400E+03
+1.23400E+00
+1.23400E+04
+1.23400E+10
+1.23400E-10

+1.2E+10
-1.2E-03
**/
