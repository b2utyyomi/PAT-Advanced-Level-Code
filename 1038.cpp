/**********************
author: yomi
date: 18.5.27
ps: ����˵���ߴ��˷����� Ϊʲô��ȷ���㷨�Ҿ����벻����
�� ��������̫����
 �� û������д�Ķ��� ֱ�ӳ����� �һ��ס�𰸵ļ��ɵ�
������ȥǰ����Ĵ�� �м�Ϊ����Ӧ�ñ�����
������Ӱ�
һ������ ֻȥ�� ��ǰ�����
����������ɶ����ƴ�ɵ� ������ƴ���Ǹ�����ȥǰ���㰡
��Ȼ��ô����� ȥ�ĸ��İ�
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
    while(ans.size() && ans[0] == '0'){///ȥǰ����ĺð취��Ҫ��ס
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
/*   ------------21��--------------------
�ڳ��𰸵Ĺ����л�Ȼ���� Ϊʲô��ֻ��21��
���������ͬʱȥ����ǰ���� �м�λ��ǰ������Ӧ�ñ�����
����ȥ���˺ܶ಻��ȥ����
21���ǻ�ð�
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
