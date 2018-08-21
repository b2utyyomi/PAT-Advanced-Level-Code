/**********************
author: yomi
date: 18.7.29
ps: 数组开了20 两组样例没过 开了1000立马ac 这要是考试因为这个丢了7分
我可真是比窦娥还冤呢
**********************/
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
bool isPalin(string s)
{
    int len = s.length();
    int i;
    for(i=0; i<len/2; i++){ ///1221 --> 4   121
        if(s[i] != s[len-i-1]){
            break;
        }
    }
    if(i == len/2)
        return true;
    return false;

}
struct bign
{
    int len;
    int num[1000];
    bign()
    {
        memset(num, 0, sizeof(num));
        len = 0;
    }
}b, c, a;
void add()
{
    int carry = 0, cnt = 0;

    for(int i=0; i<c.len; i++){
        int tmp = c.num[i]+c.num[c.len-i-1]+carry;
        carry = tmp/10;
        a.num[cnt++] = tmp%10;
    }
    if(carry){
        a.num[cnt++] = carry;
    }
    a.len = cnt;
    c = a;
}
int main()
{
    string s;
    int k;
    cin >> s >> k;
    if(isPalin(s)){
        cout << s << endl;
        cout << 0 << endl;
    }
    else{
        int n = 0, flag = 1;
        string p = "";
        int len = s.length();
        b.len = len;
        for(int i=0; i<len; i++){
            b.num[i] = s[len-i-1]-'0';
        }
        c = b;
        while(n<k){
            add();
            p = "";
            for(int i=0; i<c.len; i++){
                char ch = c.num[i]+'0';
                p+=ch;
            }
            reverse(p.begin(), p.end());
            if(isPalin(p)){
                cout << p << endl;
                cout << n+1 << endl;;
                flag = 0;
                break;
            }
            n++;
        }
        if(flag){
            cout << p << endl;
            cout << n << endl;
        }

    }
    return 0;
}
/**
Sample Input 1:
67 3
Sample Output 1:
484
2
Sample Input 2:
69 3
Sample Output 2:
1353
3
**/
