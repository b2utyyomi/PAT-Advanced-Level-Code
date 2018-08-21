/**********************
author: yomi
date: 18.5.27
ps: 可以说是走错了方向了 为什么正确的算法我就是想不到呢
答： 您做的题太少了
 啊 没脸看我写的东西 直接抄答案了 我会记住答案的技巧的
掉进了去前导零的大坑 中间为的零应该保留啊
这个脑子啊
一个大数 只去掉 最前面的零
而这个数是由多个数拼成的 必须先拼成那个数再去前导零啊
不然那么多的数 去哪个的啊
**********************/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 10010;
string str[maxn];
string ans = "";
int cmp(string a, string b)
{
    return a+b < b+a;
}
int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> str[i];
    }
    sort(str, str+n, cmp);
    for(int i=0; i<n; i++){
        ans += str[i];
    }
    while(ans.size() && ans[0] == '0'){///去前导零的好办法，要记住
        ans.erase(ans.begin());
    }
    if(!ans.size()){
        cout << "0";
    }
    else{
        cout << ans;
    }
    return 0;
}
/*   ------------21分--------------------
在抄答案的过程中恍然大悟 为什么我只有21分
我在输入的同时去掉了前导零 中间位的前导零是应该保留的
这样去掉了很多不该去掉的
21分是活该啊
struct str
{
    string value;
    char small;
}s[10010];
//char findsmall(string a)
//{
//    char ch1 = 'A';
//    //cout << "test" <<endl;
//    for(int i=0; i<a.length(); i++){
//        if(a[i] < ch1){
//            ch1 = a[i];
//        }
//    }
//
//    return ch1;
//}
//int cmp(str a, str b)
//{
//    if(a.value[0]!=b.value[0])
//        return a.value<b.value;
//    return a.small<b.small;
//}
//int cmp(str a, str b)
//{
//    if(a.value[0]!=b.value[0])
//        return a.value < b.value;
//    if ((a.value+b.value)<(b.value+a.value)){
//        return a.value < b.value;
//    }
//    return a.value > b.value;
//
//}
int cmp(str a, str b)
{
    return a.value+b.value < b.value+a.value;
}
int main()
{
    int n;
    scanf("%d", &n);
    int flag = 1;
    for(int i=0; i<n; i++){
        cin >> s[i].value;
        int len = s[i].value.length();
        int pos = 0;
        for(int j=0; j<len; j++){
            if(s[i].value[j]!='0'){
                break;
            }
            else{
                pos++;
            }
        }
        if(pos!=0)
            s[i].value = s[i].value.substr(pos, len);
        //s[i].small = findsmall(s[i].value);
    }
    sort(s, s+n, cmp);
    for(int i=0; i<n; i++){
        if(s[i].value.length()){
            cout << s[i].value;
            flag = 0;
        }

    }
    if(flag)
        cout << "0";
    return 0;
}
*/
/**
5 32 321 3214 0229 87

22932132143287
**/
