/**********************
author: yomi
date: 18.4.8
ps: 10^7+10^7 �������ͷ�Χ�������İɣ������Ŀ���ʹ��̬������С����ɲ�Ҫ�ٷ��ˡ�
**********************/
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    long long int a1, b1, c1, a2, b2, c2, sum, a3, b3, c3;
    char ch;
    scanf("%d%c%d%c%d%d%c%d%c%d", &a1, &ch, &b1, &ch, &c1, &a2, &ch, &b2, &ch, &c2);
    sum = (a1+a2)*29*17+(b1+b2)*29+(c1+c2);
    a3 = sum/29/17;
    b3 = (sum-a3*29*17)/29;
    c3 = sum-a3*29*17-b3*29;
    cout << a3 << "." << b3 << "." << c3;
    return 0;
}
/**
3.2.1 10.16.27
14.1.28
**/
