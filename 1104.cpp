/**********************
author: yomi
date: 18.6.23
ps: ���Ե�2WA ---> �治������Ϊʲô����  ���������������ʱ��Ƚϳ�
�������������ر���ʱ����˲��� �޽�
����ˢ���������~
**********************/
#include <iostream>
#include <cstdio>
using namespace std;
double a[100010];
int main()
{
    int n;
    scanf("%d", &n);
    double ans = 0.0, temp = 0.0;
    for(int i=1; i<=n; i++){
        scanf("%lf", &a[i]);
        ans += a[i]*i*(n+1-i);
    }

   /** ��ʹ ������Ϊʲô��
    for(int i=n, j=1; i>=1,j<=n; i--, j++){
        temp+=a[i]*j;
        ans += temp;
    }
    **/
    /** ��ǰ������ ���鷳����ֻ����17��  **/
//    temp1 += temp;
//    //cout << temp << endl;
//    for(int i=n; i>=1; i--){
//        temp = temp-a[i];
//        temp1 += temp;
//    }
//    //cout << temp1 << endl;
//    for(int i=1; i<=n; i++){
//        ans += temp1;
//        temp1 = temp1-(n+1-i)*a[i];
//    }

    printf("%.2f", ans);

    return 0;
}
/**
4
0.1 0.2 0.3 0.4


4
0.4 0.3 0.1 0.2

**/
