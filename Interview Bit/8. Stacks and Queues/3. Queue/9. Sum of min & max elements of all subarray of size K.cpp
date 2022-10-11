https://www.geeksforgeeks.org/sum-minimum-maximum-elements-subarrays-size-k/





//Solution APproach :-
// The idea behind this approach is to maintain two separate Dequeues(say, minDequeue and maxDequeue) which store the indices of the elements. In maxDequeue, we will maintain decreasing order of elements while in minDequeue we will maintain increasing order of elements. The idea for this approach is that we will keep only those elements that are candidates for our answer.
// We keep at max K element (i.e. the size of our window) in both the Dequeues and the current index is placed at its respective sorted place in both the Dequeues.
// To find maximum and minimum elements in the first window of size K, we run a loop through the first K elements of the array.
// While the minDequeue is not empty and the current element is smaller than or equal to the element at the rear end index of minDequeue, pop the rear element of minDequeue. This makes sure that we are getting rid of all those elements which can never be the minimum element in any subarray of size K and the minimum element for this subarray will be at the front end index.
// While the maxDequeue is not empty and the current element is greater than or equal to the element at the rear end index of maxDequeue, pop the rear element of maxDequeue. This makes sure that we are getting rid of all those elements which can never be the maximum element in any subarray of size K and the maximum element for this subarray will be at the front end index.
// Add the current index to the rear of both the Dequeues.
// Now, the front end index of minDequeue corresponds to the minimum element of this window of size K while the front end element of maxDequeue corresponds to the maximum element and we can add the elements at these two positions to our final sum.
// We have to repeat this process for the rest of the windows as well.
// But before inserting the current index we have to remove all indices in both the Dequeues which are not in the current window of size K.
// Since our current window ends at (say, index i), we have to remove all indices from both the Dequeues which are less than the starting index of this window (in this case, it would be i - K).
// While the index at the front end of minDequeue is less than or equal to the starting index of this window, remove the front end index of minDequeue.
// While the index at the front end of maxDequeue is less than or equal to the starting index of this window, remove the front end index of maxDequeue.
// Now, we can follow the above process to insert the current element into both the Dequeues.
// For, every iteration, the front end index of minDequeue will correspond to the minimum element of that window while the front end index of maxDequeue will correspond to the maximum element of that window and we can add both these elements to our final answer.

#include <iostream>
#include <queue>
using namespace std;

long long sumOfMaxAndMin(vector<int> &arr, int n, int k) {
	deque<long long> maxi(k);
    deque<long long> mini(k);

    //Addition of first k size window
    for(int i=0; i<k; i++) {
        while(!maxi.empty() && arr[maxi.back()] <= arr[i]){
            maxi.pop_back();
        }

        while(!mini.empty() && arr[mini.back()] >= arr[i]){
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);
    }

    long long ans = 0;
    ans += arr[maxi.front()] + arr[mini.front()];

    //remaining windows ko process karlo
    for(int i=k; i<n; i++) {        //next window
        //removal
        while(!maxi.empty() && i - maxi.front() >=k) {
            maxi.pop_front();
        }
        while(!mini.empty() && i - mini.front() >=k) {
            mini.pop_front();
        }

        //addition
        while(!maxi.empty() && arr[maxi.back()] <= arr[i]){
            maxi.pop_back();
        }
        while(!mini.empty() && arr[mini.back()] >= arr[i]){
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);    

        ans += arr[maxi.front()] + arr[mini.front()];
    }
    return ans;
}


int main() {
    int arr[7] = {2, 5, -1, 7, -3, -1, -2};
    int k = 4;
    cout << solve(arr, 7, k) << endl;
    return 0;
}



//Second Approach :-
