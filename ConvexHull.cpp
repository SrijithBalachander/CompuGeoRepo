/* The Implementation of Andrew's Monotone Chain Convex Hull Algo in 2D O(n log n)*/

#include<bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

struct Point{
    ll x, y;

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

ll crossp(const Point &O, const Point &A, const Point &B){
    return ((A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x));
}

vector <Point> revch(vector<Point> X)
{
    vector <Point> Y;
    int n=X.size();
    for(int i=0;i<n;i++)
        Y.pb(X[n-i-1]);

    return Y;
}

vector <Point> hull(vector <Point> P){
    int n=P.size(), k=0;
    vector<Point> X(2*n);
    sort(P.begin(), P.end());
    for(int i=0;i<n;i++){
        while(k>=2){
            if(crossp(X[k-2], X[k-1], P[i]) <= 0)
                k--;
            else
                break;}
        X[k++] = P[i];}
    for(int i=n-2, t=k+1;i>=0;i--){
        while(k>=t){
            if(crossp(X[k-2], X[k-1], P[i]) <= 0)
                k--;
            else
                break;}
        X[k++] = P[i];
    }
    /* X = revch (X); //for clockwise arrangement*/
    X.resize(k-1);
    return X;
}

int main()
{
    int N;
    cin>>N;
    Point Z;
    vector <Point> p;
    for(int i=0;i<N;i++)
    {
        cin>>Z;
        p.pb(Z);
    }
    vector <Point> ans;
    ans = hull(p);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i];

    cout<<endl;
    return 0;
}
