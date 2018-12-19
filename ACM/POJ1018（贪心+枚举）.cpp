#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <string.h>
using namespace std;
#define eps 1e-8
typedef long long LL;
struct point {
    double width;
    double price;
    bool operator<(double a)
    {
        return width<a;
    }
} points[105][105];
double ans[105][105];
int num[105];
int n;
bool operator<(point a,point b)
{
    return a.width<b.width;
}
int main()
{
    int tt;
    cin>>tt;
    while(tt--)
    {
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            scanf("%d",num+i);
        for(int j=0; j<num[i]; j++)
        {
            scanf("%lf%lf",&points[i][j].width,&points[i][j].price);
        }
        sort(points[i],points[i]+num[i]);
        ans[i][num[i]-1]=points[i][num[i]-1].price;
        for(int j=num[i]-2; j>=0; j--)
            ans[i][j]=min(points[i][j].price,ans[i][j+1]);
        }
        double ans1=0; for(int i=0; i<n; i++)
        {
            for(int j=0; j<num[i]; j++)
            {
                double tool=points[i][j].width,sum=points[i][j].price;
                bool flag=1;
                int pp=0;
                for(int k=0; k<n; k++)
                {
                    if(k==i)continue;
                    int t=lower_bound(points[k],points[k]+num[k],tool)-points[k];
                    if(t==num[k]) { flag=0; break; }
                    else { sum+=ans[k][t]; pp=t; }
                    if(tool/sum<ans1) { flag=0; break; }
                }sh
                if(flag) ans1=
    }
    return 0;
}
