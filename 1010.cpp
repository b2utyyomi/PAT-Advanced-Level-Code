/**********************
author: yomi
date: 18.2.27
ps:
�ƶ��Ƕ���
date: 18.6.8
����������˼·��
1. ����֪���Ƶ���ת��Ϊ��Ӧ���Ѹ��Ľ��� ��ΪʲôҪת�أ���Ϊ����������������һ������ȷ�ı�ʾ������˵
ab ������ �� ��ô����Ҫ��ab��ת�������ƣ�
2. Ѱ��δ֪�������Ľ��ƣ�ʹ����ǰ��������--->������һ���Ǵ�С��������ģ���ô�����õ�����
Ȼ������һЩС����Ҫȥ���ˣ�
1.�������½��ȷ����
 �����½磺
    ���Ʊ����ܹ���ʾ����������Ըý��Ʊ�������������������λ�������½�Ϊ��������λ��+1
 �����Ͻ磺
    �����������
    һ����֪�������½磬��ô�Ͻ�Ϊ����֪��
    ������֪��С���½磬��ô�Ͻ�Ϊ���½磨�����뵽�����Ͻ�Ϊ��֪�����������Ͻ粻��С���½磬��
    ��ʱ�Ͻ����½���ȣ�
   �����͹�����һ�����⣬Ϊʲô�Ͻ�Ϊ��֪����
   ��Ҫָ������ A digit is less than its radix and is chosen from the set {0-9, a-z} where 0-9
   represent the decimal numbers 0-9, and a-z represent the decimal numbers 10-35. ֻ��˵ĳһλ
   ���Ľ���Ϊ36������ȴ��Ϊ����Ҫ�ҵĽ���Ҳ��36�������ڣ������WA��һ�롣ʵ���ϣ���Ŀ��û����
   �Ͻ磬����Ҫ�ҵĽ���������֪�����ʱ�����������;�������������ˡ����Խ��Ͻ�����Ϊ��֪��
   ���ɣ�һ����ת������֪����������֪������
���˴���Ĵ����ջ�ࣺܶ
1. char it = *max_element(n.begin(), n.end());//�������Ԫ�صĺð취
   ��������ֻҪ��vector�оͿ���ʹ����
2. �ʵ�ʹ����Ŀ�����ȷʵ��ʹ�����಻�٣����������ڿ����Ϸ�����
    �������Ƕ�û���������Ҷ��ˡ�
*********************����Ϊԭ�������벿��ԭ���ı������S******************/

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
    char it = *max_element(n.begin(), n.end());//�������Ԫ�صĺð취
    long long low = (isdigit(it) ? it - '0': it - 'a' + 10) + 1;
    long long high = max(num, low);
    while (low <= high) {
        long long mid = (low + high) / 2;
        long long t = convert(n, mid);
        if ( t < 0 || t > num) high = mid - 1;//���ʹ�õ�ǰ����ת���õ���ֵ����һ�������С��0��˵���������̫��
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


/** û�ö���17�� һ�Ѵ𰸴��� ��Ϊ��û���Ǻ�radix�ķ�Χ
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
