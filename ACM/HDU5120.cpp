/*************************************************************************
	> File Name: HDU5120.cpp
	> Author:
	> Mail:
	> Created Time: 2018年11月04日 星期日 13时29分38秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define ll long long
#define PI acos(-1.0)
struct node
{
    double x ,y;
    double r;
};

double dist(node o1, node o2)
{
    double ans = sqrt((o1.x-o2.x)*(o1.x-o2.x)+(o1.y-o2.y)*(o1.y-o2.y));
    return ans;
}

double cal(node o1, node o2)
{
    double len = dist(o1, o2);
   //  cout << len << endl;
    double r1 = o1.r, r2 = o2.r;
    if(len+min(o1.r, o2.r) <= max(o1.r, o2.r))
    {
        double r = min(o1.r, o2.r);
       //  cout << r<< " "  << PI*r*r << endl;
        return PI*r*r;
    }
    else if(len >= o1.r+o2.r)
    {
        return 0.00;
    }
    else
    {
       double d1=2*acos((o1.r*o1.r+len*len-o2.r*o2.r)/(2*o1.r*len));
       double d2=2*acos((o2.r*o2.r+len*len-o1.r*o1.r)/(2*o2.r*len)); // 利用圆心角求得扇形面积再减去三角形面积后两部分相加就是相交部分面积
       double area1=o1.r*o1.r*d1/2-o1.r*o1.r*sin(d1)/2;
       double area2=o2.r*o2.r*d2/2-o2.r*o2.r*sin(d2)/2;
       double area=area1+area2;
       return area;
       }

}

int main()
{
   // freopen("input.txt","r", stdin);
    int t;
    cin >> t;
    int j = 0;
     while(j++ < t)
    {
        node o1, o2, o3, o4;
       scanf("%lf%lf%lf%lf%lf%lf",&o3.r,&o1.r,&o1.x,&o1.y,&o2.x,&o2.y);
        o3.x = o1.x, o3.y = o1.y, o2.r = o1.r;
        o4.r = o3.r, o4.x = o2.x, o4.y = o2.y;
        double res = cal(o1, o2)+cal(o3,o4)-cal(o3,o2)-cal(o4,o1);
        cout << "Case #" << j << ": ";
        printf("%.6lf\n",res);
    }
    return 0;
}
