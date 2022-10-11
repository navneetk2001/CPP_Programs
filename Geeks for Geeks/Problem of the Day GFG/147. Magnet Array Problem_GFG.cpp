// Given N Magnets which are placed linearly, with each magnet to be considered as of point object. Each magnet suffers force from its left sided magnets such that they repel it to the right and vice versa. All forces are repulsive. The force being equal to the distance (1/d , d being the distance). Now given the positions of the magnets, the task to find all the points along the linear line where net force is ZERO. 
// More Formally, Magnets are placed on X axis, the coordinates of which are given, you are asked to find out the X-co-ordinates of all the equilibrium points (i.e. the point where net force is zero). You notice the point each magnet repels each other, it means the polarity of the magnet is such that exerts +ve force in its right side and -ve force in left side, (here +ve is considered in +ve direction of x-axis). And that forces are inversely proportional to the distance, thus there lies an equilibrium point between every two magnetic points. Thus there will be total of N-1 equllibrium points. You have to find those N-1 points.
// Note: Array M[] is sorted and distance have to be calculated with precision of 2 decimal places.

// Example 1:
// Input:
// N = 2
// M[] = {1, 2}
// Output: 1.50
// Explanation: The mid point of two points will have net force zero, thus answer = 1.50
 

// Example 2:
// Input:
// N = 4
// M[] = {0, 10, 20, 30}
// Output: 3.82, 15.00, 26.18




//Problem Explained in Detail :-
// So I will explain the equilibrium concept for the second example:
// [0, 10, 20, 30]
//     ^
// We will find the equilibrium for 1st place i. e. between 0 and 10:->  low = 0, high = 10, Mid = 5;

// So calculate the left forces and right forces at point 5.
// left forces = 1/(5 - 0) => (0.25)
// Right forces = 1/(10-5) + 1/(20 - 5) + 1/(20-5) => (0.306)
// Clearly, left forces < right forces:
// 	So, we move left

// Now, low = 0, high = 5, Mid = 2.5;
// So calculate the left forces and right forces at point 2.5.
// left forces = 1/(2.5 - 0) => (0.4)
// Right forces = 1/(10-2.5) + 1/(20 - 2.5) + 1/(20-2.5) => (0.22)
// Clearly, left forces > right forces:
// 	So, we Move Right

// Now, low = 2.5, high = 5, Mid = 3.75;
// So calculate the left forces and right forces at point 3.75.
// left forces = 1/(3.75 - 0) => (0.26)
// Right forces = 1/(10-3.75) + 1/(20 - 3.75) + 1/(20-3.75) => (0.25)
// Clearly, left forces > right forces:
// 	So, we Move Right

// Follow this till we get 
// Right forces == Left forces.
// and calculate the same for all the equilibrium points.




//Solution Approach :-
void nullPoints(int n, double magnets[], double getAnswer[])
{
   for(int i=0;i<n-1;i++){                                   
       getAnswer[i] = neutral_point(magnets[i],magnets[i+1],magnets,n);
   }
}

double neutral_point(double low, double high,double magnets[],int n){
    while(low<high){  
    	double mid = (low+high)/2;
       
        double totalforce = 0;
        for(int i=0;i<n;i++){
            totalforce+= 1/(mid-magnets[i]);  
        }

        if(abs(totalforce)<0.000001){
        	return mid;
        }
        else if(totalforce<0){   //left is too much, right is too less, right increases
            high = mid;          //move closer to the first magnet and away from other magnets
        }
        else{                    //left is very less, right is too much, right decrease
            low = mid;           //move away from first magnet and close to other magnets
        }
    }
    return low;
}



//Second Solution :-
void nullPoints(int n, double magnets[], double getAnswer[])
{
    for(int i=0;i<n-1;i++){
        double low = magnets[i];
        double high = magnets[i+1];
	    
	    while(low<=high)
	    {
	        double mid = low +(high-low)/2;
	        double left = 0.00,right = 0.00;
	        for(int j=i+1;j<n;j++) {
	        	left += (1/(magnets[j]-mid));
	        }
	            
	        for(int j=i;j>=0;j--){
	        	right += (1/(mid-magnets[j]));
	        }
	            
	        if((abs(right-left)<0.000001)){
	         	getAnswer[i] = mid;
	        	break;
	        }
	        else if(left<right){
	        	low = mid;
	        }
	        else{
	        	high = mid; 
	        }
	    }
    }
}


