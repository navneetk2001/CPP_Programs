// Given a number n. The task is to find the smallest number whose factorial contains at least n trailing zeroes.

// Example 1:
// Input:
// n = 1
// Output: 5
// Explanation : 5! = 120 which has at least 1 trailing 0.

// Example 2:
// Input:
// n = 6
// Output: 25
// Explanation : 25! has at least 6 trailing 0.




//Solution Approach :-
// Concept: Number of trailing zeros= min( number of 5's, number of 2's);
// For calculating the trailing zeros in factorial, it can be shown that the number of 5's is always smaller or equal than number of 2's. That's why 
// we calculate only number of 5's not both.
// And 
// Count of 5's=(n/5+n/25+n/125+……)
// n/5= number of 5's
// n/25=number of 25's (In 25, (5*5) there are 2 fives one five is already considered in the previous iteration).
// n/125=number of 125's ((In 125, (5*5*5) there are 3 fives two fives are already considered in the previous iteration two iteration)
// So on…….

int get_count(int n){
    int cnt=0;
    while(n>=5){
        cnt=cnt+(n/5);
        n=n/5;
    }
    return cnt;
}

int findNum(int n){
    int low=0,high=1e9,ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        int cnt=get_count(mid);      //counting the number of 5's, 25's and 125's and so on
        
        if(cnt>=n){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}




//Second Solution :-
int findNum(int n)
{
    int low = 0;
    int high = n * 5;
    int ans = high;

    while(low <= high){
        int mid = low + (high - low)/2;
        int x = 5;
        int total = 0;
        while(x <= mid){
            total += mid/x;
            x *= 5;
        }

        if(total < n){
            low = mid + 1;
        }
        else if(total > n){
            high = mid - 1;
            ans = min(ans, mid);
        }
        else{
            ans = mid;
            break;
        }
    }
    ans -= ans % 5;
    return ans;
}




//Third Solution :-
int help(int a){
    int temp = a; 
    int res = 0; 
    for(int i = 5; i <= a; i *=5 ){ 
        res += temp/i; 
    } 
    return res;
}

int findNum(int n){
  	int l=0;
  	int h=5*n;
  	int ans=0;
  	while(l<=h)
    {
      	int m = (l+h)/2;
      	int zeroes = help(m);
      	if(zeroes >= n){
          	ans=m;
          	h=m-1;
      	}
      	else{
        	l=m+1;
      	}
    }
	return ans;
}



//Fourth Solution :-
int solve(int n){
    if(n <= 1){
        return n;
    }
    return n + solve(n/5);
}

int findNum(int n){
    int l = 1, r = n;
    while(l < r){
        int mid = (l+r)/2, x = solve(mid);
        if(x >= n){
            r = mid;
        }
        else{
            l = mid+1;
        }
    }
    return 5*l;
}
