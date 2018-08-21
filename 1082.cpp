/**********************
author: yomi
date: 18.4.13
ps: 应该是从后往前数的四位 最后还是被自己的智商折服了 就是做不出来啊
归根到底 还是上来就打代码 并没有把思路梳理好
再也不要这样做题了
暂时和1082说再见
我去找你姐姐1016玩耍了 他不理我 于是 我又回来了
其实出错的最主要原因：
1000800
就是每四位要从后往前数， 而 打印出来的ling 又是从前往后数的第一个
整理一下 重新做 测试点0WA
没有控制好100000000 yi Yi
竟然忘记在name中加Yi了
忽然发现 我没有去掉while(cin >> s)
但是竟然过了
本题让我深刻地意识到梳理好思路的重要性
1011111
1000
1008
重要的就是知道什么时候该输出ling，比如说yi Qian ling Ba 和yi Qian ba Bai
不难发现
每四位一组 只要低位有数字 然后在这四位中碰到0就要输出零 但要注意只输出一次 可以通过flag控制
每四位结束 就要重置标志flag
最后别忘记一位数字的处理 比如 2、0
OK 25到手
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
                if(count(t.begin(), t.end(), '0')!=4)//解决了测试点0
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
