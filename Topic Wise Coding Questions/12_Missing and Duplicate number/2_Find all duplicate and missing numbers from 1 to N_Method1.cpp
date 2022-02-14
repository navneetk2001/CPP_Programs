// First Approach :- Use Sorting
Sort the input array.
Traverse the array and check for missing and repeating.


// Second Approach :- Use count array
Approach: 
Create a temp array temp[] of size n with all initial values as 0.
Traverse the input array arr[], and do following for each arr[i] 
if(temp[arr[i]] == 0) temp[arr[i]] = 1;
if(temp[arr[i]] == 1) output “arr[i]” //repeating
Traverse temp[] and output the array element having value as 0 (This is the missing element)


// Third Approach :- Use elements as Index and mark the visited places
// C++ program to Find the repeating
// and missing elements
 
#include <bits/stdc++.h>
using namespace std;
 
void printTwoElements(int arr[], int size)
{
    int i;
    cout << " The repeating element is ";
 
    for (i = 0; i < size; i++) {
        if (arr[abs(arr[i]) - 1] > 0)
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
        else
            cout << abs(arr[i]) << "\n";
    }
 
    cout << "and the missing element is ";
    for (i = 0; i < size; i++) {
        if (arr[i] > 0)
            cout << (i + 1);
    }
}
 
/* Driver code */
int main()
{
    int arr[] = { 7, 3, 4, 5, 5, 6, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printTwoElements(arr, n);
}
 


 //Fourth Approach :- Make two equations
#include <bits/stdc++.h>
using namespace std;
 
/* The output of this function is stored at
*x and *y */
void getTwoElements(int arr[], int n,
                    int* x, int* y)
{
    /* Will hold xor of all elements
    and numbers from 1 to n */
    int xor1;
 
    /* Will have only single set bit of xor1 */
    int set_bit_no;
 
    int i;
    *x = 0;
    *y = 0;
 
    xor1 = arr[0];
 
    /* Get the xor of all array elements */
    for (i = 1; i < n; i++)
        xor1 = xor1 ^ arr[i];
 
    /* XOR the previous result with numbers
    from 1 to n*/
    for (i = 1; i <= n; i++)
        xor1 = xor1 ^ i;
 
    /* Get the rightmost set bit in set_bit_no */
    set_bit_no = xor1 & ~(xor1 - 1);
 
    /* Now divide elements into two
    sets by comparing a rightmost set
    bit of xor1 with the bit at the same
    position in each element. Also,
    get XORs of two sets. The two
    XORs are the output elements.
    The following two for loops
    serve the purpose */
    for (i = 0; i < n; i++) {
        if (arr[i] & set_bit_no)
            /* arr[i] belongs to first set */
            *x = *x ^ arr[i];
 
        else
            /* arr[i] belongs to second set*/
            *y = *y ^ arr[i];
    }
    for (i = 1; i <= n; i++) {
        if (i & set_bit_no)
            /* i belongs to first set */
            *x = *x ^ i;
 
        else
            /* i belongs to second set*/
            *y = *y ^ i;
    }
 
    /* *x and *y hold the desired
        output elements */
}
 
/* Driver code */
int main()
{
    int arr[] = { 1, 3, 4, 5, 5, 6, 2 };
    int* x = (int*)malloc(sizeof(int));
    int* y = (int*)malloc(sizeof(int));
    int n = sizeof(arr) / sizeof(arr[0]);
 
    getTwoElements(arr, n, x, y);
    cout << " The missing element is " << *x << " and the repeating"
         << " number is " << *y;
    getchar();
}


//Fifth Method :- Use a Map
#include <iostream>
#include <unordered_map>
using namespace std;
 
int main()
{
    int arr[] = { 4, 3, 6, 2, 1, 1 };
    int n = 6;
     
    unordered_map<int, bool> numberMap;
     
    for(int i : arr)
    {
        if (numberMap.find(i) ==
            numberMap.end())
        {
            numberMap[i] = true;
        }
        else
        {
            cout << "Repeating = " << i;
        }
    }
    cout << endl;
     
    for(int i = 1; i <= n; i++)
    {
        if (numberMap.find(i) ==
            numberMap.end())
        {
            cout << "Missing = " << i;
        }
    }
    return 0;
}


// Sixth Method :- Make two equations using sum and sum of squares
#include <bits/stdc++.h>
 
using namespace std;
 
vector<int>repeatedNumber(const vector<int> &A) {
    long long int len = A.size();
    long long int Sum_N = (len * (len+1) ) /2, Sum_NSq = (len * (len +1) *(2*len +1) )/6;
    long long int missingNumber=0, repeating=0;
     
    for(int i=0;i<A.size(); i++){
       Sum_N -= (long long int)A[i];
       Sum_NSq -= (long long int)A[i]*(long long int)A[i];
    }
     
    missingNumber = (Sum_N + Sum_NSq/Sum_N)/2;
    repeating= missingNumber - Sum_N;
    vector <int> ans;
    ans.push_back(repeating);
    ans.push_back(missingNumber);
    return ans;
     
}

int main(void){
        std::vector<int> v = {4, 3, 6, 2, 1, 6,7};
    vector<int> res = repeatedNumber(v);
    for(int x: res){
        cout<< x<<"  ";
    }
    cout<<endl;
}


// Seventh Method :- Using OR Operator
#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    // Input:
    vector<int> arr = {4, 3, 6, 2, 1, 1};
    int n = arr.size();
     
    // Declaring output variables
    // Note : arr[i]-1 is used instead of arr[i] as we want to use all 64 bits
    int bitOr = (1 << (arr[0]-1));
    int repeating, missing;
     
    // Performing XOR as well as Checking repeating number
    for(int i=1; i<n; i++){
        // If OR operation with 1 gives same output that means, we already have 1 at that position
        if((bitOr | (1 << (arr[i]-1))) == bitOr) {
            repeating = arr[i];
            continue;
        }
        bitOr = (bitOr | (1 << (arr[i]-1)));
    }
     
    // Checking missing number
    for(int i=0; i<n; i++){
        // property: OR with 0 yield 1 hence value of bitOr changes
        if((bitOr | (1 << i)) != bitOr) {
            missing = i+1;
            break;
        }
    }
     
    cout << "Repeating : " << repeating << "\nMissing : " << missing;
    return 0;
}