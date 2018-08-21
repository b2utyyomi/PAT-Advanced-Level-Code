/**********************
author: yomi
date: 18.2.27
ps:
似懂非懂啊
date: 18.6.8
现在来梳理思路：
1. 把已知进制的数转换为相应的已给的进制 （为什么要转呢？因为他给你的这个数并不一定是正确的表示，比如说
ab 二进制 ， 那么就需要把ab先转到二进制）
2. 寻找未知进制数的进制，使他与前面的数相等--->进制数一定是从小到大遍历的，那么可以用到二分
然而还有一些小问题要去攻克：
1.二分上下界的确定：
 二分下界：
    进制必须能够表示这个数，所以该进制必须大于这个数中最大的那位数，故下界为：最大的那位数+1
 二分上界：
    分两种情况：
    一是已知数大于下界，那么上界为：已知数
    二是已知数小于下界，那么上界为：下界（容易想到的是上界为已知数，而由于上界不能小于下界，故
    此时上界与下界相等）
   这样就归结成了一个问题，为什么上界为已知数？
   需要指出的是 A digit is less than its radix and is chosen from the set {0-9, a-z} where 0-9
   represent the decimal numbers 0-9, and a-z represent the decimal numbers 10-35. 只是说某一位
   数的进制为36，而我却以为我们要找的进制也在36进制以内，结果就WA了一半。实际上，题目并没有提
   上界，而当要找的进制数比已知数大的时候，这两个数就决不可能再相等了。所以将上界设置为已知数
   即可（一定是转换到已知进制数的已知数）。
看了大神的代码收获很多：
1. char it = *max_element(n.begin(), n.end());//查找最大元素的好办法
   整型数据只要在vector中就可以使用啦
2. 适当使用三目运算符确实能使代码简洁不少，这样有助于考场上分析。
    不管你们懂没懂，反正我懂了。
*********************分析为原创，代码部分原创改编自柳婼******************/

#include <iostream>
#include <cctype>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
long long convert(string n, long long radix) {
    long long sum = 0;
    int index = 0, temp = 0;
    for(int i=0; i<n.length(); i++){
        temp = isdigit(n[i]) ? n[i]-'0' : n[i]-'a'+10;
        sum = sum*radix+temp;
    }
    return sum;
}
long long find_radix(string n, long long num) {
    char it = *max_element(n.begin(), n.end());//查找最大元素的好办法
    long long low = (isdigit(it) ? it - '0': it - 'a' + 10) + 1;
    long long high = max(num, low);
    while (low <= high) {
        long long mid = (low + high) / 2;
        long long t = convert(n, mid);
        if ( t < 0 || t > num) high = mid - 1;//如果使用当前进制转化得到数值比另一个大或者小于0，说明这个进制太大～
        else if (t == num) return mid;
        else low = mid + 1;
    }
    return -1;
}
int main() {
    string n1, n2;
    long long tag = 0, radix = 0, result_radix;
    cin >> n1 >> n2 >> tag >> radix;
    result_radix = tag == 1 ? find_radix(n2, convert(n1, radix)) : find_radix(n1, convert(n2, radix));
    if (result_radix != -1) {
        printf("%lld", result_radix);
    } else {
        printf("Impossible");
    }
    return 0;
}


/** 没用二分17分 一堆答案错误 因为我没考虑好radix的范围
#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
using namespace std;

int pow(int a, int n)
{
    int ans = 1;
    for(int i=0; i<n; i++){
        ans *= a;
    }
    return ans;
}
int main()
{
    int tag, radix;
    string a,b;
    int flag = 1;
    int aa[20], bb[20];
    long long int n1 = 0, n2 = 0;
    int ans = 0;
    cin >> a >> b >> tag >> radix;
    int cnt1 = 0, cnt2 = 0;
    for(int i=0; i<a.length(); i++){
        if(a[i]>='0' && a[i]<='9'){
            aa[cnt1++] = a[i]-'0';
        }
        else if(a[i]>='a' && a[i]<='z'){
            aa[cnt1++] = a[i] - '0' - 39;
        }
    }
    for(int i=0; i<b.length(); i++){
        if(b[i]>='0' && b[i]<='9'){
            bb[cnt2++] = b[i]-'0';
        }
        else if(b[i]>='a' && b[i]<='z'){
            bb[cnt2++] = b[i] - '0'-39;
        }
    }
//    for(int i=0; i<cnt2; i++){
//        cout << bb[i] << endl;
//    }
    if(tag == 1){
        //to find 2nd's radix
        // convert 1st and 2nd to decimal
        for(int i=0; i<cnt1; i++){
            n1 += aa[i]*pow(radix, cnt1-i-1);
        }
        for(ans = 2; ans <=36; ans++){
            n2 = 0;
            for(int i=0; i<cnt2; i++){
                n2 += bb[i]*pow(ans, cnt2-i-1);
            }
            if(n2 == n1){
                flag = 0;
                break;
            }
        }

    }
    else if(tag == 2){
        //to find 1st's radix
        //convert 1st and 2nd to decimal
        for(int i=0; i<cnt2; i++){
            n1 += bb[i]*pow(radix, cnt2-i-1);
        }
        for(ans = 2; ans <=36; ans++){
            n2 = 0;
            for(int i=0; i<cnt1; i++){
                n2 += aa[i]*pow(ans, cnt1-i-1);
            }
            if(n2 == n1){
                flag = 0;
                break;
            }
        }
    }
    if(flag == 0)
        cout << ans;
    else
        cout << "Impossible";
    return 0;
}
**/
/**
6 110 2 2
2

1 ab 1 2
**/
