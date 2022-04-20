// Design and implement a data structure for LRU (Least Recently Used) cache. It should support the following operations: get and set.
// get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
// set(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least recently used item before inserting the new item.
// The LRU Cache will be initialized with an integer corresponding to its capacity. Capacity indicates the maximum number of unique keys it can hold at a time.
// Definition of “least recently used” : An access to an item is defined as a get or a set operation of the item. “Least recently used” item is the one with the oldest access time.
// NOTE: If you are using any global variables, make sure to clear them in the constructor.

// Example :
// Input : 
//          capacity = 2
//          set(1, 10)
//          set(5, 12)
//          get(5)        returns 12
//          get(1)        returns 10
//          get(10)       returns -1
//          set(6, 14)    this pushes out key = 5 as LRU is full. 
//          get(5)        returns -1 

//Hint :-
Lets approach this question bit by bit.
If lets say you never had to remove entries from the LRU cache because we had enough space, what would you use to support and get and set ?
A simple map / hashmap would suffice.
Alright, lets now look at the second part which is where the eviction comes in. We need a data structure which at any given instance can give me the least recently used objects in order. Lets see if we can maintain a linked list to do it. We try to keep the list ordered by the order in which they are used. So whenever, a get operation happens, we would need to move that object from a certain position in the list to the front of the list. Which means a delete followed by insert at the beginning.
Insert at the beginning of the list is trivial. How do we achieve erase of the object from a random position in least time possible ?
How about we maintain another map which stores the pointer to the corresponding linked list node.
Ok, now when we know the node, we would need to know its previous and next node in the list to enable the deletion of the node from the list. We can get the next in the list from next pointer ? What about the previous node ? To encounter that, we make the list doubly linked list.
Now, can you think of an approach using doubly linked list and the map(s) ?

//Solution Approach :- 
As discussed in the previous hint, we solve this problem using :
originalMap : A hashmap which stores the orginial key to value mapping
accessList : A doubly linked list which has keys ordered by their access time ( Most recently used key in front of the list to least recently used key at the end of the list ).
addressMap : A hashmap which saves the mapping of key to address of the key in accessList.
Lets see now how the get and set operation would work :
get(key) :
Look for the value corresponding to key in originalMap.
If key is not found, we don’t need to change accessList. So, return -1.
If key is found, then we need to move the node corresponding to the key to front of the list in accessList.
To do that, we find the address of the node for key from addressMap. We make the node->prev->next = node->next;, node->next->prev = node->prev;, node->prev = NULL; node->next = head; head->prev = node;
We update the head of the accessList to be node now.
set(key, value)
If the key is a new entry (it does not exist in the originalMap) AND the cache is full(size = capacity), then we would need to remove the least recently used key lkey.
We know that this key is the key corresponding to the last node in accessList which is accessible in O(1). To evict, we delete the last node from accessList, and the entry corresponding to lkey(from last node) in addressMap and originalMap.

Post this, there are 2 cases.
key is a new entry and is not present in originalMap. In this case, a new node is created for key and inserted at the head of accessList. A new (key,value) entry is created into originalMap and addressMap accordingly.
key is present in the map, in which case the value needs to be updated. We update the value in the originalMap and then we update the accessList for key exactly the way we did in the case of get operation.
A couple of insights for clean code :

Note that the update of accessList for key when key is present is a common operation in get and a subcase of set function. We should create a function for it and call that function in both cases to reduce redundancy.
Also, note that originalMap and addressMap are always of the same size with the same keys ( One with value and the other with address in linkedlist ). If you want to manage less maps, you can just have a masterMap which maps key to a pair of (value, address_in_list)


//First Solution :-  Perfect on LeetCode but Runtime error on Interviewbit
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
    unordered_map<int, node*>m;
    
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

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

//Second Solution :-
// We need to add and remove an element in O(1) 
// thus we need to use linked list over an array because 
// to shift the element after deletion, we need O(n) time
// with the linked list we can assign two pointers at head and tail
// and just adjust head and tail accordingly

// for checking whether the element is in the cache already or not
// we use hashtable, (unordered_map), where we store the address and the value
// this lookup becomes O(1) as well; (instead of traversal in O(n))

#include<bits/stdc++.h>
int _capacity;
list<int> _keys;
unordered_map<int, pair<int, list<int>::iterator>> _map;

// front denotes the recent and back denotes the least recent in this code

LRUCache::LRUCache(int capacity) 
{
    _map.clear(); // need to clear the global variables
    _keys.clear(); // ________ ,, _____________________
    _capacity = capacity;
}

int LRUCache::get(int key) 
{
    if(_map.find(key) != _map.end()) // if element exists in the  map
    {
         _keys.erase(_map[key].second); // remove the element
        _keys.push_front(key); // put it in front of it 
        _map[key].second = _keys.begin(); // set the new node postion of that element in the map
        return _map[key].first; // return the value;
    }
    else
        return -1;
}

void LRUCache::set(int key, int value) 
{
    if(_map.find(key) != _map.end())
        {
            _keys.erase(_map[key].second); // remove it
            _keys.push_front(key); // put it in the beginning
            _map[key] = {value, _keys.begin()}; // update the map for value and position
        }
    else
    {
        // check the capacity
        if(_keys.size() >= _capacity) // if exceeded
        {
            _map.erase(_keys.back()); // remove the least recent element from the map
            _keys.pop_back();              // and from the list
        }
        // insert in the beginning regardless (if capacity is full we remove and then add otherwise just add)
        _keys.push_front(key);               // insert the new key in the beginning of the list and update it
        _map[key] = {value, _keys.begin()};  // in the  map as well
    }

}


//Third Solution :- 
#include<list>
unordered_map<int, list<int>::iterator> um_dll;
unordered_map<int, int> key_val;
int cap;
int curr;
list<int> dll;

void delete_key(int key)
{
    if(key_val.find(key) == key_val.end())
        return;
    dll.erase(um_dll[key]);
    --curr;
    key_val.erase(key);
}

void insert_key_val(int key, int value)
{
    key_val[key] = value;
    dll.push_front(key);
    um_dll[key] = dll.begin();
    ++curr;
}

LRUCache::LRUCache(int capacity) 
{
    um_dll.clear();
    key_val.clear();
    dll.clear();
    cap = capacity;
    curr = 0;
}

int LRUCache::get(int key) 
{
    if(key_val.find(key) == key_val.end())
    {
        return -1;
    }
    else
    {
        int val = key_val[key];
        delete_key(key);
        insert_key_val(key, val);
        return val;
    }
}

void LRUCache::set(int key, int value) 
{
    if(key_val.find(key) != key_val.end())
    {
        delete_key(key);
        insert_key_val(key, value);
    }
    else
    {
        if(curr == cap)
        {
            int least_used = dll.back();
            delete_key(least_used);
            insert_key_val(key, value);
        }
        else
        {
            insert_key_val(key, value);
        }
    }
}

