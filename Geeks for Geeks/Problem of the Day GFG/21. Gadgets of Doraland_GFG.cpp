In Doraland, people have unique Identity Numbers called D-id. Doraemon owns the most popular gadget shop in Doraland. Since his gadgets are in high demand and he has only K gadgets left he has decided to sell his gadgets to his most frequent customers only. N customers visit his shop and D-id of each customer is given in an array array[ ]. In case two or more people have visited his shop the same number of time he gives priority to the customer with higher D-id. Find the D-ids of people he sells his K gadgets to.

Example 1:
Input:
N = 6
array[] = {1, 1, 1, 2, 2, 3}
K = 2
Output: 
1 2
Explanation: 
Customers with D-id 1 and 2 are most 
frequent.

Example 2:
Input:
N = 8
array[] = {1, 1, 2, 2, 3, 3, 3, 4}
K = 2
Output: 
3 2
Explanation: People with D-id 1 and 2 have 
visited shop 2 times Therefore, in this 
case, the answer includes the D-id 2 as 2 > 1.


//Solution :-
class Solution{
    public:
    static bool cmp(pair<int,int>a, pair<int,int>b){  //Comparator function
    	if(a.second>b.second) return 1;
    	else if(a.second<b.second) return 0;
    	else if(a.second==b.second){
    		return (a.first>b.first);
    	}
    }
    
    vector<int> TopK(vector<int>& a, int k)
    {
        vector<int>ans;
    	vector<int>f(10001);  //frequency store for each id number
    	for(auto e:a){
    		f[e]++;
    	}
    	vector<pair<int,int>>v;   //store id number and its frequency together
    	for(int i=0;i<10001;i++){
    		if(f[i]){
    			v.push_back({i,f[i]});
    		}
    	}
    	sort(v.begin(),v.end(),cmp);  //sort in non increasing order
    	int i=0;
    	while(k && i<v.size()){
    		ans.push_back(v[i].first);
    		i++;
    		k--;
    	}
    	return ans;
    }
};