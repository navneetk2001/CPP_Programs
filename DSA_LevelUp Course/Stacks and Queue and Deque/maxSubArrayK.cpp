#include<iostream>
#include<vector>
#include<deque>
using namespace std;

void maxSubArrayK(vector<int>a, int k){
	//Algorithm
	deque<int> Q(k);
	int i;
	int n=a.size();
    // 1. Process only the first k elements
    for(i=0;i<k;i++){
    	if(!Q.empty() && a[i] > a[Q.back()]){
    		Q.pop_back();
    	}
    	Q.push_back(i);
    }

    //2. Remaining elements of the array
    for( ;i<n;i++){
    	cout<<a[Q.front()]<<" ";
    	//Remove elements from the left(contraction when index lies outside current window)
    	while(!Q.empty() and Q.front()<=i-k){
    		Q.pop_front();
    	}

    	while(!Q.empty() and a[i] >= a[Q.back()]){
    		Q.pop_back();
    	}
    }
}

int main(){
	vector<int> arr{1,2,3,1,4,5,2,3,5};
	int k=3;

	maxSubArrayK(arr,k);

	return 0;
}