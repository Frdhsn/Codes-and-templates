// radius of a polygon = r = S/2sin(180/n)
#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1.0)
double RToD(double rad) // radian to degrees
{
    double haha = 180.0 / PI;
 
    return haha*rad;
}
double DToR(double rad) // degrees to radians
{
    double haha =  PI / 180.0;
 
    return haha*rad;
}
