class Solution {
public:
    int countElements(vector<int>& arr) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n = arr.size();
        if(n<=1)
            return 0;
        
        sort(arr.begin(),arr.end());
        int left = 0, right = 1;
        int count = 0;
        
        while(right < n)
        {
            if(arr[right] == 1+arr[left])
            {
                count += (right-left);
                left = right;
                right += 1;
            }
            else if(arr[right] == arr[left])
                right += 1;
            else
            {
                left = right;
                right += 1;
            }                
        }
        return count;
    }
};



//HASHMAP APPROACH

class Solution {
public:
    int countElements(vector<int>& arr) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        map<int,int> mymap;
        int i;
        int n = arr.size();
        
        for(i=0;i<n;++i)
        {
            if(mymap.find(arr[i])==mymap.end())
                mymap[arr[i]] = 1;
            else
                mymap[arr[i]] += 1;
        }
        
        int count = 0;
        auto itr = mymap.begin();
        ++itr;
        for(;itr!=mymap.end();++itr)
        {
            auto finder = mymap.find(itr->first-1);
            if(finder!=mymap.end())
                count += finder->second;
        }
        
        return count;
    }
};