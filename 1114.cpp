/******************************
author:yomi
date:18.8.29
ps: 我的天 写了将近两个小时
虽然说一次就过了 但是这时间也太长了吧
收拾收拾行李 我这次真的要凉了 凉吧凉吧
凉不凉我都得把题刷完 连带着初试一起凉吧
******************************/
#include<iostream>
#include <map>
#include <algorithm>
#include <cstdio>
#include <set>
using namespace std;
const int maxn = 100010;
int father[maxn];
int isRoot[maxn], root[maxn];
map<int, int>mmap, mmap1;
struct family
{
    int id;
    double avg_area;
    int num;
    double avg_total;
    double M, A;

}fam[maxn], bfam[maxn];
void init(int n)
{
    for(int i=1; i<=10010; i++){
        father[i] = i;
        isRoot[i] = 0;
    }
}
int findfather(int v)
{
    if(v == father[v]){
        return v;
    }
    else{
        int F = findfather(father[v]);
        father[v] = F;
//        fam[F].M += fam[v].M;
//        fam[F].A += fam[v].A;
        return F;
    }
}
void Union(int a, int b)
{
    int fa = findfather(a);
    int fb = findfather(b);
    if(fa!=fb){
        father[fa] = father[fb];
//        fam[fa].M += fam[fb].M;
//        fam[fa].A += fam[fb].A;

    }
}
int convert(int id)
{
    int s = mmap.size();
    if(mmap.find(id) == mmap.end()){
        mmap[id] = s+1;
        return s+1;
    }
    else{
        return mmap[id];
    }
}
int cmp(family a, family b)
{
    if(a.avg_area != b.avg_area){
        return a.avg_area > b.avg_area;
    }
    else
        return a.id < b.id;
}
int main()
{
    int n, id, fid, mid, cid, k, fid1, mid1, cid1;
    cin >> n;
    init(n);
    mmap.clear();
    mmap1.clear();
    for(int i=0; i<n; i++){
        id=-1, fid=-1, mid=-1, cid=-1, k,fid1=-1, mid1=-1, cid1=-1;
        cin >> id >> fid >> mid >> k;
        int id1 = convert(id);
        mmap1[id1] = id;
        if(fid!=-1){
            fid1 = convert(fid);
            mmap1[fid1] = fid;
            Union(id1, fid1);
        }

        if(mid!=-1){
            mid1 = convert(mid);
            mmap1[mid1] = mid;
            Union(id1, mid1);
        }

        for(int j=0; j<k; j++){
            cin >> cid;
            cid1 = convert(cid);
            mmap1[cid1] = cid;
            Union(id1, cid1);
        }
        cin >> fam[id1].M >> fam[id1].A;
        //cout << endl <<  "start: " << id1 << ' ' << fid1 << ' ' << mid1  << endl;
    }
    int s = mmap.size();
//    for(map<int, int>::iterator iter=mmap.begin(); iter!=mmap.end(); ++iter){
//        cout << iter->first << ' ' << iter->second << endl;
//    }
    for(int i=1; i<=s; i++){
        isRoot[findfather(i)]++;
    }
    int cnt = 0, cnt_root = 0;
    for(int i=1; i<=s; i++){
        if(isRoot[i]!=0){
            /// index   --->  num
            ///cout << mmap1[i]  << ' ' << isRoot[i] << endl;
            root[cnt_root++] = i;


        }
    }
    int min_id=10000000;
    int cnt1=0;
    for(int j=0; j<cnt_root; j++){
        min_id=10000000, cnt1 = 0;
        for(int i=1; i<=s; i++){
            if(father[i] == root[j]){
                //cout << mmap1[i] << ' ' << min_id << endl;
                if(mmap1[i] < min_id){
                    bfam[cnt].id = mmap1[i];
                    min_id = mmap1[i];
                }
                bfam[cnt].M += fam[i].M;
                bfam[cnt].A += fam[i].A;
                cnt1++;
            }

        }
        bfam[cnt].num = cnt1;
        ///我写在cnt后面了 花了五分钟才找到BUG
        bfam[cnt].avg_total = bfam[cnt].M/cnt1;
        bfam[cnt].avg_area = bfam[cnt].A/cnt1;
//        cout << cnt1 << endl;
//        cout << bfam[cnt].M << ' ' <<  bfam[cnt].A << endl;
//        cout << bfam[cnt].avg_total << ' ' <<  bfam[cnt].avg_area << endl;
        cnt++;

    }
    sort(bfam, bfam+cnt, cmp);
    cout << cnt << endl;
    for(int i=0; i<cnt; i++){
       // cout << bfam[i].id << ' ' << bfam[i].M << ' ' <<  bfam[i].A << endl;
        printf("%04d %d %.3f %.3f\n", bfam[i].id, bfam[i].num, bfam[i].avg_total, bfam[i].avg_area);
    }
    return 0;
}
/**
10
6666 5551 5552 1 7777 1 100
1234 5678 9012 1 0002 2 300
8888 -1 -1 0 1 1000
2468 0001 0004 1 2222 1 500
7777 6666 -1 0 2 300
3721 -1 -1 1 2333 2 150
9012 -1 -1 3 1236 1235 1234 1 100
1235 5678 9012 0 1 50
2222 1236 2468 2 6661 6662 1 300
2333 -1 3721 3 6661 6662 6663 1 100
**/
