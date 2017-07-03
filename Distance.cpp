#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;

struct Point{
    double x, y;

    bool operator < (const Point &p) const{
        return (x < p.x || (x == p.x && y < p.y));}

    bool operator == (const Point &p) const{
        return (x == p.x && y==p.y);}

    bool operator != (const Point &p) const{
        return (x!=p.x || y!=p.y);
    }

    friend ostream& operator << (ostream& s, Point& p){
        s << p.x <<" " << p.y << endl;
        return s;}
    friend istream & operator >> (istream& s, Point& p){
        s >> p.x >> p.y;
        return s;}
};

double dist_points(Point X, Point Y)
{
	double x = (Y.x-X.x)*(Y.x-X.x);
	double y = (Y.y-X.y)*(Y.y-X.y);
	return sqrt(x+y);
}
