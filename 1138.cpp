/******************************
author:yomi
date:18.9.4
ps: cin cout 也是会超时的
******************************/
#include<iostream>
#include <cstring>
#include <cstdio>
using namespace std;

struct node
{
    int data;
    node* l;
    node* r;
};
const int maxn = 50010;
int pre[maxn], in[maxn], n;
int cnt;
bool flag = false;
node* create(int preL, int preR, int inL, int inR)
{
    if(preL > preR || flag == true){
        return NULL;
    }
    node* root = new node;
    root->data = pre[preL];
    int k = 0, j;
    for(int i=inL; i<=inR; i++){
        k++;
        if(pre[preL] == in[i]){
            ///这里利用k去统计左子树节点数是不正确的 经测试 当只有两个节点 即只有根节点和一个左孩子 是不会出正确结果的 T^T 原来是我的区间推错了
            j = i;/// 2   现在利用k也没问题了
            break;/// 1 3
                  /// 3 1
        }
    }
    int numLeft = j-inL;
//    root->l = create(preL+1, preL+numLeft, inL, j-1);   ///AC
//    root->r = create(preL+numLeft+1, preR, j+1, inR);
    root->l = create(preL+1, preL+k-1, inL, j-1);   ///AC
    root->r = create(preL+k, preR, j+1, inR);

    if(flag == false){
        //cout << root->data;
        printf("%d", root->data);
        flag = true;
    }

    return root;
}
//
//void po(node* root)
//{
//    if(flag == true){
//        return;
//    }
//    if(root->l){
//        po(root->l);
//    }
//    if(root->r){
//        po(root->r);
//    }
//
//    if(flag == false){
//        cout << root->data;
//        flag = true;
//    }
//
//}
int main()
{
    //cin >> n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        //cin >> pre[i];
        scanf("%d", &pre[i]);
    }
    for(int i=1; i<=n; i++){
        //cin >> in[i];
        scanf("%d", &in[i]);
    }

    node *root;
    root = create(1, n, 1, n);
    ///建好树后再后序遍历是会超时的
    //po(root);
    //cout << post[0];
    return 0;
}

/**
7
1 2 3 4 5 6 7
2 3 1 5 4 7 6

**/
