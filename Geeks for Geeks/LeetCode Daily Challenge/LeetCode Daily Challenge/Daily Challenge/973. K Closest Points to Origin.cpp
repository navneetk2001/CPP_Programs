// Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).
// The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).
// You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

// Example 1:
// Input: points = [[1,3],[-2,2]], k = 1
// Output: [[-2,2]]
// Explanation:
// The distance between (1, 3) and the origin is sqrt(10).
// The distance between (-2, 2) and the origin is sqrt(8).
// Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
// We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].

// Example 2:
// Input: points = [[3,3],[5,-1],[-2,4]], k = 2
// Output: [[3,3],[-2,4]]
// Explanation: The answer [[-2,4],[3,3]] would also be accepted.



//Solution Approach :-  Sorting 
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), [&](vector<int>& a, vector<int>& b) {
            return squaredDistance(a) < squaredDistance(b);
        });
        
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
    
private:
    int squaredDistance(vector<int>& point) {
        return point[0] * point[0] + point[1] * point[1];
    }
};


//Solution Approach :-  Sorting 
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n=points.size();
	vector<pair<int,pair<int,int>>>v;

	//Find all euclidean distance
	int dist;
	for(auto it:points){
		dist=it[0]*it[0]+it[1]*it[1];
		v.push_back({dist,{it[0],it[1]}});
	}
	sort(v.begin(),v.end());

	vector<vector<int>> ans(k);
	for(int i=0;i<k;i++){
		ans[i].push_back(v[i].second.first);
		ans[i].push_back(v[i].second.second);
	}
	return ans;
    }
}



//Solution Approach :-  Min/Max Priority Queue 
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<vector<int>, vector<vector<int>>, compare> pq;
        for (vector<int>& point : points) {
            pq.push(point);
            if (pq.size() > K) {
                pq.pop();
            }
        }
        vector<vector<int>> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }

private:
    struct compare {
        bool operator()(vector<int>& p, vector<int>& q) {
            return p[0] * p[0] + p[1] * p[1] < q[0] * q[0] + q[1] * q[1];
        }
    };
};


//Solution Approach :-  Multi-Set Approach  
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n=points.size();
	//Multimap is sorted in ASC Order by key
	multimap<int,int>mymap;   //1st val:DISTANCE....//2nd Val:INDEX
	for (int i = 0; i < n; ++i)
	{
		mymap.insert({points[i][0]*points[i][0] + points[i][1]*points[i][1],i});
	}
	vector<vector<int>>ans;
	//Store 1st k from multimap
	int count=0;
	for(auto it=mymap.begin();count<k;++it,++count){
		ans.push_back(points[it->second]);
	}
	return ans;
    }
};



//Solution Approach :-  Multi-Set Approach  
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        multiset<vector<int>, compare> mset;
        for (vector<int>& point : points) {
            mset.insert(point);
            if (mset.size() > K) {
                mset.erase(mset.begin());
            }
        }
        vector<vector<int>> ans;
        copy_n(mset.begin(), K, back_inserter(ans));
        return ans;
    }

private:
    struct compare {
        bool operator()(const vector<int>& p, const vector<int>& q) const {
            return p[0] * p[0] + p[1] * p[1] > q[0] * q[0] + q[1] * q[1];
        }
    };
};

