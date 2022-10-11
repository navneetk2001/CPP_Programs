https://practice.geeksforgeeks.org/problems/box-stacking/1



//Solution Approach :- 
/*The function takes an array of heights, width and length as its 3 arguments where each index i value determines the height, width, length of the ith box. Here n is the total no of boxes.*/

struct box {
    int h,w,l;
};

bool compare(struct box a,struct box b){          //arrange in decreasing order of area
    return (a.w * a.l > b.w * b.l)?true:false;
}

int maxHeight(int height[],int width[],int length[],int n)
{
    //STEP-1:Make an array of box (to store-> h,w,l)
    int len = 3*n;
    box arr[len];   //store  all 3 orientations
    int index = 0;
    for(int i=0;i<n;++i)
    {
        arr[index].h = height[i];
        arr[index].w = max(width[i],length[i]);
        arr[index].l = min(width[i],length[i]);
        index+=1;
       
        arr[index].h = width[i];
        arr[index].w = max(length[i],height[i]);
        arr[index].l = min(length[i],height[i]);
        index+=1;
       
        arr[index].h = length[i];
        arr[index].w = max(height[i],width[i]);
        arr[index].l = min(height[i],width[i]);
        index+=1;
    }
   
    //STEP-2: Sort in DSC order of height
    sort(arr,arr+len,compare);
   
    //STEP-3: Find LIS
    int lis[len];
    for(int i=0;i<len;++i){
        lis[i] = arr[i].h;
    }
   
    for(int i=1;i<len;++i){
        for(int j=0;j<i;++j){
            if((arr[i].w < arr[j].w) and (arr[i].l < arr[j].l) and (lis[i] < lis[j]+arr[i].h)){
                lis[i] = lis[j] + arr[i].h;
            }
        }
    }
    int mx = 0;
    for(int i=0;i<len;++i){
        mx = max(mx,lis[i]);
    }
    return mx;
}




//Second Solution :- 
int dp[101][101];
int solve(int height[],int width[],int length[],int y,int z,int n){
    int ht=0;
   	
   	for(int ind=0;ind<n;++ind){
      	int a1=max(width[ind],length[ind]);
	    int b1=min(width[ind],length[ind]);
	    int a2=max(width[ind],height[ind]);
	    int b2=min(width[ind],height[ind]);
	    int a3=max(height[ind],length[ind]);
	    int b3=min(height[ind],length[ind]);

	   	if(y>a1 && z>b1){
	      	if(dp[a1][b1]!=-1){
	      		ht=max(ht,height[ind]+dp[a1][b1]);
	      	}
	    	else{
	    		ht=max(ht,height[ind]+solve(height,width,length,a1,b1,n));  
	    	}
	   	}

	    if(y>a2 && z>b2){
	    	if(dp[a2][b2]!=-1){
	    		ht=max(ht,length[ind]+dp[a2][b2]);
	    	}
	   		else{
	   			ht=max(ht,length[ind]+solve(height,width,length,a2,b2,n));  
	   		}
	   	}

	    if(y>a3 && z>b3){
	    	if(dp[a3][b3]!=-1){
	    		ht=max(ht,width[ind]+dp[a3][b3]);
	    	}
	    	else{
	    		ht=max(ht,width[ind]+solve(height,width,length,a3,b3,n));   
	    	}
	   	}
   	}
    return dp[y][z]=ht;
}

int maxHeight(int height[],int width[],int length[],int n){    
	memset(dp,-1,sizeof(dp));
  	int alp= solve(height,width,length,101,101,n);
 
  	return alp;
}



//Third Solution :- 
int dp[702];
int solve(vector<vector<int>>& v,int n,int idx){
   	int ans=0;
   	if(dp[idx]!=-1) return dp[idx];
   
   	for(int i=0;i<n;i++){
       	if(v[idx][0] > v[i][0] and v[idx][1] > v[i][1]){
           ans = max(ans,solve(v,n,i)+v[i][2]);
       	}
   	}
   	return dp[idx]= ans;
}

int maxHeight(int height[],int width[],int length[],int n)
{
   	memset(dp,-1,sizeof(dp));
   	vector<vector<int>> box;
   	for(int i=0;i<n;i++){
       	box.push_back({height[i],width[i],length[i]});
       	box.push_back({width[i],height[i],length[i]});
       	box.push_back({length[i],width[i],height[i]});
        box.push_back({width[i],length[i],height[i]});
        box.push_back({length[i],height[i],width[i]});
        box.push_back({height[i],length[i],width[i]});
   	}
   
   	int ans=0;
   	for(int i=0;i<6*n;i++){
       	ans=max(ans,solve(box,6*n,i)+box[i][2]);
   	}
   	return ans;
}



//Fourth Solution :-
int maxHeight(int height[],int width[],int length[],int n)
{
	vector<array<int,3>> box(3*n);
	int k=0;

	for(int i=0;i<n;i++){
		int arr[3] = {length[i],width[i],height[i]};
		sort(arr,arr+3);
		box[k++]={arr[0],arr[1],arr[2]};
		box[k++]={arr[1],arr[2],arr[0]};
		box[k++]={arr[0],arr[2],arr[1]};
	}

	sort(box.begin(),box.end(),[&](const array<int,3>&a,const array<int,3>&b){
	 	return a[0]*a[1]<b[0]*b[1];
	}); 

	vector<int> dp(3*n);
	int maxi=INT_MIN;

	for(int i=0;i<3*n;i++){
	 	dp[i] = box[i][2];
	 	for(int j=i-1;j>=0;j--){
	  		if(box[j][0]<box[i][0]&&box[j][1]<box[i][1]){
	   			dp[i]=max(dp[i],dp[j]+box[i][2]);
	  		}
	 	}
	 	maxi=max(maxi,dp[i]);
	}
	return maxi;
}