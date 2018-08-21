/**********************
author: yomi
date: 18.4.11
ps: 这题值得纪念啊 很久以前就做过 然而却并不能通过 今天终于完全用自己的代码通过了 很尴尬的是
乙级里也有这题
首先the second common character is the 5th capital letter 'E', 。描述的不是很清楚，不是从头
开始数的第二个，而是满足条件的第一个的下一个。
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
            ///break;上面的两个break我使用这一个代替，结果1、2答案错误
            ///这是个深坑，我提交二十多遍的罪魁祸首。这里一break,那么
            ///如果先遇到了两个相同的小写字母，也就跳出了循环，这样并没
            ///有得到时间。
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
