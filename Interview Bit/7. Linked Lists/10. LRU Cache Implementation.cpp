https://leetcode.com/problems/lru-cache/




//Solution Approach :- 
//Firstly, the Least Recently Used does not mean the most visited, but refers to to the cache which was just recently used and the list will be ordered in accordance in which cache was latest and recent in use.
//We here use two maps to facilitate operation in O(1), one to store corresponding value of keys and other for corresponding position of the key in the list. The doubly linked list strucure (simply, list in C++ STL) is used as it can remove itself without any reference compared to singly linked list (forward_list in C++ STL, which use erase_after).

class LRUCache {
public:
    map <int, int> keyval;                    //One map to store the key and its corresponding value to facilitate O(1) time complexity
    map <int, list<int>::iterator> keypos;    //Similarly, one map to store the key and its corresponding positionn in the list
    
    list <int> keys;                          //A doubly linked list of keys
    int siz,cap;                              //Global variable siz and cap for other functions to know size and the total capacity of the cache
    
    LRUCache(int capacity) {
        cap = capacity;                       //Initializing the LRU cache with the given positive size capacity.
        siz = 0;                              //Keeping count of the total existing elements, which is initially 0       
    }
	
    int get(int key) {
        if (keyval.find(key)==keyval.end()){   //If the key doesn't exist in the LRU Cache, simply return -1
            return -1;
        }
        
        //💡Since key exists we have to move key to front of the list (as it is now the least recently used cache) and return val    
        //So, firstly erase key and its old position
        auto it = keypos[key];                  //Get the position of key in the list. This helps for searching list in O(1) throughout code.
        keys.erase(it);                         //Removing the key from our keys list
        keypos.erase(key);                      //And also erasing its position stored in the keypos map
        
        //Now push the key at front of the list and update its position in our map 
        keys.push_front(key);
        keypos[key]=keys.begin();
        
        //didn't update the value of list in get() so simply return it
        return keyval[key];
    }
    
    void put(int key, int value) {
        /*💡We have to place the key at front as it is now the LRU . If it already exists in the cache so firstly delete it and put up front.
        Also we have to evict the last key from our list if the capacity is already full. Will write similar code like get () and simply mantain the data strucure we have created to facilitate O(1) average time complexity. */
        
        //So, firstly, if exist somewhere then delete so that it can be technically moved to front
        if (keyval.find(key) != keyval.end()){
            auto it=keypos[key];
            keys.erase(it);
            keypos.erase(key);
            keyval.erase(key);
            siz--;
        }
        
        //Do check if capacity is reached then delete key from the last of the list
        if (siz == cap){
            int lkey=keys.back();
            keys.pop_back();
            keypos.erase(lkey);
            keyval.erase(lkey);
            siz--;
        }
        
        //Now, simply place the new key at front of the list and mantain all the data structure we have created.
        keys.push_front(key);
        keypos[key]=keys.begin();
        keyval[key]=value;
        siz++;
    }
};





//Second Solution :- 
class LRUCache {
public:
    class node {
        public:
            int key;
            int val;
            node* next;
            node* prev;
       
        node(int _key, int _val) {
            key = _key;
            val = _val; 
        }
    };
    
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    
    int cap;
    unordered_map<int, node*> m;
    
    LRUCache(int capacity) {
        cap = capacity;    
        head->next = tail;
        tail->prev = head;
    }
    
    void addnode(node* newnode) {
        node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }
    
    void deletenode(node* delnode) {
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    
    int get(int key_) {
        if (m.find(key_) != m.end()) {
            node* resnode = m[key_];
            int res = resnode->val;
            m.erase(key_);
            deletenode(resnode);
            addnode(resnode);
            m[key_] = head->next;
            return res; 
        }
    
        return -1;
    }
    
    void put(int key_, int value) {
        if(m.find(key_) != m.end()) {
            node* existingnode = m[key_];
            m.erase(key_);
            deletenode(existingnode);
        }
        if(m.size() == cap) {
          m.erase(tail->prev->key);
          deletenode(tail->prev);
        }
        
        addnode(new node(key_, value));
        m[key_] = head->next; 
    }
};



//Third Solution :-
// In this question we have to keep track of the most least recently used item in the cache. I have designed the cache using list and map in C++.
// We do it by following the steps below :-

// When we access an item in the cache it moves to the front of the list as it is the most recently used item.
// When we want to remove an item we remove it from the last of the list as it is the least recently used item in the cache.
// When we insert an item we insert it into the front of the list as it is the most recently used item.
// The idea is to store the keys in the map and its corrosponding values into the list...
// Note : splice() function here takes the element at the m[key] and places it at the beginning of the list...

class LRUCache{
public:
    list<pair<int,int>> l;
    unordered_map<int,list<pair<int, int>>::iterator> m;
    int size;
    
    LRUCache(int capacity){
        size=capacity;
    }

    int get(int key){
        if(m.find(key)==m.end()){
            return -1;
        }
        l.splice(l.begin(),l,m[key]);
        return m[key]->second;
    }

    void put(int key, int value){
        if(m.find(key)!=m.end()){
            l.splice(l.begin(),l,m[key]);
            m[key]->second=value;
            return;
        }

        if(l.size()==size){
            auto d_key=l.back().first;
            l.pop_back();
            m.erase(d_key);
        }

        l.push_front({key,value});
        m[key]=l.begin();
    }
};




