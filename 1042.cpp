/**********************
author: yomi
date: 18.3.19
ps:  If the number at the i-th position is j,
it means to move the card from position i to position j.
太尴尬了 刚开始我挪反了
**********************/
#include <iostream>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

string to_string1(int n)
{
    string s = "";
    while(n){
        s += n%10+'0';
        n /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}
int main()
{
    map<int, string>mmap, mmap1;
    for(int i=1; i<=52; i++){
        string s1 = to_string1(i%13);
        if(i == 13)
            mmap[i] = "S13";
        else if(i == 26)
            mmap[i] = "H13";
        else if(i == 39)
            mmap[i] = "C13";
        else if(i == 52)
            mmap[i] = "D13";
        else if(i/13 == 0)
            mmap[i] =  "S"+s1;
        else if(i/13 == 1)
            mmap[i] = "H"+s1;
        else if(i/13 == 2)
            mmap[i] = "C"+s1;
        else{
            mmap[i] = "D"+s1;
        }
        //cout << s << endl;
    }
    mmap[53] = "J1";
    mmap[54] = "J2";
//    for(int i=1; i<=54; i++){
//        cout << mmap[i] << ' ' ;
//    }
    int n;
    int a[55];
    cin >> n;
    for(int i=1; i<=54; i++){
        cin >> a[i];
    }
    for(int i=0; i<n; i++){///也是绝了 我老是把n用具体的数字代替
        for(int j=1; j<=54; j++){
            mmap1[a[j]] = mmap[j];
            //cout << a[i] << " " <<  mmap1[j] << endl;
        }

        for(int j=1; j<=54; j++){
            mmap[j] = mmap1[j];
            //cout << mmap1[j] << ' ';
        }
        //cout << endl;
    }
    for(int i=1; i<=53; i++){
        cout << mmap[i] << ' ';
    }
    cout << mmap[54];
    return 0;
}

/*
2
36 52 37 38 3 39 40 53 54 41 11 12 13 42 43 44 2 4 23 24 25 26 27 6 7 8 48 49 50 51 9 10 14 15 16 5 17 18 19 1 20 21 22 28 29 30 31 32 33 34 35 45 46 47
*/
