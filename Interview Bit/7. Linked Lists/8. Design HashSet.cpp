https://leetcode.com/problems/design-hashset/




//Solution :- Using Array :- 
class MyHashSet {
private:
	vector<bool> table;
public:
	MyHashSet() : table(1e6 + 1, false) {}
	
	void add(int key) {
		table[key] = true;
	}
	
	void remove(int key) {
		table[key] = false;
	}
	
	bool contains(int key) {
		return table[key];
	}
};




//Second Solution :- Using Vector of lists
class MyHashSet {
private:
	int prime;
	vector<list<int>> table;

	int hash(int key) {
		return key % prime;
	}

	list<int>::iterator search(int key) {
		int h = hash(key);
		return find(table[h].begin(), table[h].end(), key);
	}

public:
	MyHashSet() : prime(10007), table(prime) {}
	
	void add(int key) {
		int h = hash(key);
		if (!contains(key)){
			table[h].push_back(key);
		}
	}
	
	void remove(int key) {
		int h = hash(key);
		auto it = search(key);
		if(it != table[h].end()){
			table[h].erase(it);
		}
	}
	
	bool contains(int key) {
		int h = hash(key);
		return search(key) != table[h].end();
	}
};




//Third Solution :- Table-Doubling
class MyHashSet {
private:
	int m_size, capacity;
	double load_factor;
	vector<list<int>> table;

	int hash(int key) {
		return key % capacity;
	}

	list<int>::iterator search(int key) {
		int h = hash(key);
		return find(table[h].begin(), table[h].end(), key);
	}

	void rehash() {
	    m_size = 0;
		capacity = max(2, capacity);
		vector<list<int>> old_table(move(table));
		table = vector<list<int>>(capacity);
		
		for (list<int>& chain: old_table)
			for (int& key: chain)
				add(key);
	}

public:
	MyHashSet() : m_size(0), capacity(2), load_factor(0.75), table(capacity) {}
	
	void add(int key) {
		if (contains(key))
			return;
		
		m_size++;
		int h = hash(key);
		table[h].push_back(key);
		
		if (m_size >= load_factor * capacity) {
			capacity *= 2;
			rehash();
		}
	}
	
	void remove(int key) {
		int h = hash(key);
		auto it = search(key);
		
		if (it == table[h].end())
			return;
		
		m_size--;
		table[h].erase(it);
		
		if (m_size <= 0.5 * load_factor * capacity) {
			capacity /= 2;
			rehash();
		}
	}
	
	bool contains(int key) {
		int h = hash(key);
		return search(key) != table[h].end();
	}
};