/**********************
author: yomi
date: 18.4.11
ps: ����ֵ�ü�� �ܾ���ǰ������ Ȼ��ȴ������ͨ�� ����������ȫ���Լ��Ĵ���ͨ���� �����ε���
�Ҽ���Ҳ������
����the second common character is the 5th capital letter 'E', �������Ĳ��Ǻ���������Ǵ�ͷ
��ʼ���ĵڶ������������������ĵ�һ������һ����
**********************/
#include <iostream>
#include <string>
#include <cctype>
#include <cstdio>
using namespace std;
string week[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
int main()
{
    string s1, s2, s3, s4;

    cin >> s1 >> s2 >> s3 >> s4;
    int len1 = s1.length(),len2 = s2.length(),len3 = s3.length(),len4 = s4.length();
    int len5 = min(len1, len2), len6 = min(len3, len4);
    int flag = 1;
    int cnt = 0;
    for(int i=0; i<len5; i++){
        if(isupper(s1[i]) && s1[i] == s2[i] && s1[i] >='A' && s1[i] <= 'G' && flag == 1){
            cout << week[s1[i]-'0'-17] << ' ';
            flag = 0;
        }
        else if(flag == 0 && s1[i] == s2[i]){

            if((s1[i]>='A'&&s1[i]<='N')){
                printf("%02d:", s1[i]-'0'-17+10);
              	break;///
            }
            else if((s1[i]>='0'&&s1[i]<='9')){
                printf("%02d:", s1[i]-'0');
              	break;///
            }
            ///break;���������break��ʹ����һ�����棬���1��2�𰸴���
            ///���Ǹ���ӣ����ύ��ʮ����������ס�����һbreak,��ô
            ///�����������������ͬ��Сд��ĸ��Ҳ��������ѭ����������û
            ///�еõ�ʱ�䡣
        }
    }
    for(int i=0; i<len6; i++){
        if(s3[i] == s4[i] && isalpha(s3[i])){
            printf("%02d", i);
            break;
        }
    }
    return 0;
}
/**
3485djGkxh4hhGN
2984akGfkkkkggNdsb
s&hgsfdk
d&Hyscvnm

THU 14:04
**/
