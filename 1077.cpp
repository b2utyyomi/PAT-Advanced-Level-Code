/**********************
author: yomi
date: 18.4.12
ps:思路就是从第一个串的最后一个字符开始依次与其他的串的相应字符进行比对。
不一致就要跳出循环，全一致就保存到tmp中。
第一次提交 最后一个测试点WA
**********************/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    char ch;
    string s[1000];
    cin >> n;
    getline(cin, s[100]);//就相当于getchar()接收换行
    //本来我写的是cin >> ch;ch虽然接住了回车 但也又产生了一个呀 低级错误
    for(int i=0; i<n; i++){
        getline(cin, s[i]);
    }
    int v=s[0].length()-1, j, i, k, flag = 0;
    string tmp = "";
    int cnt = 1;
    for(j=v; j>=0; j--){

        for(i=1; i<n; i++){
            k = s[i].length()-cnt;
            if(k < 0){
                flag = 1;
                break;
            }

            //cout << s[i][k] << ' ' << s[0][v] << endl;
            if(s[i][k]!=s[0][j]){
                flag = 1;
                break;
            }
            else{
                ch = s[i][k];
            }
        }
        if(flag)
            break;
        cnt++;
        tmp += ch;
    }
    reverse(tmp.begin(), tmp.end());
    if(tmp!="")
        cout << tmp;
    else{
        cout << "nai";
    }
    return 0;
}
/**
wrong
3
aaaaa
aa
aa

aaaa

**/
/**
3
Itai nyan~
Ninjin wa iyadanyan~
uhhh nyan~

nyan~


3
Itai!
Ninjinnwaiyada T_T
T_T

nai
*/
