/**********************
author: yomi
date: 18.4.13
ps: Ӧ���ǴӺ���ǰ������λ ����Ǳ��Լ��������۷��� ��������������
������� ���������ʹ���� ��û�а�˼·�����
��Ҳ��Ҫ����������
��ʱ��1082˵�ټ�
��ȥ������1016��ˣ�� �������� ���� ���ֻ�����
��ʵ���������Ҫԭ��
1000800
����ÿ��λҪ�Ӻ���ǰ���� �� ��ӡ������ling ���Ǵ�ǰ�������ĵ�һ��
����һ�� ������ ���Ե�0WA
û�п��ƺ�100000000 yi Yi
��Ȼ������name�м�Yi��
��Ȼ���� ��û��ȥ��while(cin >> s)
���Ǿ�Ȼ����
����������̵���ʶ�������˼·����Ҫ��
1011111
1000
1008
��Ҫ�ľ���֪��ʲôʱ������ling������˵yi Qian ling Ba ��yi Qian ba Bai
���ѷ���
ÿ��λһ�� ֻҪ��λ������ Ȼ��������λ������0��Ҫ����� ��Ҫע��ֻ���һ�� ����ͨ��flag����
ÿ��λ���� ��Ҫ���ñ�־flag
��������һλ���ֵĴ��� ���� 2��0
OK 25����
**********************/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

                //  0     1       2      3      4       5      6      7
//string name[8] = {"Yi", "Qian", "Bai", "Shi", "Wan", "Qian", "Bai", "Shi"};
string name[10] = {"","Shi", "Bai", "Qian", "Wan", "Shi", "Bai", "Qian", "Yi"};
string value[9] = {"yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
int main()
{
    string s;
    while(cin >> s){
        if(s[0] == '-'){
        cout << "Fu ";
        s = s.substr(1, s.length());
    }
    //cout << s << endl;
    int i, j;
    int cnt = 0;
    string tmp = "";
    int flag = 0;
    if(s.length()!=1){
        for(j=s.length()-1; j>0; j--){
            if(cnt % 4 == 0){
                flag = 0;
            }
            if(j == s.length()-1 && s[j]!='0'){
                tmp = " "+value[s[j]-'0'-1] + tmp;
                flag = 1;
            }
            else if(s[j]!='0'){
                tmp = " " + value[s[j]-'0'-1]+ " " + name[cnt] + tmp;
                flag = 1;
            }
            else if(flag && s[j] == '0'){
                tmp = " ling" + tmp;
                flag = 0;
            }
            if(s[j] == '0' && cnt == 4){
                string t = s.substr(1, j);
                if(count(t.begin(), t.end(), '0')!=4)//����˲��Ե�0
                    tmp = " Wan"+tmp;
            }
            cnt++;

        }
        if(s[0]!='0'){
            tmp = value[s[0]-'0'-1]+ " " + name[cnt] + tmp;
        }
    }
    else if(s.length() == 1){
        if(s[0] == '0'){
            tmp = "ling";
        }
        else{
            tmp = value[s[0]-'0'-1];
        }
    }



    cout << tmp;

    }

    return 0;
}
/**
1010080
yi Bai yi Wan ling ba Shi
1000080
yi BaiShi  Wan ling ba Shi

1008000
yi Bai ling ba Qian
100080
yi Shi Wan  ling  ba Shi Shi
10008
yi Wan ling  ba
100008
yi Shi Wan  ling  ba
10000008
yi Qian ling  Wan  ling  ba
**/
/**
Sample Input 1:
-123456789
Sample Output 1:
Fu yi Yi er Qian san Bai si Shi wu Wan liu Qian qi Bai ba Shi jiu
Sample Input 2:
100800
Sample Output 2:
yi Shi Wan ling ba Bai
Sample Input 3:
108
Sample Output 3:
yi Bai ling ba
Sample Input 4:
1008
Sample Output 4:
yi Qian ling ba


**/
