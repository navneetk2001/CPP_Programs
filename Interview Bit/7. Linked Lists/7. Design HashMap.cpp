https://leetcode.com/problems/design-hashmap/




//Solution Approach :- Using array
//but it won't work for size greater than 1e7.
//So, we will use vector of list with chaining and hash function

class MyHashMap {
public:
    int data[1000001];
    MyHashMap() {
        fill(data, data + 1000000, -1);
    }
    void put(int key, int val) {
        data[key] = val;
    }
    int get(int key) {
        return data[key];
    }
    void remove(int key) {
        data[key] = -1;
    }
};




//Second Solution :- Using vector of list
class MyHashMap {
public:
    vector<list<pair<int,int>>> m;
    int siz;
    
    MyHashMap() {
        siz=100;
        m.resize(siz);
    }
    
    int hash(int key){
        return key%siz;
    }
    
    list<pair<int,int>>:: iterator search(int key){
        int i=hash(key);
        list<pair<int,int>>:: iterator it;
        
        for(it=m[i].begin(); it!=m[i].end(); it++){
            if(it->first == key) return it;
        }
        return it;
    }
    
    void put(int key, int value) {
        int i=hash(key);
        remove(key);
        m[i].push_back({key,value});
    }
    
    int get(int key) {
        int i=hash(key);
        list<pair<int,int>>:: iterator it=search(key);
        if(it==m[i].end()) return -1;
        else return it->second;
    }
    
    void remove(int key) {
        int i=hash(key);
        list<pair<int,int>>:: iterator it=search(key);
        if(it!=m[i].end()) m[i].erase(it);
    }
};





//Third Solution :- 

class MyHashMap {
	vector<vector<pair<int, int>>> map;
	const int size = 10000;
public:
	/** Initialize your data structure here. */
	MyHashMap() {
		map.resize(size);
	}

	/** value will always be non-negative. */
	void put(int key, int value) {
		int index = key % size;
        vector<pair<int, int>> &row = map[index];
        for(auto iter = row.begin(); iter != row.end(); iter++)
        {
            if(iter->first == key)
            {
                iter->second = value;
                return;
            }
        }
		row.push_back(make_pair(key, value));
	}

	/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
	int get(int key) {
		int index = key % size;
        vector<pair<int, int>> &row = map[index];
		for (auto iter = row.begin(); iter != row.end(); iter++)
		{
			if (iter->first == key)
			{
				return iter->second;
			}
		}
		return -1;
	}

	/** Removes the mapping of the specified value key if this map contains a mapping for the key */
	void remove(int key) {
		int index = key % size;
        vector<pair<int, int>> &row = map[index];
		for (auto iter = row.begin(); iter != row.end(); iter++)
		{
			if (iter->first == key)
			{
				row.erase(iter);
                return;
			}
		}
	}
};

