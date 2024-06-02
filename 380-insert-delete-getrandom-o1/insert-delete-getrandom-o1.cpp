class RandomizedSet {
         unordered_set<int> v;
         unordered_map<int,int>freq;
public:
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(freq[val]==0){

        v.insert(val);
        freq[val]++;
        return true;
        }
        else return false;
    }
    
    bool remove(int val) {
        if(freq[val]!=0){
        v.erase(val);
            freq[val]--;
            return true;
        }
        else return false;
    }
    
    int getRandom() {
        int sizer = rand()%v.size(); 
        auto x =next(v.begin(),sizer);
        return *x;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */