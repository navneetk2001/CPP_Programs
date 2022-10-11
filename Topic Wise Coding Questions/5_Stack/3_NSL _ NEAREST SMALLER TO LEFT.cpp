https://practice.geeksforgeeks.org/problems/smaller-on-left20360700/1




//Solution Approach :- 
vector<int> Smallestonleft(int arr[], int n)
{
    vector<int> v;         // creating a vector for storing result 
    stack<int> s;          // creating a stack for temp. hold the values from array
    
    for (int i=0;i<n;i++){ 
        if(s.size() ==0){       // when stack size is empty there is no element in stack return output as -1;
            v.push_back(-1);
        }
        else if (s.size()>0 && s.top()<arr[i]){  // when there is element in stack and stack top is less then array element 
            v.push_back(s.top());                // take stack top in the result vector 
        }
        else if (s.size()>0 && s.top()>=arr[i]){    // when there is element in stack and that element is grreater then array element 
            while(s.size()>0 && s.top()>=arr[i]){   // upto when there is element and stack top is greater then array's element delete the element from stack
                s.pop();                            // delete the element from stack
            }
            if (s.size()==0){                   // when stack became empty return -1
                v.push_back(-1);
            }
            else{
                v.push_back(s.top());
            }
        }
        s.push(arr[i]);                 // push array in stack
    }
    return v;
}
     

// Time Complexity: O(N)
// Auxiliary Space: O(N)




//Second Solution :-
vector<int> Smallestonleft(int arr[], int n)
{
   set<int> s;
   vector<int> ans;
   for (int i=0; i<n; i++){
       s.insert(arr[i]);
       if (s.lower_bound(arr[i])==s.begin()){
           ans.push_back(-1);
       }
       else{
           auto it=s.lower_bound(arr[i]);
           it--;
           ans.push_back(*it);
       }
   }
   return ans;
}



