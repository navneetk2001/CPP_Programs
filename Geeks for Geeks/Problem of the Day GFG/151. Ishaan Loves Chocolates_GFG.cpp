// As we know, Ishaan has a love for chocolates. He has bought a huge chocolate bar that contains N chocolate squares. Each of the squares has a tastiness level which is denoted by an array A[].
// Ishaan can eat the first or the last square of the chocolate at once. Ishaan has a sister who loves chocolates too and she demands the last chocolate square. Now, Ishaan being greedy eats the more tasty square first. 
// Determine the tastiness level of the square which his sister gets.

// Example 1:
// Input : arr[ ] = {5, 3, 1, 6, 9}
// Output : 1
// Explanation:
// Initially: 5 3 1 6 9
// In first step: 5 3 1 6
// In Second step: 5 3 1
// In Third step: 3 1
// In Fourth step: 1
// Return 1

// Example 2:
// Input : arr[ ] = {5, 9, 2, 6} 
// Output :  2




//Solution Approach :-
int chocolates(int arr[], int n){
    int i = 0, j = n-1 ;
    
    while( i != j ){
        if(arr[i] > arr[j]){
            i++;
        }
        else{
            j--;
        }
    }
    return arr[i] ;
}



//Second Solution :-
int chocolates(int arr[], int n)
{
    return *min_element(arr,arr+n);
}


