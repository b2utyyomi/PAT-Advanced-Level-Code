/**********************
author: yomi
date: 18.8.26
ps: 内存超限22分 无法挽救
**********************/
///膜一膜柳神的代码以及分析
/**
题解：
1.合并排序，超时超内存（舍）
2.维护两个队列，比较对头大小,循环出队:原先的测试点可以通过的，
后来新版PAT加了内存限制，超内存（舍）
3.在2的基础上优化，第一个队列存好后，把第二个队列边读，
边和第一个队列比较，选择出队。这样可以不用一次
存完第二个队列，解决超内存的问题。
思路：第一、二个序列分别有n, m个元素，
所以需要从队头剔除（n + m – 1） / 2个元素，
最后答案就是两个队头的最小值。对于最终答案在第一
第二个队列中的情况要分开处理。若答案在第二个队列中，
在输入数据时就可以提前得出答案并退出，若答案在第一个队列中，
要二次出队才能找到答案。
注意：在所有元素入队列完毕后，
把INT_MAX入队列，一是这样队列永不为空，方便处理。
二是，题目的long int因为内存限制原因，并不会为最终答案，
只是干扰数据，所以每次遇到这样的干扰数据把他设为INT_MAX即可～
**/
#include <iostream>
#include <climits>
#include <queue>
using namespace std;
int main() {
    queue<int> a, b;
    long long tnum;
    int n, m, num, cnt = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%lld", &tnum);
        num = min((long long)INT_MAX, tnum);
        a.push(num);
    }
    a.push(INT_MAX);
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%lld", &tnum);
        int num = min((long long)INT_MAX, tnum);
        b.push(num);
        if(cnt == (n + m - 1) / 2) {
            printf("%d", min(a.front(), b.front()));
            return 0;
        }
        if(a.front() < b.front())
            a.pop();
        else
            b.pop();
        cnt++;
    }
    b.push(INT_MAX);
    for(; cnt < (n + m - 1) / 2; cnt++) {
        if(a.front() < b.front())
            a.pop();
        else
            b.pop();
    }
    printf("%d", min(a.front(), b.front()));
    return 0;
}
/**
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int ansn, ans, flag;
vector<int>a, b;
void merge_(int L1, int R1, int L2, int R2)
{
    int cnt = 1;
    int i=L1, j = L2;
    while(i<R1 && j<R2){
        if(a[i] <= b[j]){
            if(cnt == ansn){
                flag = 1;
                ans = a[i];
                break;
            }
            i++;
        }
        else{
            if(cnt == ansn){
                ans = b[j];
                flag = 1;
                break;
            }
            j++;
        }
        cnt++;
    }
    while(i<R1){
        if(cnt == ansn && !flag){
            ans = a[i];
            break;
        }
        cnt++;
        i++;
    }
    while(j<R2){
        if(cnt == ansn && !flag){
            ans = b[j];
            break;
        }
        cnt++;
        j++;
    }
}
int main()
{
    int n, m, aa, bb;
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d", &aa);
        a.push_back(aa);
    }
    scanf("%d", &m);
    for(int i=1; i<=m; i++){
        scanf("%d", &bb);
        b.push_back(bb);
    }
    ansn = (n+m+1)/2;
    //cout << ansn << endl;
    merge_(0, n, 0, m);
    printf("%d", ans);
    return 0;
}
**/
/**
Sample Input:
4 11 12 13 14
5 9 10 15 16 17
Sample Output:
13
**/
