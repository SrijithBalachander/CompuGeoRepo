/* Area of a Polygon with given coordinates */

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

struct Point{
    double x, y;

    bool operator < (const Point &p) const{
        return (x < p.x || (x == p.x && y < p.y));}

    bool operator == (const Point &p) const{
        return (x == p.x && y==p.y);}

    friend ostream& operator << (ostream& s, Point& p){
        s << p.x <<" " << p.y << endl;
        return s;}
    friend istream& operator >> (istream& s, Point& p){
        s >> p.x >> p.y;}
};

double CoordArea(vector <Point> p){
    int N=p.size();
    double prod=0;
    for(int i=0;i<N;i++)
        prod+=((p[i%N].x * p[(i+1)%N].y) - (p[i%N].y * p[(i+1)%N].x));
    prod/= 2.0;
    return prod;
}
int main()
{
    int n;
    cin>>n;
    vector<Point> P;
    Point p;
    for(int i=0;i<n;i++)
    {
        cin>>p;
        P.pb(p);
    }
    double area;
    area = CoordArea(P);
    cout<< area <<endl;
    return 0;
}
