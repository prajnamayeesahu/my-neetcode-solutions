class MyHashMap {
    private:
    vector<int> array;

public:
        MyHashMap() : array(1000001, -1) {}
    
    void put(int key, int value) {
        array[key]=value;
    }
    
    int get(int key) {
        return array[key];
    }
    
    void remove(int key) {
        array[key]=-1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */