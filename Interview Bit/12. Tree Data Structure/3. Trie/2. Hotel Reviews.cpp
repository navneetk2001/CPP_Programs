// Given a set of reviews provided by the customers for different hotels and a string containing Good Words, you need to sort the reviews in descending order according to their Goodness Value (Higher goodness value first). We define the Goodness Value of a string as the number of Good Words in that string.
// NOTE: Sorting should be stable. If review i and review j have the same Goodness Value then their original order would be preserved.
// You are expected to use Trie in an Interview for such problems

// Input 1:
//  A = "coolicewifi"
//  B = ["wateriscool", "coldicedrink", "coolwifispeed"]
// Output 1: [2, 0, 1]
// Explanation 1: sorted reviews are ["coolwifispeed", "wateriscool", "coldicedrink"]

//Hint :-
//To calculate the “Goodness Value’’ of a review you need to check whether a word in the review is good or not. How can you reduce the time complexity of this checking? Brute force is O(N) per word.

//Solution Approach :- 
// Through a little try, we would know that “Trie” is the best solution. You just need to make a trie of all the good words and check the goodness of each word in a review using the trie.
// ** Algorithm: **
// Insert all the good words in a trie.
// For each review, calculate the number of good words in it by checking whether a given word exist in trie or not.
// Output as needed by the solution.


//First Solution :-
struct trie{
    int isLeaf;
    trie *child[26];
};

trie *getNode(){
    trie *node = new trie();
    for(int i=0; i<26; i++){
        node->child[i] = NULL;
    }
    node->isLeaf = 0;
    
    return node;
}

void insert(trie *A, string s){
    trie *curr = A;
    for(int i=0; i<s.size(); i++){
        int idx = int(s[i] - 'a');
        if(!curr->child[idx]){
            curr->child[idx] = getNode();
        }
        curr = curr->child[idx];
    }
    curr->isLeaf = 1; 
}

int search(trie *A, string s){
    trie *curr = A;
    
    for(int i=0; i<s.size(); i++){
        int idx = int(s[i] - 'a');
        if(!curr->child[idx]){
            return 0;
        }
        curr = curr->child[idx];
    }
    return (curr && curr->isLeaf);
}

void convert(string &str){
    for(int i=0; i<str.size(); i++){        //Convert _ to spaces
		if(str[i] == '_'){
	     	str[i] = ' ';
		}
    }
    return;
}

bool cmp(const pair<int, int>& a, const pair<int, int>& b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first > b.first;	
}

vector<int> Solution::solve(string A, vector<string> &B){
    vector<int> v;
    vector<pair<int, int>> v1;

    trie *root = getNode();
    
    convert(A);
    string word;
    stringstream ss;
    ss<<A;

    while(ss>>word){
        insert(root, word);
    }
	
    int cnt;
    for(int i=0; i<B.size(); i++){
		convert(B[i]);
		ss.clear();

		ss<<B[i];
		cnt = 0;
		while(ss>>word)	{
		    if(search(root, word)){	
				cnt++;
			}
		}
		v1.push_back({cnt, i});
    }
    
    sort(v1.begin(), v1.end(), cmp);
    for(int i=0; i<B.size(); i++){
        v.push_back(v1[i].second);
    }
    
    return v;
}

//Second Solution :-
struct TrieNode {
  TrieNode* next[26];
  bool isWord;
  
  TrieNode(): isWord(false) {
    memset(next, 0, sizeof(TreeNode*) * 26);
  };
  
  void insert(const std::string&amp; words, size_t start, size_t end) {
      TrieNode* current = this;
      for (size_t i = start; i &lt; end; ++i) {
          if (!current-&gt;next[words[i] - 'a']) {
              current-&gt;next[words[i] - 'a'] = new TrieNode{};
          }
          current = current-&gt;next[words[i] - 'a'];
      }
      current-&gt;isWord = true;
  }
  
  bool query(const std::string&amp; words, size_t start, size_t end) {
      TrieNode* current = this;
      for (size_t i = start; i &lt; end; ++i) {
          if (!current-&gt;next[words[i] - 'a']) {
              return false;
          }
          current = current-&gt;next[words[i] - 'a'];
      }
      return current-&gt;isWord;
  }
};


vector&lt;int&gt; Solution::solve(string goodWords, vector&lt;string&gt;&amp; reviews) {
    const size_t NPOS = ~size_t(0);
    size_t wordStart = NPOS;
    TrieNode trie;
    for (size_t i = 0; i &lt; goodWords.size(); ++i) {
        if (goodWords[i] == '_' &amp;&amp; wordStart != NPOS) {
            trie.insert(goodWords, wordStart, i);
            wordStart = NPOS;
        } else if (goodWords[i] != '_' &amp;&amp; wordStart == NPOS) {
            wordStart = i;
        }
    }
    if (wordStart != NPOS) {
        trie.insert(goodWords, wordStart, goodWords.size());
    }
    
    typedef std::pair&lt;int /* idx */, int /* score */&gt; IdxScore;
    std::vector&lt;IdxScore&gt; scores;
    scores.reserve(reviews.size());
    
    for (int i = 0; i &lt; reviews.size(); ++i) {
        int score = 0;
        const auto&amp; review = reviews[i];
        wordStart = NPOS;
        for (size_t i = 0; i &lt; review.size(); ++i) {
            if (review[i] == '_' &amp;&amp; wordStart != NPOS) {
                score += trie.query(review, wordStart, i);
                wordStart = NPOS;
            } else if (review[i] != '_' &amp;&amp; wordStart == NPOS) {
                wordStart = i;
            }
        }
        if (wordStart != NPOS) {
            score += trie.query(review, wordStart, review.size());
        }

        scores.emplace_back(i, score);
    }
    
    std::stable_sort(scores.begin(), scores.end(), [](const IdxScore&amp; lhs, const IdxScore&amp; rhs) {
       return lhs.second &gt; rhs.second; 
    });
    
    std::vector&lt;int&gt; result;
    result.reserve(reviews.size());
    
    for (const auto&amp; p: scores) {
        result.push_back(p.first);
    }
    
    return result;
}






//Third Solution :- 
const int mxN =1e5+2 ;
#define ar array
int c[mxN+1][26],n=1,ok[mxN+1]; 
void insert(string s){
	int u=0 ;
	for(char x:s){
	if(!c[u][x-'a']){
	  	c[u][x-'a']=n++ ;
	}
	u=c[u][x-'a'] ;
	}
	ok[u]=1 ;
}

bool find(string s){
  int u=0 ;
  for(char x:s){
    if(!c[u][x-'a'])
      return 0 ;
    u=c[u][x-'a'] ;
  }
  return ok[u]  ;
}

vector<int> Solution::solve(string A, vector<string> &B) {
	stringstream x(A);
	string t  ;
	while(getline(x,t,'_'))
		insert(t) ;
	vector<ar<int,2>>a ;
	for(int i=0;i<B.size();i++){
		int c=0 ;
		stringstream y(B[i]) ;
		while(getline(y,t,'_'))
			c+=find(t) ; 
		a.push_back({i,c}) ;
	}
	sort(a.begin(),a.end(),[&](const ar<int,2>&i,const ar<int,2>&j){
	    return (i[1]>j[1]||(i[1]==j[1]&&i[0]<j[0])) ;
	});

	vector<int>ans ;
	for(ar<int,2> x:a)
		ans.push_back(x[0]) ;
	memset(c,0,sizeof(c)) ;
    memset(ok,0,sizeof(ok)) ;n=1 ;
	return ans   ;
}

