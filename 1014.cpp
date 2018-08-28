/**********************
author: yomi
date: 18.8.27
ps: һ����Сʱ ֻ�������� ������T^T �� ϸ˼���� �ദ�߼�©��
�о����Ĳ���� Ȼ������ֻ��ʮ���� ���˰��� �������
쭵�22��Ҳ����
����Ҫ�������
�������ı����֮�� ��ȫ��������˼· ������ȥ����
һ�ι� ���Ǹо�ֻ��һ�� �����Լ�̫��ѽ
**********************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdio>
using namespace std;

const int maxn = 1001;
int ansTime[maxn], needTime[maxn];
struct window
{
    int endTime, popTime;
    queue<int>q;
}w[maxn];
int n, m, k, q, qcnt, query;
int main()
{
    int index = 0;
    cin >> n >> m >> k >> q;
    for(int i=0; i<k; i++){
        cin >> needTime[i];
    }
    for(int i=0; i<n; i++){
        w[i].endTime = w[i].popTime = 8*60;
    }

    for(int i=0; i<min(n*m, k); i++){///����д�ļ�����(*v*)
        w[index%n].q.push(index);
        w[index%n].endTime += needTime[index];
        if(index<n){
            w[index%n].popTime += needTime[index];
        }
        ansTime[index] = w[index%n].endTime;
        index++;
    }
    for(; index<k; index++){
        int uid = -1, minPopTime=1000000, wid=-1;
        for(int i=0; i<n; i++){
            if(w[i].popTime < minPopTime){
                minPopTime = w[i].popTime;
                wid = i;
            }
        }
        w[wid].q.pop();
        int id = w[wid].q.front();
        w[wid].popTime += needTime[id];
        w[wid].endTime += needTime[index];
        ansTime[index] = w[wid].endTime;

    }
    for(int i=0; i<q; i++){
        cin >> query;
        int ans = ansTime[query-1];
        if(ansTime[query-1]- needTime[query-1]< 17*60){
            printf("%02d:%02d\n", ans/60, ans%60);
        }
        else{
            cout << "Sorry" << endl;
        }
    }

    return 0;
}
/**
2 10 7 5
1 2 6 4 3 534 2
3 4 5 6 7
**/
/** 22'����
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

const int maxn = 1001;
int ansTime[maxn], startTime[maxn];
vector<int>q[25];
int n, m, k, qu, cus[maxn];
int main()
{
    cin >> n >> m >> k >> qu;
    for(int i=1; i<=k; i++){
        cin >> cus[i];
    }
    ///��������
    int cnt = 1, flag=0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(cnt > k){///���� ���ﱾ��û�����������ڶ������������
                break;///����֮���쭵�22��
            }
            q[j].push_back(cnt);
            cnt++;
        }
        if(flag)
            break;
    }
    int time = 8*60;
    int cntp = 1;
    while(cnt <= k){
        int finishT=10000000, finishID=-1, uid=-1;
        for(int i=0; i<n; i++){
            if(q[i].size() > 0){
                int id = q[i][0];
                if(cus[id]<finishT){
                    finishT = cus[id];
                    finishID = i;
                    uid = id;
                }
            }

        }
//        cout << "uid: " << uid << endl;
//        cout << "timeb: " << time << endl;
        startTime[uid] = time;
        time += finishT;
        //cout << "timea: " << time << endl;
        for(int i=0; i<n; i++){
            if(q[i].size() > 0){
                int id = q[i][0];
                cus[id] -= finishT;
            }
        }
        ansTime[uid] = time;
        //cout << finishID << endl;
        //ansTime[cntp++] = time;
        q[finishID].erase(q[finishID].begin());
        q[finishID].push_back(cnt);
        cnt++;
        cntp++;
    }
    while(cntp <= k){
        int finishT=10000000, finishID=-1, uid = -1;
        for(int i=0; i<n; i++){
            if(q[i].size() > 0){
                int id = q[i][0];
                if(cus[id]<finishT){
                    finishT = cus[id];
                    finishID = i;
                    uid = id;
                }
            }
        }
        startTime[uid] = time;
//        cout << "uid: " << uid << endl;
//        cout << "timeb: " << time << endl;

        time += finishT;
        //cout << "timea: " << time << endl;
        for(int i=0; i<n; i++){
            if(q[i].size() > 0){
                int id = q[i][0];
                cus[id] -= finishT;
            }
        }

        ansTime[uid] = time;

        q[finishID].erase(q[finishID].begin());
        cntp++;


    }



//    for(int i=1; i<cntp; i++){
//        printf("%02d:%02d\n", startTime[i]/60, startTime[i]%60);
//
//    }
    int query;
    for(int i=0; i<qu; i++){
        cin >> query;
        int ans = ansTime[query];
        if(startTime[query] < 17*60){
            printf("%02d:%02d\n", ans/60, ans%60);
        }
        else{
            cout << "Sorry" << endl;
        }
    }
    return 0;
}
**/
/**
Sample Input:
2 2 7 5
1 2 6 4 3 534 2
3 4 5 6 7
Sample Output:
08:07
08:06
08:10
17:00
Sorry
**/
