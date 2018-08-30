/**********************
author: yomi
date: 18.8.29
ps:模考的时候这题竟然挂了 我的字符串处理是真的差
拯救我的就是在字符串末尾加上星花了 16-->20
注意到失分不多 可能是边界的问题 编两个数据一测 果然呐
原因是我的算法检测不到最后一个字符
fffeee
就检测不到eee了
所以加星花是一个解决的好办法
反正我这个水平 也就这种笨方法了 回头去看看柳神的代码呀
**********************/
#include <iostream>
#include <map>
#include <string>
#include <cstdio>
using namespace std;
map<char, int>mmap;
int main()
{
    int n, cnt=1;
    string s;
    cin >> n;
    getchar();
    getline(cin, s);
    s+='*';///救星
    char last = s[0];
    for(int i=1; i<s.length(); i++){
        //cout << s[i] << ' ' << cnt << endl;
        if(s[i]!=last){
            if(cnt%n==0 && mmap[last]!=-1){
                mmap[last] = 1;
            }
            else if(cnt != n){
                mmap[last] = -1;
            }
            cnt = 1;
            last = s[i];
        }
        else{
            cnt++;
        }
    }
    int flag = 0;
    for(int i=0; i<s.length(); i++){
        if(mmap[s[i]] == 1){
            cout << s[i];
            flag = 1;
            mmap[s[i]] = 2;
        }
    }
    if(flag)
        cout << endl;
    for(int i=0; i<s.length()-1; i++){
        cout << s[i];
        if(mmap[s[i]] == 2){
            i+=(n-1);
        }

    }

    return 0;
}
/**
3
fffeee
f
feee
**/
/**
Sample Input:
3
caseee1__thiiis_iiisss_a_teeeiieeest
Sample Output:
ei
case1__this_isss_a_teest
**/
