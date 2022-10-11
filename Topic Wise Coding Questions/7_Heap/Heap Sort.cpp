https://practice.geeksforgeeks.org/problems/heap-sort/1



//Solution Approach :- 
#include <iostream>
using namespace std;

// To heapify a subtree rooted with node i which is an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i)
{
	int largest = i;             // Initialize largest as root
	int l = 2 * i + 1;           // left = 2*i + 1
	int r = 2 * i + 2;           // right = 2*i + 2

	if (l < n && arr[l] > arr[largest]){    	// If left child is larger than root
		largest = l;
	}
	if (r < n && arr[r] > arr[largest]){     	// If right child is larger than largest so far
		largest = r;
	}

	if (largest != i) {                      	// If largest is not root
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);        		// Recursively heapify the affected sub-tree
	}
}

// main function to do heap sort
void heapSort(int arr[], int n){
	for (int i = n / 2 - 1; i >= 0; i--){          	// Build heap (rearrange array)
		heapify(arr, n, i);
	}

	// One by one extract an element from heap
	for (int i = n - 1; i > 0; i--) {
		swap(arr[0], arr[i]);           	// Move current root to end
		heapify(arr, i, 0);         		// call max heapify on the reduced heap
	}
}

void printArray(int arr[], int n){
	for (int i = 0; i < n; ++i){
		cout << arr[i] << " ";
	}
	cout << "\n";
}

int main(){
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int n = sizeof(arr) / sizeof(arr[0]);

	heapSort(arr, n);

	cout << "Sorted array is \n";
	printArray(arr, n);
}




//Second Solution :- 
class Solution{
public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i){
		int l = 2 * i + 1;
		int r = 2 * i + 2;
		int largest = i;
		if(l<n && arr[largest]<arr[l]){
		  	largest=l;
		}
		if(r<n && arr[largest]<arr[r]){
		    largest=r;
		}

		//if we found child greater than the parent make child parent
		if(largest!=i){
			swap(arr[largest],arr[i]);
			heapify(arr,n,largest);    			//there is chance ith value go further down in heap so heapifiy it
		}
      
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
        //(n/2-1)th node is first non-leaf node i.e. all node greater than (n/2-1) are leaf node, so there is no need to heapified leaf node it get there desire position by parents lower nodes get heapified first
        for(int i=n/2-1;i>=0;i--){
            heapify(arr,n,i);
        }
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n){
        //first we have to build max heap so we got max elm on top swap it to last and iterate for length-1 array
        buildHeap(arr,n);

        //here we got max elm on idx 0 to swap it to last elm and we can clearly see after swapping the 0th elm is only which is un heapified so heapify it i.e. take that elm to its pos.
        for(int i=n-1;i>=0;i--){
            swap(arr[0],arr[i]);                 //reduce array size by one in each iteration
            heapify(arr,i,0);                    //since 0th elm is not heapified
        }
        
    }
};