/**********************
author: yomi
date: 18.6.17
ps:
���᲻�� ��Ȼ�Ҽ�ˢ������� �������ڻ��ǲ��� Ҫ����������˼��
�����뵽�ľ�ֻ�б���ѭ�� T^T
int len = strlen(str);
ѭ����һ��Ҫ�������ȼ���õ�len
**********************/
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <stdio.h>
#include <cstdlib>
using namespace std;
const int mod = 1000000007;
int plnum[100010];
char str[100010];
int main()
{
    memset(str, 0, sizeof(str));
    memset(plnum, 0, sizeof(plnum));
    scanf("%s", str);
    int len = strlen(str);
    ///����ÿһ��λ�õ�����ж��ٸ�p��������������
    for(int i=0; i<len; i++){///����˴�����len,������ʱ����Ļ����ᳬʱ
        if(i > 0){
            plnum[i] = plnum[i-1];
        }
        if(str[i] == 'P'){
            plnum[i]++;
        }
    }
    int ans = 0, trnum = 0;
    for(int i=len-1; i>=0; i--){
        if(str[i] == 'T'){
            trnum++;
        }
        else if(str[i] == 'A'){
            ans = (ans+plnum[i]*trnum)%mod;
        }

    }
    printf("%d\n", ans);
    return 0;
}

/***
��������Ľⷨ����

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int num_t=0, num_at=0, num_pat=0;
    ///cout << str.length() << endl;
    for(int i=str.size()-1; i>=0; i-- ){///���� �����д�˸�size_t, ����ѭ����
        if(str[i] == 'T'){
            num_t ++;
            ///num_t %= 1000000007;
        }
        if(str[i] == 'A'){
            num_at = (num_at+num_t) % 1000000007;///����д��+=Ҳ���� ��������ȼ�������
        }
        if(str[i] == 'P'){
            num_pat = (num_pat+num_at) % 1000000007;
        }
    }
    cout << num_pat;
    return 0;
}

**/
