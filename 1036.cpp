/**********************
author: yomi
date: 18.3.27
ps:
**********************/
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int flag1 = 0, flag2 = 0;
    string name, sex, major, n1, n2, m1, m2, diff;
    int mark;
    int maxk = 0, mink=200;
    for(int i=0; i<n; i++){
        cin >> name >> sex >> major >> mark;
        if(sex == "M" && mark < mink){
            mink = mark;
            n1 = name;
            m1 = major;
            flag1 = 1;
        }
        else if(sex == "F" && mark > maxk){
            maxk = mark;
            n2 = name;
            m2 = major;
            flag2 = 1;
        }

    }
    if(flag1 && flag2){

        cout << n2 << ' ' << m2 << endl;
        cout << n1 << ' ' << m1 << endl;
        cout << abs(maxk-mink);
    }

    else if(flag1){

        cout << "Absent" << endl;
        cout << n1 << ' ' << m1 << endl;
        cout << "NA";
    }
     else if(flag2){

        cout << n2 << ' ' << m2 << endl;
        cout << "Absent" << endl;
        cout << "NA";
    }
    return 0;
}
/**
3
Joe M Math990112 89
Mike M CS991301 100
Mary F EE990830 95
*/
