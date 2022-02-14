// Given a string A and a dictionary of n words B, find out if A can be segmented into a space-separated sequence of dictionary words. 

// Example 1:
// Input:
// n = 12
// B = { "i", "like", "sam", "sung", "samsung",
// "mobile","ice","cream", "icecream", "man",
// "go", "mango" }, A = "ilike"
// Output: 1
// Explanation: The string can be segmented as 
// "i like".

// Example 2:
// Input:
// n = 12
// B = { "i", "like", "sam", "sung", 
// "samsung", "mobile","ice","cream", "icecream",
// "man", "go", "mango" }, A = "ilikesamsung"
// Output: 1
// Explanation: The string can be segmented as 
// "i like samsung" or "i like sam sung".




//Using Tries :-It has nodes and edged
//TrieNode :- A trieNode array of length 26 a boolean variable


// C++ implementation of search and insert
// operations on Trie
#include <bits/stdc++.h>
using namespace std;
const int ALPHABET_SIZE = 26;

// trie node
class TrieNode
{
	TrieNode *children[ALPHABET_SIZE];
	bool EndOfWord;    //EndOfWord is true if the node represents end of a word

	TrieNode(){
		children=new TrieNode[26];
		for (int i=0;i<ALPHABET_SIZE;i++)
			children[i] = NULL;

		EndOfWord=false;
	}
};


// If not present, inserts key into trie If the key is prefix of trie node, just marks leaf node
void insert(TrieNode *root, string key)
{
	TrieNode *curr = root;
	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if (!curr->children[index])
			curr->children[index] = new TrieNode();

		curr = curr->children[index];
	}

	curr->EndOfWord = true;  // mark last node as leaf
}

// Returns true if key presents in trie, else
// false
bool search(TrieNode *root, string key)
{
	TrieNode *curr = root;

	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if (!curr->children[index])
			return false;

		curr = curr->children[index];
	}

	return (curr->EndOfWord);
}





class Solution{
	bool wordBreakUtil(string A, TrieNode *root){
		if(A.size()==0)
			return true;

		for(int i=0;i<A.size();i++){
			if(root.search(root,A.substr(0,i)) && wordBreakUtil(A.substr(i,A.string()),root))
				return true;
		}
		return false;
	}

	int wordBreak(string A, vector<string>B){
		TrieNode *root=new TrieNode();
		for(int i=0;i<B.size();i++){
			root.insert(root,B[i]);
		}

		bool res=wordBreakUtil(A,root);
		if(res)
			return 1;
		else
			return 0;
	}
}









// A DP and Trie based program to test whether a given string can be segmented into
// space separated words in dictionary
#include <iostream>
using namespace std;

const int ALPHABET_SIZE = 26;

// trie node
struct TrieNode
{
	struct TrieNode *children[ALPHABET_SIZE];

	// isEndOfWord is true if the node represents
	// end of a word
	bool isEndOfWord;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void)
{
	struct TrieNode *pNode = new TrieNode;

	pNode->isEndOfWord = false;

	for (int i = 0; i < ALPHABET_SIZE; i++)
		pNode->children[i] = NULL;

	return pNode;
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just
// marks leaf node
void insert(struct TrieNode *root, string key)
{
	struct TrieNode *pCrawl = root;

	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if (!pCrawl->children[index])
			pCrawl->children[index] = getNode();

		pCrawl = pCrawl->children[index];
	}

	// mark last node as leaf
	pCrawl->isEndOfWord = true;
}

// Returns true if key presents in trie, else
// false
bool search(struct TrieNode *root, string key)
{
	struct TrieNode *pCrawl = root;

	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if (!pCrawl->children[index])
			return false;

		pCrawl = pCrawl->children[index];
	}

	return (pCrawl != NULL && pCrawl->isEndOfWord);
}

// returns true if string can be segmented into
// space separated words, otherwise returns false
bool wordBreak(string str, TrieNode *root)
{
	int size = str.size();

	// Base case
	if (size == 0) return true;

	// Try all prefixes of lengths from 1 to size
	for (int i=1; i<=size; i++)
	{
		// The parameter for search is str.substr(0, i)
		// str.substr(0, i) which is prefix (of input
		// string) of length 'i'. We first check whether
		// current prefix is in dictionary. Then we
		// recursively check for remaining string
		// str.substr(i, size-i) which is suffix of
		// length size-i
		if (search(root, str.substr(0, i)) &&
			wordBreak(str.substr(i, size-i), root))
			return true;
	}

	// If we have tried all prefixes and none
	// of them worked
	return false;
}

