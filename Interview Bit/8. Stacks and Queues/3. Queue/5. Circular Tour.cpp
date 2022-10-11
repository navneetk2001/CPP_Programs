https://practice.geeksforgeeks.org/problems/circular-tour-1587115620/1



//Approach :-
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[], int n){
        vector<int> v;
        int sum = 0;
       
        for(int i=0; i<n; i++){
            v.push_back(p[i].petrol - p[i].distance);
            sum += v.back();
        }
       
        if(sum < 0){
            return -1;
        }
       
        sum = 0;
        int l = 0;
       
        for(int i=0; i<n; i++){
            sum += v[i];
           
            if(sum<0){
                l = i + 1;
                sum = 0;
            }
        }
       
        return l;
    }
};



//Second Solution :-
int tour(petrolPump p[],int n){
	int start = 0, prevpet = 0, curpet = 0;

	for(int i=0; i<n; i++){
	    curpet += p[i].petrol - p[i].distance;
	  	if(curpet < 0){
	      	start = i+1;
	      	prevpet += curpet;
	      	curpet = 0;
	  	}
	}
	return prevpet + curpet>=0 ? start : -1;
}



//Third Solution :-
class Solution{
public:
    //Function to find starting point where the truck can start to get through the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       	int presum = 0, curr = 0, index = -1;
        
        for(int i=0;i<n;i++){
           	presum += (p[i].petrol - p[i].distance);
           	curr += (p[i].petrol - p[i].distance);
           	
           	if(curr>=0 && index==-1){
                index = i;
           	}
           	
           	if(curr<0){
               	curr = 0;
               	index = -1;
           	}
       	}
       	if(presum < 0){
        	return -1;
       	}
    	return index;
    }
};




//Fourth Solution :-
class petrolPump 
{ 
	public: 
	int petrol; 
	int distance; 
}; 

// The function returns starting point if there is a possible solution, 
// otherwise returns -1 
int printTour(petrolPump arr[], int n) 
{ 
	// Consider first petrol pump as a starting point 
	int start = 0; 
	int end = 1; 

	int curr_petrol = arr[start].petrol - arr[start].distance; 

	/* Run a loop while all petrol pumps are not visited. 
	And we have reached first petrol pump again with 0 or more petrol */
	while (end != start || curr_petrol < 0) 
	{ 
		// If curremt amount of petrol in truck becomes less than 0, then 
		// remove the starting petrol pump from tour 
		while (curr_petrol < 0 && start != end) 
		{ 
			// Remove starting petrol pump. Change start 
			curr_petrol -= arr[start].petrol - arr[start].distance; 
			start = (start + 1) % n; 

			// If 0 is being considered as start again, then there is no 
			// possible solution 
			if (start == 0) 
			return -1; 
		} 

		// Add a petrol pump to current tour 
		curr_petrol += arr[end].petrol - arr[end].distance; 

		end = (end + 1) % n; 
	} 

	// Return starting point 
	return start; 
} 