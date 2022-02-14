//Approach :- Multiplicative Modulo Inverse
//First we will know about multiplicative inverse
// if A*B=1 then B=1/A and it is called multiplicative inverse

//Now what is Multiplicative Modulo Inverse :-
// It will be (A*B) mod m = 1
// We can say A.B = 1 (mod m)
// (A*B -1) mod m = 0
// (A*B -1) = mq ( where it is a multiple of m and q should be integer)
// (A*B) - mq = 1 
//We can write above as (A.B) + mQ = 1   as Ax + By = C
//gcd(A,M) divides 1  => gcd(A,M) = 1


#include<bits/stdc++.h>
using namespace std;

class Triplet{
public:
	int x;
	int y;
	int ans;
};

Triplet extendedEuclid(int a, int b){
	if(b==0){       //base case :- gcd(n,0) = n
		Triplet ans;
		ans.gcd=a;
		ans.x=1;
		ans.y=0;
		return ans;
	}

	//Extended Euclid Algorithm
	Triplet smallAns = extendedEuclid(b, a%b);
	
	Triplet ans;
	ans.gcd = smallAns.gcd;
	ans.x = smallAns.x;
	ans.y = smallAns.y;
	return ans;
}

//Multiplicative Modulo Inverse Function :-
int mmInverse(int a, int m){
	Triplet ans = extendedEuclid(a,m);
	return ans.x;
}

int main(){
	int a,m;
	cin>>a>>m;

	Triplet ans=mmInverse(a,m)
    cout<<"Multiplicative Modulo Inverse is "<<ans<<endl;

    return 0;
}