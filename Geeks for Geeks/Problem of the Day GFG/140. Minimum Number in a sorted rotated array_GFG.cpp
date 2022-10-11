Given an array of distinct elements which was initially sorted. This array is rotated at some unknown point. The task is to find the minimum element in the given sorted and rotated array. 

Example 1:
Input:
N = 10
arr[] = {2,3,4,5,6,7,8,9,10,1}
Output: 1
Explanation: The array is rotated once anti-clockwise. So minium element is at last index (n-1) which is 1.

Example 2:
Input:
N = 5
arr[] = {3,4,5,1,2}
Output: 1
Explanation: The array is rotated and the minimum element present is at index (n-2) which is 1.


//Solution Approach :-
int minNumber(int arr[], int low, int high){
    int mid;
    while(low<=high){
        mid=low+(high-low)/2;
        
        if(arr[mid]>arr[high]){
            low=mid+1;
        }
        else if(arr[mid]<arr[low]){
            high=mid;
        }
        else{
           return arr[low];
        }
    }
}


//Second Solution :-
int minNumber(int arr[], int low, int high){
    int mini=INT_MAX;
    
    for(int i=low; i<=high; i++){
        mini=min(arr[i],mini);
    }
    return mini;
}


//Third Solution :-
int minNumber(int arr[], int low, int high)
{   
   int minEle=INT_MAX;
   while(low<=high){
       int mid=(low+high)/2;
       
        if(arr[mid]>=arr[low]){      //this half is sorted and its low can be minimum so far
           minEle=min(minEle,arr[low]);
           low=mid+1;
        }
        else if(arr[mid]<=arr[high]){   //right half is sorted
           minEle=min(minEle,arr[mid]);
           high=mid-1;
        }
   }
   return minEle;
}