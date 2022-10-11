https://www.codingninjas.com/codestudio/problems/aggressive-cows_1082559?leftPanelTab=3



//Solution :-
bool isPossible(vector<int> &stalls, int k, int mid){
    int cowCount = 1;   //start with first cow
    int lastPosition = stalls[0];   //last position is the position where we kept first cow and from where we are measuring safe distance
    //arr[i] will denote the dynamic place where i am wanting to place my 2nd cow such that their min distance is met and maximised
    
    for(int i =0; i<stalls.size();i++){
        if(stalls[i] - lastPosition >= mid){        //distance between the placing position and placed position should be greater than equal to the mid value which is required
            cowCount++;                           //place cow=> how to place -> increement cow value count
            if(cowCount == k){                    //if we got the cows as needed
                return true;   
            }
            lastPosition = stalls[i];            //update lastPosition of cow & keep checking on right side for further max value
        }
    }
    return false;   //if not found till here -> no solution exists with this value of mid, so return false
}

int aggressiveCows(vector<int> &stalls, int k){
    sort(stalls.begin(), stalls.end());        //sort stall array 

    int maxi = -1;

    for(int i =0; i<stalls.size(); i++){
        maxi = max(maxi, stalls[i]);
    }

    int start = 0;
    int end = maxi;
    int ans = -1;

    
    while(start <= end){
        int mid  = start+(end-start)/2;
        if(isPossible(stalls,k,mid)){               //possible solution -> save in ans and move right coz we need to find largest max distance, right side move
            ans = mid;
            start = mid+1;
        }
        else{            //solution not possible, move left
            end = mid-1;
        }
    }
    return ans;
}




//Second Solution :- 
#include <bits/stdc++.h>
using namespace std;

const int me = 100025;
const int mod = 0x3b9aca07;


int t, n, c;
int a[me];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    while(t --){
        cin >> n >> c;
        for(int i = 0; i < n; i ++)
            cin >> a[i];
        
        sort(a, a + n);
        int low = 0, high = a[n-1], mid, best = 0;
        while(low <= high){
            mid = (low + high + 1) / 2;
            int cnt = 1, left = 0;
            for(int i = 1; i < n && cnt < c; i ++){
                if(a[i] - a[left] >= mid)
                    left = i, cnt ++;
            }
            if(cnt >= c){
                best = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        cout << best << endl;
    }
    
    return 0;
}




//Second Solution :- 
#include <bits/stdc++.h>
using namespace std;

bool isCompatible(vector < int > inp, int dist, int cows) {
    int n = inp.size();
    int k = inp[0];
    cows--;
    for (int i = 1; i < n; i++) {
        if (inp[i] - k >= dist) {
            cows--;
            if (!cows) {
                return true;
            }
            k = inp[i];
        }
    }
    return false;
}

int main() {
    int n = 5, m = 3;
    vector<int> inp {1,2,8,4,9};
    sort(inp.begin(), inp.end());

    int maxD = inp[n - 1] - inp[0];
    int ans = INT_MIN;

    for (int d = 1; d <= maxD; d++) {
        bool possible = isCompatible(inp, d, m);
        if (possible) {
            ans = max(ans, d);
        }
    }
    cout << "The largest minimum distance is " << ans << '\n';
}
