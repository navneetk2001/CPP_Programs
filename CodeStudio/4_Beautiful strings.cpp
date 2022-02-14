/*
Beautiful String :-
Problem Statement
Suggest Edit
Ninja has been given a binary string ‘STR’ containing either ‘0’ or ‘1’. A binary string is called beautiful if it contains alternating 0s and 1s.
For Example:‘0101’, ‘1010’, ‘101’, ‘010’ are beautiful strings.
He wants to make ‘STR’ beautiful by performing some operations on it. In one operation, Ninja can convert ‘0’ into ‘1’ or vice versa.
Your task is to determine the minimum number of operations Ninja should perform to make ‘STR’ beautiful.

*/

// First Approach :- Find All Possible Beautiful Strings
/*
We observe that for any length of the given string ‘STR’, there are only two possible beautiful strings ie: one starting with ‘1’ and 
the other starting with ‘0’.
For example for ‘N’ = 4 , “1010” and “0101” are the only two possible beautiful strings.
Now, we just need to count the different values at the same index in a possible beautiful string and given ’STR’.
For example: If ‘STR’ = “1011”, there exist two beautiful strings of length 4 ie: “1010” and “0101”. 
The count of different values at same index in ‘STR’ and “1010” is 1 and ‘STR’ and “0101” is 3 respectively and 1 is the  
minimum of these two so we need only ‘1’ operation to convert ‘1011’ to ‘1010’. 
Algorithm:
Initialize four variables ‘T1’ = 0, ‘T2’ = 0,’S1’ = 0’ and ‘S2’ = 1 where ‘T1’ denotes the difference between values at indices in ‘STR’ and the possible beautiful string starting with 0 and ‘T2’ denotes the difference between values at indices in ‘STR’ and the possible beautiful string starting with 1.‘S1’ and ‘S2’ denote the expected value at index ‘i’ in both of the possible beautiful strings 
Iterate the given string ‘STR’ and do the following:
If ‘STR[i]’ == 1
If ‘S1’ == 0’ then T1++.
Else T2++.
If ‘STR[i]’ == 0
If ‘S1’ == 1 then T1++.
Else T2++
If ‘S1’ == 0’ then make it 1 and vise versa do the same for ‘S2’.
Finally return the minimum of ‘T1’ and ‘T2’.
*/

/*
    Time Complexity : O(|STR|)
    Space Complexity : O(1)

    Where |STR| is the length of STR

*/

int makeBeautiful(string str) 
{
    int n = str.length();

    // 'T1' denotes the difference between values at indices in 'STR' and the possible beautiful string starting with 0 
    // 'T2' denotes the difference between values at indices in 'STR' and the possible beautiful string starting with 1
    // 'S1' and 'S2' denote the expected value at index 'i' in both of the possible beautiful strings 
    int t1 = 0, t2 = 0;
    char s1 = '0', s2 = '1';

    for (int i = 0; i < n; i++) 
    {
        // Iterate over the string 
        if (str[i] == '1') 
        {
            if (s1 == '0') 
            {
                t1++;
            }
            else {
                t2++;
            }
        }

        // If 'STR[i]' == 0
        else 
        {
            if (s1 == '1') 
            {
                t1++;
            }
            else 
            {
                t2++;
            }
        }
        
        // If 'S1' == '0' then make it 1 and vise versa do the same for 'S2'
        if (s1 == '1') 
        {
            s1 = '0';
            s2 = '1';
        }
        else 
        {
            s1 = '1';
            s2 = '0';
        }
    }
    
    // Return the minimum of 'T1' and 'T2'
    return min(t1, t2);
}



//Second Approach :-
int makeBeautiful(string str) {
// Write your code here
   int n=str.length();
   string temp1="";
   string temp2="";
   int one=0,two=0;
   for(int i=0;i<n;i++)
   {
       if(i%2==0)
       {
           temp1=temp1+'1';
           temp2=temp2+'0';
       }
       else
       {
           temp1=temp1+'0';
           temp2=temp2+'1';    
       }
       if(temp1[i]!=str[i])
       {
           one++;
       }
       if(temp2[i]!=str[i])
       {
           two++;
       }
   }
   return min(one,two);
}