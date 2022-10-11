// Consider the set of irreducible fractions A = {n/d | n≤d and d ≤ 10000 and gcd(n,d) = 1}.You are given a member of this set and your task is to find the largest fraction in this set less than the given fraction.
// Note : this is a set and all the members are unique.

// Example 1:
// Input: n = 1, d = 4
// Output: {2499, 9997}  
// Explanation: 2499/9997 is the largest fraction.

// Example 2:
// Input: n = 2, d = 4
// Output: {4999, 9999}
// Explanation: 4999/9999 is the largest fraction. 


//Solution Approach :-
// Algorithm : 
// 1. Start with a fraction ( I started with 10000/10000 ).
// 2. decrease numerator until current ratio becomes smaller than required ratio.
// 3. Now decrease denominator until current ratio becomes bigger than required ratio.
// 4. (current-denominator - 1) would be closest ratio found TILL NOW.
// 5. Repeat steps 2-4 to achieve all the fractions whose ratio is close to required ratio. Keep check on best ratio found till now. The one with closest ratio is our answer.
// 6. Return by dividing by their gcd ( turns out without this step, the codes works too, I have no proof of this).

vector<int> numAndDen(int n, int d) {
    int num=0, deno=1;
    for(int q=10000;q>=2;q--){
    	int p=(n*q-1)/d;
    	if(p*deno>=q*num){
    		deno=q;
    		num=p;
    	}
    }
    int g=__gcd(num,deno);
    vector<int>ans;
    ans.push_back(num/g);
    ans.push_back(deno/g);

    return ans;
}



//Second Solution :-
vector<int> numAndDen(int n, int d) {
    int num=-1, den=1;
    for(int y=d+1; y<=10000; y++) {
        int x = (n*y)/d;
        if(__gcd(x,y) == 1) {
            if(1.0*x/y > 1.0*num/den)
                num=x, den=y;
        }
    }
    return {num, den};
}



//Third Solution :-
vector<int> numAndDen(int n, int d) {
   double num = (double)n / (double)d;
   vector<int>ans;
   double mx = 0;
   for(int i=2 ; i<10000 ; i++)
   {
       int j = n * i / d;
       double num2 = (double)j / (double)i;
       if(num2 < num  && mx < num2 && __gcd(i , j) == 1)
       {
           mx = num2;
           ans = {j , i};
       }
   }
   return ans;
}
