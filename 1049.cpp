/**********************
author: yomi
date: 18.6.24
ps:啊 放弃治疗 抄答案
分析一下：
举个具体的例子：
pos :  54321
num :  30710

看了答案才发觉原来这是一道排列组合的题啊

对于pos1:
    5432    1
    3071    0
    第一位为1
    前四位是3071时，第一个位置只能放零，所以这种情况是不符合第一位为1的条件的
    所以
    0000~3076  即 一共有3071个1
对于pos2:
    543     2   1
    307     1   0
    第2位为1
    先考虑前三位为307的时候，最后一位只能是0 ，这是一种情况。
    另外，前三位为000~306的时候，最后一位可以为0~9的任意数，即有307*10种
对于pos3:
    54      3   21
    30      7   10
    第3位为1
    前两位可以是00~30 最后两位可以是0~9的任意数，即有31*100种
对于pos4:
    5       4   321
    3       0   710
    第四位为1
    第一位只能为0~2，后三位任意，即有3*1000种
 对于pos5:
            5   4321
            3   0710
    第五位为1，后四位任意，即有1*10000种

思路虽然摆在这里，但是实现起来还是有点困难， 主要是没有模拟好计算过程：
下面模拟一下：

54321
30710

a=1;
n/a=30710;
left = 30710/10 = 3071;
now = 30710/1%10 = 0(就是最后一位);
right = 0;

a = 10;
n/a = 3071;
left = 30710/(10*10) = 307;//取当前位左边的数
now = 30710/10%10 = 1;//取当前位
right = 30710%10 = 0;//取当前位右边的数

a = 100;
n/a = 307;
left = 30710/(100*10) = 30;
now = 30710/100%10 = 7;
right = 30710%100 = 10;

以此类推
不小心暴露了数据处理能力差的弱点
**********************/
#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>
using namespace std;

int main()
{
    int n, a=1, ans = 0;
    int left, now, right;
    scanf("%d", &n);
    while(n/a!=0){
        left = n/(a*10);
        now = n/a%10;
        right = n%a;
        if(now == 0){
            ans += left*a;
        }
        else if(now == 1){
            ans += left*a+right+1;
        }
        else{
            ans += (left+1)*a;
        }
        a *= 10;
    }
    printf("%d\n", ans);
    /*string s, s1, s2;
    cin >> s;
    int cnt = 0;
    int len = s.length(); ///  012   3   45
    for(int i=len-1; i>=0; i--){
        s1 = s.substr(0, i);
        s2 = s.substr(i+1, len-i+1);
        //cout << s1 << ' ' << s2 << endl;
        int len2 = s2.length();
        stringstream is;
        is.str(s1);
        int n;
        is >> n;
        if(s[i] == '0'){
            cnt += n*pow(10, len2);
        }
        else if(s[i] == '1'){
            cnt += n*pow(10, len2)+1;
        }
        else{
            cnt+= (n+1)*pow(10, len2);
        }
    }
    cout << cnt << endl;*/

    return 0;
}
/**
12
5
**/
