//First Method :- usng vector pair of pairs (Optimize using heap)
vector<vector<int>> Kclosest(vector<vector<int>>& points, int k){
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




//Second Method :- using MultiMap
vector<vector<int>> Kclosest(vector<vector<int>>& points, int k){
	int n=points.size();
	//Multimap is sorted in ASC Order by key
	multimap<int,int>mymap;   //1st val:DISTANCE....//2nd Val:INDEX
	for (int i = 0; i < n; ++i)
	{
		mymap.insert({points[i][0]*points[i][0] + points[i][1]*points[i][1],i});
	}
	vector<vector<int>ans;
	//Store 1st k from multimap
	int count=0;
	for(auto it=mymap.begin();count<k;++it,++count){
		ans.push_back(points[it->second]);
	}
	return ans;
}