/**********************
author: yomi
date: 18.8.29
ps:ģ����ʱ�����⾹Ȼ���� �ҵ��ַ�����������Ĳ�
�����ҵľ������ַ���ĩβ�����ǻ��� 16-->20
ע�⵽ʧ�ֲ��� �����Ǳ߽������ ����������һ�� ��Ȼ��
ԭ�����ҵ��㷨��ⲻ�����һ���ַ�
fffeee
�ͼ�ⲻ��eee��
���Լ��ǻ���һ������ĺð취
���������ˮƽ Ҳ�����ֱ������� ��ͷȥ��������Ĵ���ѽ
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
    s+='*';///����
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
