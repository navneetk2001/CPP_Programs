//Approach :-
//GCD :- Greatest Common Divisor

Steps:-
//Diophantine Equation :- Polynomial Equation
// -> Integral Solution exists
// -> Unknown should be integers

// Linear Diophantine Equation :- ax + by = c
//  -> gcd(a,b) divides c


// Extended Euclid algorithm
// ax + by = gcd(a,b)   -> x and y are integers

//Time Complexity :- O(log2(max(a,b)))   if a>b

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


int main(){
	int a,b;
	cin>>a>>b;

	Triplet ans=extendedEuclid(a,b)
    cout<<"GCD is "<<ans.gcd<<endl;
    cout<<ans.x<<endl;
    cout<<ans.y<<endl;

    return 0;
}