// Given a linked list, the task is to complete the function maxPalindrome() which returns an integer denoting  the length of the longest palindrome list that exist in the given linked list.

// Example:
// Input:
// 2

// 7
// 2 3 7 3 2 12 24

// 5
// 12 4 4 3 14

// Output:
// 5
// 2
// Explanation: Testcase 1: 2 -> 3 -> 7 -> 3 -> 2 is the linked list whose nodes leads to a palindrome as 2 3 7 3 2.




//Solution Approach :-
// same as leetcode 5, longest palindromic substring
// while reversing Linked List at any step prev nodes are reversed and upcoming nodes are not reversed so we can check palindrome checking palindrome using expand from middle method 

int expand(Node *h1, Node *h2){
    int ans =0;
    while(h1 && h2){
        if(h1->data == h2->data){
            ans++;
            h1 = h1->next;
            h2 = h2->next;
        }
        else{
        	break;
        }
    }
    return 2 * ans;
}

int maxPalindrome(Node *head){
    if(!head) return 0;
    if(!head->next) return 1;
    
    Node *curr = head, *nxt = head->next ,*prev = NULL;
    
    int ans =0;
    while(curr){
        nxt  = curr->next;
        curr->next = prev;
        
        //odd length palindrome 
        ans = max(ans,expand(prev,nxt)+1);
        
        //even length palindrome 
        ans = max(ans,expand(curr,nxt));
        
        prev = curr;
        curr= nxt;
    }
    return ans;
}



//Second Solution :-
int maxPalindrome(Node *head){
    vector<int> v;
    int fans = 0;
    int ans = 0;

    while(head){
        v.push_back(head->data);
        
        // for odd size palindrome
        int n = v.size()-1;
        Node *curr = head->next;
        ans = 1;
        while(curr!=NULL && n>=0)
        {
            if(v[--n]==curr->data)
            {
                ans+=2;
                curr = curr->next;
            }
            else{
                break;
            }
        }
        fans = max(fans, ans);
        
        // for even size palindrome
        curr = head;
        ans = 0;
        n = v.size()-1;
        while(curr!=NULL && n>=0)
        {
            if(v[--n]==curr->data)
            {
                ans+=2;
                curr = curr->next;
            }
            else{
                break;
            }
        }
        fans = max(fans, ans);
        head = head->next;
    }
    return fans;
}




//Third Solution :-
//Expand Around center for even and odd length palindrome

int helper(Node* prev, Node* head){
    int res = 0; 
    while(prev && head && head->data == prev->data){
        res++;
        prev = prev->next;
        head = head->next;
    }
    return res;
}

int maxPalindrome(Node *head)
{
    Node* prev = NULL;
    int ans = 1;
    while(head){
        Node* nextNode =  head->next;
        head->next = prev;
        prev = head;
        head = nextNode;
        ans = max(ans, 2 * helper(prev, head));
        if(head){
            ans = max(ans, 1 + 2 * helper(prev, head->next));
        }
    }
    return ans;
}



//Fourth Solution :-
int palin(vector<int>& v,int i,int j)
{
	int n=v.size();
	while(i>=0 && j<n)
	{
	   	if(v[i]!=v[j]){
	       	break;
	   	}
	   	i--;
	   	j++;
	}
	return (j-1)-(i+1)+1;
}

int maxPalindrome(Node *head){
	vector<int> v;
	Node* temp = head;

	while(temp){
	    v.push_back(temp->data);
	   	temp=temp->next;
	}

	int maxi=0;
	for(int i=0;i<v.size();i++){
	   	maxi=max(maxi,palin(v,i,i));
	}
	for(int i=0;i<v.size()-1;i++){
	   	maxi=max(maxi,palin(v,i,i+1));
	}
   	
   	return maxi;
}



//Fifth Solution :- DP Solution 
#include<vector>
int maxPalindrome(Node *head){
    vector<int>v;
    while(head){
        v.push_back(head->data);
        head=head->next;
    }
    int n=v.size();
    vector<vector<bool>>dp(n,vector<bool>(n,false));
    for(int i=0;i<n;i++){
        dp[i][i]=1;
    }
    int ans=1;
    for(int i=0;i<n-1;i++){
        if(v[i]==v[i+1]){
            dp[i][i+1]=true;
            ans=2;
        }
    }
    for(int k=3;k<=n;k++){
        for(int i=0;i<=n-k+1;i++){
            int j=i+k-1;
            if(v[i]==v[j] and dp[i+1][j-1]){
                dp[i][j]=1;
                ans=max(ans,k);
            }
        }
    }
    return ans;
}