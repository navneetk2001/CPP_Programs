// Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2, …N} is missing and one number 'B' occurs twice in array. Find these two numbers.

// Example 1:
// Input:
// N = 2
// Arr[] = {2, 2}
// Output: 2 1
// Explanation: Repeating number is 2 and smallest positive missing number is 1.

// Example 2:
// Input:
// N = 3
// Arr[] = {1, 3, 3}
// Output: 3 2
// Explanation: Repeating number is 3 and smallest positive missing number is 2.


//Solution Approach :-
// First Approach will be sorting and check for each index element 

//Second Approach :- we can use concept of hashmap and mark the frequency of each element and find required
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        int *res=new int[2];
        int repeatingValue;
        int missingValue;
        unordered_map<int,int> mpp;

        for(int i=1;i<=n;i++){
        	mpp[i]++;
        }

        for(int i=0;i<n;i++){
        	mpp[arr[i]]++;
        }

        for(auto it:mp){
        	if(it.second < 2){
        		missingValue=it.first;
        	}
        	if(it.second > 2){
        		repeatingValue=it.first;
        	}
        }

        res[0]=repeatingValue;
        res[1]=missingValue;
        
        return res;
    }
};


//Third Approach :- use XOR Approach :- if an element occurs twice it's xor will be 0
class Solve {
    int[] findTwoElement(int arr[], int n) {
        int[] res = new int[2];
        int xy = 0;
        for(int a : arr){
            xy ^=a;
        }
        
        for(int a = 1; a <= n ; a++){
            xy ^=a;
        }
        
        int rmsb = xy & (~xy+1);
        int x = 0, y = 0;
        
        for(int a : arr){
            if((a & rmsb) == 0)
                x ^=a;
            else
                y ^=a;
        }
        
        for(int a = 1; a <=n; a++){
            if((a & rmsb) == 0)
                x ^=a;
            else
                y ^=a;
        }
        
        for(int a : arr){
            if(a == x){
                res[0] = x;
                res[1] = y;
            }
            if(a == y){
                 res[1] = x;
                res[0] = y;
            }
        }
        return res;
    }
}


//Fourth Approach :- 
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        int *res;

        for(int i=0;i<n;i++){
        	int curr = abs(arr[i])-1;
        	if(arr[curr]<0){
        		res[0]=curr+1;
        	}
        	else{
        		arr[curr]*=-1;
        	}
        }

        for(int i=0;i<n;i++){
        	if(arr[i]>0){
        		res[1]=i+1;
        		break;
        	}
        }
        return res;
    }
};



//Fourth Approach :- Using swap sort in O(n)
int *findTwoElement(int *arr, int n) {
		
        int *arr1 = new int[2];
        
        //unsorted arr 2 3 1 1 5
        int i=0;
        while(i<n){
            if(arr[i] != arr[arr[i]-1])
            swap(arr[i], arr[arr[i]-1]);
            else
            i++;
        }
        
        //sorted array 1 2 3 1 5
        int a=0,b=0;
        for(int i=0;i<n;i++){
            if(arr[i]!=i+1){
                a=i+1;
                b=arr[i];
                break;
            }
        }
        arr1[0]=b;
        arr1[1]=a;
        return arr1;
    }