// Driver program to test above functions
int main()
{
	string dictionary[] = {"mobile","samsung","sam",
						"sung","ma\n","mango",
						"icecream","and","go","i",
						"like","ice","cream"};
	int n = sizeof(dictionary)/sizeof(dictionary[0]);
	struct TrieNode *root = getNode();

	// Construct trie
	for (int i = 0; i < n; i++)
		insert(root, dictionary[i]);

	wordBreak("ilikesamsung", root)? cout <<"Yes\n": cout << "No\n";
	wordBreak("iiiiiiii", root)? cout <<"Yes\n": cout << "No\n";
	wordBreak("", root)? cout <<"Yes\n": cout << "No\n";
	wordBreak("ilikelikeimangoiii", root)? cout <<"Yes\n": cout << "No\n";
	wordBreak("samsungandmango", root)? cout <<"Yes\n": cout << "No\n";
	wordBreak("samsungandmangok", root)? cout <<"Yes\n": cout << "No\n";
	return 0;
}




//Another Solution :-Using Backtracking

/* A utility function to check whether a word
  is present in dictionary or not.  An array of
  strings is used for dictionary.  Using array
  of strings for dictionary is definitely not
  a good idea. We have used for simplicity of
  the program*/
int dictionaryContains(string &word)
{
    string dictionary[] = {"mobile","samsung","sam","sung",
                            "man","mango", "icecream","and",
                            "go","i","love","ice","cream"};
    int n = sizeof(dictionary)/sizeof(dictionary[0]);
    for (int i = 0; i < n; i++)
        if (dictionary[i].compare(word) == 0)
            return true;
    return false;
}

// Prototype of wordBreakUtil
void wordBreakUtil(string str, int size, string result);

// Prints all possible word breaks of given string
void wordBreak(string str)
{
    // Last argument is prefix
    wordBreakUtil(str, str.size(), "");
}

// Result store the current prefix with spaces
// between words
void wordBreakUtil(string str, int n, string result)
{
    //Process all prefixes one by one
    for (int i=1; i<=n; i++)
    {
        // Extract substring from 0 to i in prefix
        string prefix = str.substr(0, i);

        // If dictionary contains this prefix, then
        // we check for remaining string. Otherwise
        // we ignore this prefix (there is no else for
        // this if) and try next
        if (dictionaryContains(prefix))
        {
            // If no more elements are there, print it
            if (i == n)
            {
                // Add this element to previous prefix
                result += prefix;
                cout << result << endl;
                return;
            }
            wordBreakUtil(str.substr(i, n-i), n-i,
                                result + prefix + " ");
        }
    }      
}


//Another Solution :-

/* A utility function to check whether a word is
  present in dictionary or not. An array of strings
  is used for dictionary.  Using array of strings for
  dictionary is definitely not a good idea. We have
  used for simplicity of the program*/
int dictionaryContains(string word)
{
    string dictionary[] = {"mobile","samsung","sam","sung",
                            "man","mango","icecream","and",
                             "go","i","like","ice","cream"};
    int size = sizeof(dictionary)/sizeof(dictionary[0]);
    for (int i = 0; i < size; i++)
        if (dictionary[i].compare(word) == 0)
           return true;
    return false;
}
 
// returns true if string can be segmented into space
// separated words, otherwise returns false
bool wordBreak(string str)
{
    int size = str.size();
 
    // Base case
    if (size == 0)  return true;
 
    // Try all prefixes of lengths from 1 to size
    for (int i=1; i<=size; i++)
    {
        // The parameter for dictionaryContains is
        // str.substr(0, i) which is prefix (of input
        // string) of length 'i'. We first check whether
        // current prefix is in  dictionary. Then we
        // recursively check for remaining string
        // str.substr(i, size-i) which is suffix of 
        // length size-i
        if (dictionaryContains( str.substr(0, i) ) &&
            wordBreak( str.substr(i, size-i) ))
            return true;
    }
 
    // If we have tried all prefixes and
    // none of them worked
    return false;
}
 