/**********************
author: yomi
date: 18.6.13
ps:��ȫ�׿�ƪ��ģ����
���Ե�1----> WA
**********************/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[100010];
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    sort(a, a+n);
    int i=0, j=n-1, flag = 0;
    while(i<n && j>=0){
        if(j<=i)
            break;
        if(a[i]+a[j] == m){
            if(a[i] <= a[j])
                printf("%d %d", a[i], a[j]);
            else
                printf("%d %d", a[j], a[i]);
            flag = 1;
            //i++,j--;
            break;
        }///Ϊʲô�����أ�������׻�����Ϊ����һ�����������С�
        else if(a[i]+a[j] < m){ ///��ʱa[i]+a[j]��mС��Ӧ����������
            i++;
        }
        else{///��ʱa[i]+a[j]��m��Ӧ����������
            j--;
        }
    }
    if(!flag)
        printf("No Solution");
    return 0;
}
/**
4 4
1 2 4 8
2 2
**/
/**
1 2 8 7 2 4 11 15
1 2 2 4 7 8 11 15
**/
/**
8 15
1 2 8 7 2 4 11 15

4 11
**/







