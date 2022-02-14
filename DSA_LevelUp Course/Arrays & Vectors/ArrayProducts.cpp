#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Expected Complexity O(N)
vector<int> productArray(vector<int> arr){
   
    int n = arr.size();
    vector<int> output(n,1);
    
    // Base case
    if (n == 1) {
    	output.push_back(0);
        return output;
    }
    
    vector<int> left(n,1);
    vector<int> right(n,1);
  
    left[0] = 1;        // left-most element
    right[n - 1] = 1;   // right-most element
  
    // Construct the left array 
    for (int i = 1; i < n; i++){
        left[i] = arr[i - 1] * left[i - 1];
    }
  
    // Construct the right array 
    for (int j = n - 2; j >= 0; j--){
        right[j] = arr[j + 1] * right[j + 1];
    }
  
    // Construct the product array using left[] and right[] array
    for (int i = 0; i < n; i++){
    	output[i] = left[i] * right[i];
    }
 
    return output;
}

int main()
{
	vector<int> arr{1,2,3,4,5};
	auto p=productArray(arr);

	for(auto x : p){
		cout<<x<<" ";
	}
	return 0;
}


/*

long* productExceptSelf(int a[], int n)
{
    long prod = 1;
    long flag = 0;
  
    // product of all elements
    for (int i = 0; i < n; i++) {
  
        // counting number of elements which have value 0.
        if (a[i] == 0)
            flag++;
        else
            prod *= a[i];
    }
  
    // creating a new array of size n
    long* arr = new long[n];
  
    for (int i = 0; i < n; i++) {
  
        // if number of elements in array with value 0 is more than 1 than each value in new array will be equal to 0
        if (flag > 1) {
            arr[i] = 0;
        }
  
        // if no element having value 0 than we will insert product/a[i] in new array
        else if (flag == 0)
            arr[i] = (prod / a[i]);
  
        // if 1 element of array having value 0 than all the elements except that index value , will be equal to 0
        else if (flag == 1 && a[i] != 0) {
            arr[i] = 0;
        }
  
        // if(flag == 1 && a[i] == 0)
        else
            arr[i] = prod;
    }
    return arr;
}

*/