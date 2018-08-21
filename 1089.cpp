/**********************
author: yomi
date: 18.6.14
ps:
�о�д�ĺ��鷳
���Ǹð�ģ���� ȫ���±�Ϊ1
����������Ե�WA��һ�Σ�ԭ������ȥ��b �鲢һ�Σ��õ��鲢��Ľ����
���Կ�������ȷ���Ǳ����ԭʼ���п�ʼ�鲢��
**********************/
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, a[200], b[200], c[200], flag = 0;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
        c[i+1] = a[i];
    }
    for(int i=0; i<n; i++){
        cin >> b[i];

    }
    ///insertion sort
    int cnt = 0;
    for(int i=0; i<n-1; i++){
         if(flag)//ʵ�ֵĻ��Ǻ��鷳�ģ���ʵ��ȫ������������ͬ�˾��˳�������һ��sort(a, a+i+2); ����
            cnt++;
        int j = i+1;
        int temp = a[j];
        while(j>0 && temp < a[j-1]){///����д��a[j],��ô��дa[j]�أ�ǰ�������Ԫ�ض�Ҫ��
            a[j] = a[j-1];  ///��ǰҪ���Ԫ�رȰ�
            j--;
        }
        a[j] = temp;
        ///compare
        int k=0;
        for(k=0; k<n; k++){
            if(a[k] != b[k]){
                break;
            }
        }
        if(k == n){
            flag = 1;
        }
        if(cnt)
            break;


    }
//    for(int i=1; i<=n-1; i++){
//        if(flag)
//            cnt++;
//        int j = i;
//        int temp = a[i];
//        while(j>0 && temp < a[j-1]){
//            a[j] = a[j-1];
//            j--;
//        }
//        a[j] = temp;
//        ///compare
//        int k=0;
//        for(k=0; k<n; k++){
//            if(a[k] != b[k]){
//                break;
//            }
//        }
//        if(k == n){
//            flag = 1;
//        }
//        if(cnt)
//            break;
//
//
//    }
    if(flag == 1){
        /// once again
        cout << "Insertion Sort" << endl;
        for(int i=0; i<n-1; i++){
            cout << a[i] << ' ';
        }
        cout << a[n-1];

    }
    else{
        cout << "Merge Sort" << endl;
        for(int step=2; step/2<=n; step*=2){//stepΪ����Ԫ�ظ���
            if(flag == 1)
                cnt++;
            for(int i=1; i<=n; i+=step){//��i������
                sort(c+i, c+min(i+step, n+1));
            }
            int k=0;
            for(k=0; k<n; k++){
                if(c[k+1] != b[k]){
                    break;
                }
            }
            if(k == n){
                flag = 1;
            }
            if(cnt)
                break;

        }
        for(int i=1; i<n; i++){
            cout << c[i] << ' ';
        }
        cout << c[n];
    }
    return 0;
}

/**
��д��������Ϊ�漣��bug
for(int i=0; i<n-1; i++){
        int j = i+1;
        int temp = a[j];
        while(j>0 && a[j] < a[j-1]){
            a[j] = a[j-1];
            j--;
        }
        a[j] = temp;
        ///compare
//        for(int k=0; k<n; k++){
//            if(a[k] == b[k]){
//                flag = 1;
//                break;
//            }
//        }
    }

**/
/**
10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0

Insertion Sort
1 2 3 5 7 8 9 4 6 0


10
3 1 2 8 7 5 9 4 0 6
1 3 2 8 5 7 4 9 0 6

Merge Sort
1 2 3 8 4 5 7 9 0 6
**/
