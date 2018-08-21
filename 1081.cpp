/**********************
author: yomi
date: 18.6.28
ps: 数组声明的都是long long int ,到主函数里，就又写了int,我可咋整？
**********************/
#include <iostream>
#include <cstdio>
#include <sstream>
#include <cmath>
using namespace std;

long long int a[101], b[101], c[101];
long long int gcd(long long int a, long long int b)
{
    if(a%b==0){
        return b;
    }
    return gcd(b, a%b);
}

int main()
{
    int n, flag = 0;
    string s, s1, s2;
    cin >> n;
    for(int i=0; i<n; i++){
        c[i] = 1;
    }
    for(int i=0; i<n; i++){
        cin >> s;
        stringstream is1, is2;
        int pos = s.find('/');
        if(s[0] == '-'){
            c[i] = -1;
            s1 = s.substr(1, pos-1);
            s2 = s.substr(pos+1, s.length()-pos-1);
        }
        else{
            s1 = s.substr(0, pos);
            s2 = s.substr(pos+1, s.length()-pos-1);
        }
        is1.str(s1);
        is1 >> a[i];
        is2.str(s2);
        is2 >> b[i];
    }

//    ///calculate
//    long long int ans1 = 0, ans2 = 0;
//    long long int minbei;
//    /// to find min bei
//    for(int i=1; i<n; i++){
//        long long int tmp = gcd(b[i-1], b[i]);
//        minbei = b[i-1]*b[i]/tmp;
//    }
//    //cout << minbei << endl;
//    for(int i=0; i<n; i++){///必须在每一次加完之后都进行约分，否则会溢出。这不，我就溢出了。
//        if(c[i] > 0)///啊，我的高数啊。
//            ans1 += a[i]*(minbei/b[i]);
//        else if(c[i] < 0){
//            ans1 -= a[i]*(minbei/b[i]);
//        }
//
//    }
//    if(ans1 == 0){
//        cout << "0";
//    }
//    else{
//        //cout << ans1 << "/" << minbei << endl;
//        long long int zheng = ans1/minbei;
//        //cout << zheng << endl;
//        flag = 0;
//        if((ans1<0 && minbei>0)||(ans1 > 0 && minbei<0)){
//            cout << "-";
//            flag = 1;
//        }
//
//        double d_zheng = ans1*1.0/minbei;
//        //cout << d_zheng << endl;
//
//        if(abs(zheng) >=1){
//            cout << abs(zheng) << ' ';
//        }
//        if(d_zheng != zheng){
//           long long int zi = ans1-minbei*zheng;
//           zi = abs(zi);
//           minbei = abs(minbei);
//            long long int yue = gcd(zi, minbei);
//            printf("%lld/%lld", zi/yue, minbei/yue);
//            flag = 1;
//        }
//        if(!flag){
//            cout << "0";
//        }

    }

    return 0;
}
/**
4
-1/2 -1/2 -1/2 2/2
1/2
3
-1 1/3 1/6
1 1/2
**/
/**
Sample Input 1:
5
2/5 4/15 1/30 -2/60 8/3
Sample Output 1:
3 1/3
Sample Input 2:
2
4/3 2/3
Sample Output 2:
2
Sample Input 3:
3
1/3 -1/6 1/8
Sample Output 3:
7/24
**/
