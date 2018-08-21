/**********************
author: yomi
date: 18.6.15
ps:
long long int ���ڴ泬��
�ĵ���֮�� ��ʣ���һ�������ڴ泬�ޡ���ʱ���ơ�
����һ�����⣺ Ϊɶcnt < midPos����Ϊ����Ҫ�ҵ���midPos�� cnt == midPos����ѭ������ʱ�Ƚ�a[i],b[j]���ý����
��һֱ���� Ϊʲô�±�Ϊ0�����±�Ϊ1�� ����cnt<midPos, ��ϸ��һ�룬 �±�Ϊ0����1ֻ�Ǿ�����cnt�ĳ�ֵ��0����1��
�����˳���������cnt<midPos,��Ϊ����Ҫ�ҵ���midPos�� cnt == midPos����ѭ������ʱ�Ƚ�a[i],b[j]���ý����
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
    a[n+1] = inf, b[m+1] = inf;///����Ϊ����ֻ�Ƿ�ֹһ������ɨ���꣬���������Խ��ġ�Ȼ��������Ŀɲ�ֹ��Щ��
    int midPos = (m+n+1)/2; /// 12345         ///���Ƚϵ�ʱ�������һ������ɨ�����ˣ��Ǿ��������������һ��Ԫ�ص���һ��Ԫ��
    int i=1, j=1;                              ///����һ������ĵ�ǰԪ�رȴ�С�ˣ���ͳ��������ˣ����������һ��Ԫ�ص���һ��Ϊinf
    while(cnt < midPos /*&& i<=n && j<=mû��Ҫ*/){        ///���ֱ��memsetΪinf��
        if(a[i] < b[j]){
            i++;
        }
        else{
            j++;
        }
        cnt++;
    }
//    while(cnt<midPos && i<=n){   ///������inf �����û��Ҫд��
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

