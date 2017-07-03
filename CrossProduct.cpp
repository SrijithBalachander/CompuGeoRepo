#include<bits/stdc++.h>
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
    friend istream & operator >> (istream& s, Point& p){
        s >> p.x >> p.y;
        return s;}
};

double crossp(const Point &O, const Point &A, const Point &B){
    return ((A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x));
}
