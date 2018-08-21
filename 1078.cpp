/**********************
author: yomi
date: 18.7.2
ps: ������ͻ������Ȼֻ�����һ�����Ե�WA��˵�����Ǹ���
����ƽ��̽�ⷨ���˻�·��
**********************/
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
bool vis[10010]={false};
int s[10010];
int ans[10010];
int Msize;
bool isPrime(int n)
{
    if(n<=1)
        return false;
    int sqr = (int)sqrt(1.0*n);
    for(int i=2; i<=sqr; i++){
        if(n%i == 0)
            return false;
    }
    return true;
}
int Hash(int n)
{
    return n%Msize;
}
void collision(int t, int num)
{
    int step=1;
    int pos = Hash(num+step*step);
    int flag = 1;
    while(step < Msize){
        if(!vis[pos]){
            vis[pos] = true;
            cout << pos;
            flag = 0;
            break;
        }
       step++;
       pos = Hash(num+step*step);
    }
    if(flag){
        cout << "-";
    }
}

int main()
{
    int n;
    cin >> Msize >> n;
    if(!isPrime(Msize)){
        ///Msize+=1;//�����ҵ���һ������������� �ϸ� �����������������
        for(int i=Msize+1; i<100010; i++){
            if(isPrime(i)){
                Msize = i;
                break;
            }
        }
    }
    for(int i=0; i<n; i++){
        cin >> s[i];
    }
    for(int i=0; i<n; i++){
        int t = Hash(s[i]);
        if(!vis[t]){
            vis[t] = true;
            cout << t;
        }
        else{
            collision(t, s[i]);
        }
         if(i!=n-1){
            cout << " ";
        }

    }
    return 0;
}
/**
4 4
10 6 4 15

0 1 4 -
**/
