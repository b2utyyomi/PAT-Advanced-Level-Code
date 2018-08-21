/**********************
author: yomi
date: 18.5.10
ps:
**********************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    int n, d;
    int cnt[100010], a[100010];
    //while(cin >> n){
        cin >> n;
        memset(cnt, 0, sizeof(cnt));
        for(int i=0; i<n; i++){
            cin >> a[i];
            cnt[a[i]]++;
        }
        int i;
        for(i=0; i<n; i++){
            if(cnt[a[i]] == 1){
                cout << a[i] << endl;
                break;
            }
        }
        if(i == n)
            cout << "None" << endl;
//        vector<int>vec; 故意试了一下 果然慢如蜗牛
//        for(int i=0; i<n; i++){
//            cin >> d;
//            vec.push_back(d);
//        }
//        int i;
//        for(i=0; i<vec.size(); i++){
//            if(count(vec.begin(), vec.end(),vec[i]) == 1){
//                cout << vec[i] << endl;
//                break;
//            }
//        }
//        if(i == vec.size())
//            cout << "None" << endl;
   // }

    return 0;
}

/**
7 5 31 5 88 67  88 17

31

5 888 666 888 666 888
**/
