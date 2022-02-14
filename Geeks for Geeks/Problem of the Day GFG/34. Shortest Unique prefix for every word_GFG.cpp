// Given an array of words, find all shortest unique prefixes to represent each word in the given array. Assume that no word is prefix of another.

// Example 1:
// Input: 
// N = 4
// arr[] = {"zebra", "dog", "duck", "dove"}
// Output: z dog du dov
// Explanation: 
// z => zebra 
// dog => dog 
// duck => du 
// dove => dov 

// Example 2:
// Input: 
// N = 3
// arr[] =  {"geeksgeeks", "geeksquiz",
//                        "geeksforgeeks"};
// Output: geeksg geeksq geeksf
// Explanation: 
// geeksgeeks => geeksg 
// geeksquiz => geeksq 
// geeksforgeeks => geeksf

// Expected Time Complexity: O(N*length of each word)
// Expected Auxiliary Space: O(N*length of each word)


//Brute Force :- For each word we have to find shortest unique prefix by comparing with all other words

//Optimal Approach :- Trie DS
//We will maintain a root and with each char, a count will be there which records the count of that word


// trie node
class TrieNode
{
public:
	TrieNode *arr[26];   //representing it as a-'a'=0, b-'a'=1,  z-'a'=25
	int cnt;    //cnt will store the frequency of element 
	TrieNode(){
		for (int i=0;i<26;i++){
			arr[i] = NULL;
		}
		cnt=0;
	}
};


// If not present, inserts ith string into trie 
void insert_string(TrieNode *root, string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if(root->arr[s[i]-'a'] == NULL){    //if curr_char doesn't exist, then make that new char
			root->arr[s[i]-'a'] = new TrieNode();
		}                       //else if present move to that character
		root=root->arr[s[i]-'a'];
		(root->cnt)++;     //and if present then simply increase its count by one
	}
}


class Solution
{
    public:
    vector<string> findPrefixes(string arr[], int n)
    {
        TrieNode* root = new TrieNode();
        for(int i=0;i<n;i++){     //insert ith word in a trie
        	insert_string(root, arr[i]);
        }

        vector<string>ans;
        for(int i=0;i<n;i++){
        	string s=arr[i];
        	TrieNode* node=root;
        	for(int j=0;j<s.length();j++){
        		node = node->arr[s[j]-'a'];
        		if(node->cnt==1){
        			ans.push_back(s.substr(0, j+1));
        			break;
        		}
        	}
        }
        return ans;
    }
};



//Brute Force Approach :-
class Solution
{
    public:
    vector<string> findPrefixes(string arr[], int n)
    {
        vector<string> v(n,"");
        
        for(int j=0;j<n;j++){
          //  v[j].push_back(arr[j][0]);
            for(int i=0;i<arr[j].size();i++){
                bool u=false;
                for(int k=0;k<n;k++){
                    if(k==j)continue;
                    if(arr[k].size()>i && arr[j].substr(0,i)==arr[k].substr(0,i)){
                       u=true;
                       break;
                    }
                }
                if(u){
                    v[j].push_back(arr[j][i]);
                }else{
                   
                    break;
                }
                    
            
            }
            
        }
        return v;
    }
    
};