/**********************
author: yomi
date: 18.4.13
ps: ���ҵķ���������ʱ�临�Ӷ� ˲��û��������ȥ��������
�ؼ���Ҳû�������취��
������� ����취������
����˼· ���Ե�2 WA
�����������ʱ��ѡ����
Ӧ�ð��ź����peo��peo1
�������Ȱ�peo��peo1������
����
12345
35462
�ź���ȡһ���ֺͲ�����ȡһ�����ǲ�һ���� ���������

**********************/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
struct people
{
    string na;
    int age;
    int mon;
}peo[100010], peo1[100010];
int count_age[100010] = {0};
int cmp(people a, people b)
{
    if(a.mon!=b.mon)
        return a.mon > b.mon;
    else if(a.age!=b.age){
        return a.age < b.age;
    }
    else
        return a.na < b.na;
}

int main()
{
    int m, n, cnt = 0;

    //memset(count_age, 0, sizeof(count_age));
    cin >> m >> n;
    for(int i=0; i<m; i++){
        cin >> peo[i].na >> peo[i].age >> peo[i].mon;
//        count_age[peo[i].age]++;
//        if(count_age[peo[i].age]<100)
//            peo1[cnt++] = peo[i];
    }
    sort(peo, peo+m, cmp);
    for(int i=0; i<m; i++){
        if(count_age[peo[i].age] < 100){
            count_age[peo[i].age]++;
            peo1[cnt++] = peo[i];
        }

    }

    int c, AMin, AMax, c1 = 0;
    for(int i=0; i<n; i++){
        cin >> c >> AMin >> AMax;
        int flag = 1, c1 = 0;
        cout << "Case #" << i+1 <<":" << endl;
        for(int j=0; j<cnt; j++){
            if(c1 == c)
                    break;
            if(peo1[j].age >= AMin && peo1[j].age <=AMax){
                cout << peo1[j].na << ' '<< peo1[j].age<< ' ' << peo1[j].mon << endl;
                flag = 0;
                c1++;
            }
        }
        if(c1 == 0)
            cout << "None" << endl;

    }
    return 0;
}
/**
12 5
Zoe_Bill 35 2333
Bob_Volk 24 5888
Anny_Cin 95 999999
Williams 30 -22
Cindy 76 76000
Alice 18 88888
Joe_Mike 32 3222
Michael 5 300000
Rosemary 40 5888
Dobby 24 5888
Billy 24 5888
Nobody 5 0
4 15 45
4 30 35
4 5 95
1 45 50
20 3 8
**/
