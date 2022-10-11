// You will be given an array A of N non-negative integers. Your task is to find the rightmost non-zero digit in the product of array elements.

// Example 1:
// Input:
// N = 4, A = {3, 23, 30, 45}
// Output: 5
// Explanation: Product of these numbers are 93150.Rightmost non-zero digit is 5.

// Example 2:
// Input:
// N = 5, A = {1, 2, 3, 4, 5}
// Output: 2
// Explanation: Product of these numbers are 120. Rightmost non-zero digit is 2.



//Solution Approach :-
int rightmostNonZeroDigit(int n, int A[]){
    int x =1;
    int cnt2=0;
    int cnt5=0;

    for(int i=0; i<n; i++){
        if(A[i]==0){
          	return -1;
        }
        while(A[i]%2==0){
            cnt2++;
            A[i]/=2;
        }

        while(A[i]%5==0){
            cnt5++;
            A[i]/=5;
        }
        
        x=(x*A[i])%10;
    }

    int y= min(cnt2, cnt5);
    cnt2-=y;
    cnt5-=y;
    
    for(int i=0; i<cnt2; i++){
        x= (x*2)%10;
    }

    for(int i=0; i<cnt5; i++){
        x = (x*5)%10;
    }
    return x;
}



// Second Solution :-
int rightmostNonZeroDigit(int n, int A[]){
    int cnt5=0;

    for(int i=0; i<n; i++){
        while(A[i] > 0 && A[i]%5==0){
            cnt5++;
            A[i]/=5;
        }
    }

    for(int i=0; i<n; i++){
        while(cnt5 && A[i] > 0 && A[i]%2==0){
            cnt5--;
            A[i]/=2;
        }
    }

    long long ans = 1;
    for(int i=0; i<n; i++){
        ans = (ans * A[i] % 10) % 10;
    }

    if(cnt5){
    	ans = (ans*5)%10;
    }
    if(ans){
    	return ans;
    }
    return -1;
}




//Third Solution :-
int rightmostNonZeroDigit(int n, int A[]){
   	int mul = 1;
    int res = 0;
    for(int i=0; i<n; i++){
       	mul = mul * A[i];
    }
   
    while(!res){
        if(mul%10 == 0){
            mul = mul/10;
        }
        res = mul%10;
    }
   
   return res;
}




