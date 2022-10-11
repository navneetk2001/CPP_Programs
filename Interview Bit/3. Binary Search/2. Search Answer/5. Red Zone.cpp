// There are many people who believe that the earth is flat and NASA is a scam. They call themselves Flat Earthers. They were already worried that the 6 feet social distancing rule might push some people out of the earth.
// Now, they decided to think about a new issue. Since the earth is flat ( or so they think), let's imagine it as an infinite 2D grid. They have the coordinates of certain points which are orange zones and have some COVID-19 cases reported. Now each day the orange zones become more fatal. After d days, all the locations within a euclidean distance of d of a particular orange zone can be affected by this zone.
// They know N orange zones, each of whose coordinates are given by (A[i][0], A[i][1]). Now, a location is considered a red zone if it is affected by at least B orange zones. You need to find the first day at which the first red zone is reported.


// Input 1:
//   A : 
//   [
//     [8, 5]
//     [0, 4]
//     [3, 6]
//   ]
//   B : 3
// Output 1:  5
// Explanation 1:  One of the red zones will be (5, 4) and it is within a distance of 5 from all the orange zones.

// Input 2:
//   A : 
//   [
//     [2, 3]
//     [9, 4]
//     [10, 3]
//   ]
//   B : 2
// Output 2:  1
// Explanation 2:  One of the red zones will be (9, 3) and it is within a distance of 1 from 2 orange zones.



//Solution :-
#include<bits/stdc++.h>
typedef double C;
typedef complex<C> P;
#define X real()
#define Y imag()
P a[205];
int n, x, y, k;
bool check(int r){
    int c=0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            P g = a[j] - a[i];
            double d = abs(g);
            if(d > 2*r) continue;
            P mid = (a[i] + a[j]) * (1.0/2);
            double h = sqrt(r*1.0*r - d*d/4);
            P per = P(-g.Y,g.X) * (h/d);
            int c1 = 2, c2 = 2;
            for(int l = 0; l < n; l++){
                if(l == i or l == j) continue;
                if(abs(a[l] - (mid-per)) <= r)
                    c1++;
                if(abs(a[l] - (mid+per)) <= r)
                    c2++;
            }
            c=max({c,c1,c2});
        }
    }
    return c>=k;
}
int Solution::solve(vector<vector<int> > &A, int B) {
    n = A.size();
    for(int i = 0; i < n;i++)
        a[i] = {1.0*A[i][0], 1.0*A[i][1]};
    k = B;
    int l = 1, h = 2000000000, ans;
    while(h >= l){
        int m = (l+h)/2;
        if(check(m)) {
            ans = m;
            h = m-1;
        }
        else l = m+1;
    }
    return ans;
}



//Second Solution :-
long double dist(pair<long double,long double>a, pair<long double,long double>b){
    return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}
bool check(vector<pair<long double,long double>>A, int B,long double d){
    d*=d;
    for(int i=0;i<A.size();i++){
        for(int j=i+1;j<A.size();j++){
           // pair<long double,long double> A[i] = A[i], A[j] = A[j];
            long double h = dist(A[i],A[j]);
            long double D = (4*d-h)/h;
            if(4*d-h>=0.0){
                int cn1=0,cn2=0;
                pair<long double,long double>x,y;
                x.first = ((A[i].first+A[j].first)+sqrt(D)*(A[i].second-A[j].second))/2;
                x.second = ((A[i].second+A[j].second)+sqrt(D)*(A[j].first-A[i].first))/2;
                y.first = ((A[i].first+A[j].first)-sqrt(D)*(A[i].second-A[j].second))/2;
                y.second = ((A[i].second+A[j].second)-sqrt(D)*(A[j].first-A[i].first))/2;
                for(int k=0;k<A.size();k++){
                    if(dist(x,A[k])<=d+0.1)cn1++;
                    if(dist(y,A[k])<=d+0.1)cn2++;
                }
                if(cn1>=B){
                    return true;
                }
                if(cn2>=B){
                    return true;
                }
            }
        }
    }
    return false;
}
int Solution::solve(vector<vector<int> > &A, int B) {
    vector<pair<long double,long double>>C;
    int r = 0, l=0;
    for(int i=0;i<A.size();i++){
        long double xcoor=A[i][0]*(1.0);
        long double ycoor=A[i][1]*(1.0);
        r=max({r,A[i][0],A[i][1]});
        C.push_back({xcoor,ycoor});
    }
    while(l<=r){
        int mid = l + (r-l)/2;
        if(check(C,B,mid))
            r = mid-1;
        else l = mid+1;
    }
    return l;
}
