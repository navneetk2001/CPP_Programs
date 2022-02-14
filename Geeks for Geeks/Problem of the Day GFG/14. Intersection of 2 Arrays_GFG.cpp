Given two arrays a[] and b[] respectively of size n and m, the task is to print the count of elements in the intersection (or common elements) of the two arrays.
For this question, the intersection of two arrays can be defined as the set containing distinct common elements between the two arrays. 

Example 1:

Input:
n = 5, m = 3
a[] = {89, 24, 75, 11, 23}
b[] = {89, 2, 4}

Output: 1

Explanation: 
89 is the only element 
in the intersection of two arrays.
Example 2:

Input:
n = 6, m = 5
a[] = {1, 2, 3, 4, 5, 6}
b[] = {3, 4, 5, 6, 7} 

Output: 4

Explanation: 
3 4 5 and 6 are the elements 
in the intersection of two arrays.

//Brute Force Approach :- T.C :- O(n*mlogn)
//1. Search for each element of first array in second array and maintain a visited array for array2


//Optimized Approach :- Using Set (T.C :- (O(n*logm)) n for traversing s1 and log m for binary search

int NumberofElementsinIntersection (int a[], int b[], int n, int m){
	set<int>s1,s2;
	for(int i=0;i<n;i++){   //Inserting elements in s1
		s1.insert(a[i]);
	}
	for(int i=0;i<m;i++){   //Inserting elements in s2
		s2.insert(b[i]);
	}
	int cnt=0;
	for(auto &x:s1){   //for each elements in s1
		if(s2.find(x)!=s2.end()){  //Binary Search to find x in s2
			cnt++;
		}
	}
    return cnt;
}


//Second answer
int NumberofElementsinIntersection(int a[], int b[], int n, int m){
	unordered_map<int,int>mp;
	for(int i=0;i<n;i++){   //Inserting elements in map
		mp[a[i]]=1;
	}
	
	int cnt=0;
	for(int i=0;i<m;i++){ //Traversing b  
		if(mp[b[i]]==1){  //if number existed in A
			cnt++;
			mp[b[i]]=0;  //dupicate should not be counted
		}
	}
    return cnt;
}
