/**********************
author: yomi
date: 18.7.19
ps: 像这种字符串的题一定要考虑前导零 万一掉坑 那可就惨了
结果还是很不妙 少考虑了很多种情况 包括0.0000
完全是照着书上的样例改代码，也是没谁了
**********************/
#include <iostream>
#include <string>
using namespace std;

int main()
{
    while(1){


    int n;
    string a, b;
    cin >> n >> a >> b;
    while(a.size()!=0 && a[0] == '0'){
        a.erase(a.begin());
    }
    while(b.size()!=0 && b[0] == '0'){
        b.erase(b.begin());
    }
    int pos1 = a.find('.');
    int pos2 = b.find('.');
    if(pos1 == -1){
        pos1 = a.length();
        a+=".";
    }
    if(pos2 == -1){
        pos2 = b.length();
        b+=".";
    }
//    cout << pos1 << ' ' << pos2 << endl;
//    cout << a << ' ' << b << endl;
    if(pos1 >= n && pos2 >= n){ /// 5 5
        string s1 = a.substr(0, n);
        string s2 = b.substr(0, n);
        //cout << s1 << ' ' << s2 << endl;
        if(s1 == s2 && pos1 == pos2){
            cout << "YES" << ' ';
            cout << "0." << s1;
            if(pos1)
             cout << "*10^" << pos1;
        }
        else{///2 1134 1235
            cout << "NO" << ' ';
            cout << "0." << s1;
            if(n)
                cout << "*10^" << pos1 << ' ';
            cout << "0." << s2;
            if(n)
                cout << "*10^" << pos2;
        }
    }
    else{/// 4 12.897 12.8989    ---   4 123   123
        string s1 = a.substr(0, pos1);
        string s2 = b.substr(0, pos2);
        s1 += a.substr(pos1+1, a.length()-pos1-1);
        s2 += b.substr(pos2+1, b.length()-pos2-1);
        s1 = s1.substr(0, n);
        s2 = s2.substr(0, n);
        if(s1 == s2 && pos1 == pos2){
            cout << "YES" << ' ';
            cout << "0." << s1;
            if(pos1)
                cout << "*10^" << pos1;
        }
        else{
            cout << "NO" << ' ';
            cout << "0." << s1 ;
            cout << "*10^" << pos1 << ' ';
            cout << "0." << s2 ;
            cout << "*10^" << pos2 << ' ';

        }
        cout <<endl;
    }
    }
    return 0;
}
/**
4 0012.897 001289
4 12.897 12.8989
4 12.897 12.8789
**/
/**
Sample Input 1:
3 12300 12358.9
Sample Output 1:
YES 0.123*10^5
Sample Input 2:
3 120 128
Sample Output 2:
NO 0.120*10^3 0.128*10^3
**/
