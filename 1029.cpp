/**********************
author: yomi
date: 18.6.15
ps:
long long int 都内存超限
改掉了之后 还剩最后一个样例内存超限。暂时弃疗。
还有一个问题： 为啥cnt < midPos？因为我们要找的是midPos啊 cnt == midPos跳出循环，此时比较a[i],b[j]即得结果。
我一直纠结 为什么下标为0还是下标为1， 都是cnt<midPos, 仔细想一想， 下标为0还是1只是决定了cnt的初值是0还是1，
最终退出条件都是cnt<midPos,因为我们要找的是midPos啊 cnt == midPos跳出循环，此时比较a[i],b[j]即得结果。
**********************/
#include <cstdio>

///--- O(logn) ---
const int maxn = 1000002;
const int inf = 0x7fffffff;
int a[maxn], b[maxn];

int main()
{
    int n, m, cnt = 1;
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
    }
    scanf("%d", &m);
    for(int i=1; i<=m; i++){
        scanf("%d", &b[i]);
    }
    a[n+1] = inf, b[m+1] = inf;///我以为这里只是防止一个数组扫描完，会造成数组越界的。然而这句做的可不止这些。
    int midPos = (m+n+1)/2; /// 12345         ///最后比较的时候，如果有一个数组扫描完了，那就是这个数组的最后一个元素的下一个元素
    int i=1, j=1;                              ///和另一个数组的当前元素比大小了，这就出现问题了，必须让最后一个元素的下一个为inf
    while(cnt < midPos /*&& i<=n && j<=m没必要*/){        ///最后直接memset为inf吧
        if(a[i] < b[j]){
            i++;
        }
        else{
            j++;
        }
        cnt++;
    }
//    while(cnt<midPos && i<=n){   ///加上了inf 这里就没必要写了
//        i++;
//        cnt++;
//    }
//    while(cnt<midPos && j<=m){
//        j++;
//        cnt++;
//    }
    //cout << i << ' ' << j <<endl;
    if(a[i] < b[j])
        printf("%d", a[i]);
    else
        printf("%d", b[j]);
    return 0;
}

/**
4 11 12 13 14
5 9 10 15 16 17
13
**/

/**    ---   O(nlogn)  ----
long long int a[2000010];

int Partition(int left, int right)
{
    int temp = a[left];
    while(left < right){
        while(left<right && a[right]>temp){
            right--;
        }
        a[left] = a[right];
        while(left<right && a[left]<=temp){
            left++;
        }
        a[right] = a[left];
    }
    a[left] = temp;
    return left;
}
void quicksort(int left, int right)
{
    if(left < right){
        int pos = Partition(left, right);
        quicksort(left, pos-1);
        quicksort(pos+1, right);

    }

}
int main()
{
    int n, m;
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%lld", &a[i]);
    }
    scanf("%d", &m);
    for(int i=1; i<=m; i++){
        scanf("%lld", &a[i+n]);
    }
    //sort(a, a+m+n);
    quicksort(1, m+n);
//    for(int i=1; i<=m+n; i++){
//        cout << a[i] <<' ';
//    }
    printf("%lld", a[(m+n+1)/2]);

    return 0;
}
**/

