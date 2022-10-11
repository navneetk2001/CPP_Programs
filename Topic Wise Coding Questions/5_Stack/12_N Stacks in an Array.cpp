https://www.codingninjas.com/codestudio/problems/n-stacks-in-an-array_1164271?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0?source=youtube&campaign=Lovebabbarcodestudio11thfeb&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio11thfeb



//Solution Approach :-
class NStack{ 
    int *arr;         //arr is the array itself in which n stacks are to be implemented
    int *top;         //top stores the top element of each stack
    int *next;        //next stores the next freeSpot of each index
    
    int n, s;         // n is no of stack and s is size of array
    int freespot;     //stores freeSpot in the array to insert
    
public:
    // Initialize your data structure.
    NStack(int N, int S){
        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];

        for(int i=0; i<n; i++) {        //top initialise
            top[i] = -1;
        }

        for(int i=0; i<s; i++) {        //next initialise
            next[i] = i+1;
        }

        next[s-1] = -1;        //update last index value to -1 b/c there is no next freeSpot for last index
        freespot = 0;          //initialise freespot
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m){
        if(freespot == -1) {        //check for overflow  //if freeSpot is -1 then no element can be pushed
            return false;
        }
       
        int index = freespot;        //find index
        arr[index] = x;              //insert element into array
        freespot = next[index];      //update freespot
        next[index] = top[m-1];      //update next;
        top[m-1] = index;            //update top
        
        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m){
        if(top[m-1] == -1){     //check underflow condition    //if there is no element to be popped return -1
            return -1;
        }
        
        int index= top[m-1];          // Find the index of the top element of the stack.
        top[m-1] = next[index];       // Remove the element from the stack by updating the head/top of the stack list.
        next[index] = freespot;       // Add the free slot to the free list.
        freespot = index;
        
        return arr[index];            // Return the popped element
    }
};




//Second Solution :-
/*
	Time complexity: O(1) for all operations.
	Space Complexity: O(S + N)
	
	Where S is the size of the array, 
    N is the number of stacks.
*/

class NStack
{
    // Array to implement the stacks.
    vector<int> arr;

    // Array to keep track of the indices of the top elements of every stack.
    vector<int> top;

    int n, s;

public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        n = N;
        s = S;

        // Create the arrays.
        arr = vector<int>(s);
        top = vector<int>(n);

        // Initialise the 'top' array.
        int count = s / n;
        for (int i = 0; i < n; i++)
        {
            top[i] = i * count - 1;
        }
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        if (top[m - 1] >= ((m * s) / n - 1))
        {
            // Stack overflow. So, element cannot be inserted.
            return false;
        }

        // Update the index of the new top element.
        top[m - 1]++;

        // Insert the element X into the stack.
        arr[top[m - 1]] = x;

        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        if (top[m - 1] < (m - 1) * (s / n))
        {
            // Stack is empty. So, return -1.
            return -1;
        }

        // Pop the top element of Mth stack.
        int element = arr[top[m - 1]];

        // Update the index of the new top element.
        top[m - 1]--;

        return element;
    }
};


