/**********************
author: yomi
date: 18.6.14
ps:
**********************/
#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;

int main()
{
    string s;
    stringstream is;
    cin >> s;
    if(s[0] == '-'){
        cout << "-";
    }
    string s1, s2, s3, s4;
    int pos1, pos2, p3, p4;
    pos1 = s.find('E');
    s1 = s.substr(1, pos1-1);//1.23400
    pos2 = s.find('.');
    s2 = s.substr(1, pos2-1);//1
    int len1 = s1.length(), len2 = s2.length();
    s3 = s.substr(pos2+1, len1-len2-1);//23400
    s4 = s.substr(pos1+1+1, s.length()-3);/// - E -   /// 03
    int len3 = s3.length(), len4 = s4.length();
//    cout << s1 << endl;
//    cout << s2 << endl << s3 << endl;
//    cout << s4 << endl;
    is.str(s4);
    int t;
    is >> t;
    //cout << t << endl;
    //cin >> t;
    if(s[pos1+1] == '+'){///   *
        if(t > len3){
            cout << s2 << s3;
            for(int i=0; i<t-len3; i++){
                cout << "0";
            }
        }
        else{
            cout << s2;
            for(int i=0; i<t; i++){
                cout << s3[i];
            }
            if(t!=len3)
            cout << ".";
            for(int i=t; i<len3; i++){
                cout << s3[i];
            }
        }
    }
    else{/// /
        if(t){
            cout << "0.";
            for(int i=0; i<t-1; i++){
                cout << "0";
            }
            cout << s2 << s3;
        }
        else{
            cout << s1;
        }
    }
    return 0;
}

/**
[+-][1-9]"."[0-9]+E[+-][0-9]+

+1.23400E-03
0.00123400

-1.2E+10
-12000000000
**/
