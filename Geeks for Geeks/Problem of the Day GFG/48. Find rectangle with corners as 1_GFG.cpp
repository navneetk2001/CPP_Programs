// Given a NxM binary matrix consisting of 0s and 1s. Find if there exists a rectangle/ square within the matrix whose all four corners are 1. 

// Example 1:
// Input:
// N = 4, M = 5
// matrix[][] = 
// {
// {1 0 0 1 0},
// {0 0 1 0 1},
// {0 0 0 1 0}, 
// {1 0 1 0 1}
// } 
// Output: Yes
// Explanation:
// Valid corners are at index (1,2), (1,4), (3,2), (3,4) 

// Example 2:
// Input:
// N = 3, M = 3
// matrix[][] = 
// {{0 0 0},
// {0 0 0},
// {0 0 0}}
// Output: No


//BruteForce Approach :-
//Solution Approach :-  T.C :- O(N^2 * M^2)
class Solution{
    public:
    bool ValidCorner(const vector<vector<int> >& matrix)
    {
        int r=matrix.size();
        int c= matrix[0].size();
        for(int i=0;i<r;i++){
        	for(int j=0;j<c;j++){
        		if(matrix[i][j]==1){
	        		int right,down;
	        		for(right=j+1;right<c;right++){
	        			if(matrix[i][right]==1){
	        				for(down=i+1;down<r;down++){
	        					if(matrix[down][right]==1){
	        						if(matrix[down][j]==1){
	        							return true;
	        						}
	        					}
	        				}
	        			}
	        		}
	        	}
        	}
        }
        return false;
    }
};


//Another Solution :- 
bool ValidCorner(const vector<vector<int> >& matrix){
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    for(int i = 0; i < rows; i++){
        for(int j = i + 1; j < rows; j++){
            int cnt = 0;
            for(int k = 0; k < cols; k++){
                if(matrix[i][k] == 1 && matrix[j][k] == 1)
                	cnt++;

                if(cnt == 2)
                	return true;
            }
        }
    }
    return false;
}


//Another Solution :- Using set
bool ValidCorner(const vector<vector<int> >& matrix){
    int n=matrix.size(),m=matrix[0].size();
    set<pair<int,int>> st;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m-1;j++)
        {
            if(matrix[i][j]==0) continue;
            for(int k=j+1;k<m;k++)
            {
                if(matrix[i][k]==0) continue;
                if(st.count({j,k})) return true;
                st.insert({j,k});
            }
        }
    }
    return false;
}


//Another Solution :- Bitset Solution
bool ValidCorner(const vector<vector<int> >& matrix)
{
    int n=matrix.size(),m=matrix[0].size();
    vector<bitset<200>> arr(n);
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        arr[i][j]=matrix[i][j];
    }

    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if((arr[i]&arr[j]).count()>=2)
            return true;
        }
    }
    return false;
}


//Another Solution :- Unordered map Solution :- T.C :- O(N^2 * M)
bool ValidCorner(const vector<vector<int> >& matrix)
{
   int r = matrix.size();
   int c = matrix[0].size();
   unordered_map<int,unordered_set<int>> map;

   for(int i=0;i<r;i++){
       for(int j=0;j<c;j++){
           for(int z = j+1;z<c;z++){
               if(matrix[i][j]==1 && matrix[i][z]==1){
                   if(map.find(j)!=map.end() && map[j].find(z)!=map[j].end()){
                       return true;
                   }
                   map[j].insert(z);
               }
           }
       }
   }
   return false;
}