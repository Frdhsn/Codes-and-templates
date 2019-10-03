// problem link: https://codeforces.com/gym/102267/problem/H

// radius of a polygon = r = S/2sin(180/n)
#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1.0)
double RToD(double rad)
{
    double haha = 180.0 / PI;

    return haha*rad;
}
double DToR(double rad)
{
    double haha =  PI / 180.0;

    return haha*rad;
}
int main ()
{

    double V,S;cin>>V>>S;
    double r = (S*1.0) / ( 2.0 * sin ( DToR( (180.0 / V*1.0 ) ) ));
    double area = PI*r*r;
    cout<<fixed<<setprecision(20)<<area<<endl;

    return 0;
}

