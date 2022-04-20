// Find shortest unique prefix to represent each word in the list.

// Example:
// Input: [zebra, dog, duck, dove]
// Output: {z, dog, du, dov}
// where we can see that
// zebra = z
// dog = dog
// duck = du
// dove = dov


//Hint :-
Hint : Prefix tree or Trie ( https://www.topcoder.com/community/data-science/data-science-tutorials/using-tries/ )
Assume you have all the prefixes of the word stored in the tree along with their frequencies. Is it possible to arrive at the solution now ?

//Solution Approach :- 
Lets take an example:
input: ["zebra", "dog", "duck", "dot"]
Now we will build prefix tree and we will also store count of characters
                root
                /|
         (d, 3)/ |(z, 1)
              /  |
          Node1  Node2
           /|        \
     (o,2)/ |(u,1)    \(e,1)
         /  |          \
   Node1.1  Node1.2     Node2.1
      | \         \            \
(g,1) |  \ (t,1)   \(c,1)       \(b,1)
      |   \         \            \ 
    Leaf Leaf       Node1.2.1     Node2.1.1
    (dog)  (dot)        \                  \
                         \(k, 1)            \(r, 1)
                          \                  \   
                          Leaf               Node2.1.1.1
                          (duck)                       \
                                                        \(a,1)
                                                         \
                                                         Leaf
                                                         (zebra)

Now, for every leaf / word , we find the character nearest to the root with frequency as 1. 
The prefix that the path from root to this character corresponds to, is the representation of the word. 


//First Solution :- Using Tries
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

vector<string> Solution::prefix(vector<string> &arr) {
    int n=arr.size();
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


//Second Solution :-
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


//Third Solution :- 
vector<string> Solution::prefix(vector<string> &A) 
{
    vector<string> solution;
    
    for (int i = 0; i < A.size(); i++)
    {
        int necessaryChars = 1;
        int maxNC = necessaryChars;
        
        for (int j = 0; j < A.size(); j++)
        {
            if (A[j].compare(A[i]) == 0)
            {
                continue;
            }
            for (int k = 0; k < A[j].length(); k++)
            {
                if (A[j][k] == A[i][k])
                {
                    necessaryChars++;
                }
                else
                {
                    break;
                }
            }
            if (necessaryChars > maxNC)
            {
                maxNC = necessaryChars;
            }
            necessaryChars = 1;
        }
        
        solution.push_back(A[i].substr(0, maxNC));
    }
    return solution;
}


