Given an array of size n, find the majority element. The majority element is the element that appears more than floor(n/2) times.
You may assume that the array is non-empty and the majority element always exist in the array.

Example :
Input : [2, 1, 2]
Return  : 2 which occurs 2 times which is greater than 3/2.


//Hint :-
Lets say you find 2 elements x and y which are different in the array. If you removed those 2 elements, would the majority element change ?

//Solution Approach :- 
If we cancel out each occurrence of an element e with all the other elements that are different from e then e will exist till end if it is a majority element. Loop through each element and maintains a count of the element that has the potential of being the majority element. If next element is same then increments the count, otherwise decrements the count. If the count reaches 0 then update the potential index to the current element and reset count to 1.


//First Solution :-
int Solution::majorityElement(const vector<int> &A) {
    int n = A.size();
    int candidate = 0;
    int count = 0;

    for(int i=0;i<n;i++){
        if(count == 0){
            candidate = A[i];
        }
        if(A[i] == candidate){
            count++;
        }
        else{
            count--;
        }
    }

    return candidate;
}


//Second Solution :-  
int Solution::majorityElement(const vector<int> &A){
	int i=1;
	int v1 = A[0];

	stack<int>s;
	s.push(A[0]);
	for(i=1;i<A.size();i++)
	{
		if(!s.empty() && s.top()!=A[i])
			s.pop();
		else
			s.push(A[i]);
	}
	return s.top();
}

//Third Solution :- 
int Solution::majorityElement(const vector<int>&A) {
	map<int,int>m;
	int n=A.size();
	
	for(int i=0;i<n;i++){
		m[A[i]]++;
		int num=n/2;
		int no;

		for(auto it:m){
			if(it.second>num){
				no=it.first;
				break;
			}
		}
	}
	return no;
}


//Solution :-
class Solution {
    public:
        int majorityElement(vector&lt;int&gt; &amp;num) {
            int majorityIndex = 0;
            for (int count = 1, i = 1; i &lt; num.size(); i++) {
                num[majorityIndex] == num[i] ? count++ : count--;
                if (count == 0) {
                    majorityIndex = i;
                    count = 1;
                }
            }

            return num[majorityIndex];
        }
};



