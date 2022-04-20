// Geek has a ticket to the Geek Summer Carnival. The ticket has a positive integer B written on it. B denotes the base of a right-angled isosceles triangle. 
// Geek can avail discounts on X courses in the carnival.
// X is the maximum number of squares of size 2x2 units that can fit in the given right-angled isosceles triangle. 
// Find X. 

// Example 1:
// Input: B = 8
// Output: 6 

// Example 2:
// Input: B = 2
// Output: 0



//Approach :-
Just imagine a mirror isosceles triangle and make this a whole square now you can check this by making B = 2 , 4, 6, 8 and you can see that the squares which are getting sliced at the diagonal are equal to B/2 . Which Mean we have to remove this sliced squares but still we will be remaining with the upper half and lower half so we will divide the total by 2 to get only the lower half.


//Solution Approach :-
class Solution{
    public:
    int countSquare(int b)
    {
	    int ans = 0;
	    while(b>2){
	    	ans+=(b-2)/2;
	    	b-=2;
	    }
	    return ans;
    }
};



//Second Solution :-
//When you look closely it is nothing just sum of n/2 - 1 digits
int countSquare(int B)
{
	int newBase = (B/2)-1;
	return (newBase*(newBase+1))/2;
}

