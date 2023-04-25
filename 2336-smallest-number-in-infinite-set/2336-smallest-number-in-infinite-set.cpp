class SmallestInfiniteSet {
public:
    priority_queue <int, vector<int>, greater<int> > pq;
    unordered_map<int,bool> hash;
    SmallestInfiniteSet() {    
        for(int i=1;i<=1000;i++){
            pq.push(i);
            hash[i]=1;
        } 
    }
    
    int popSmallest() {
        int k = pq.top();
        hash[k]=0;
        pq.pop();

        return k;
    }
    
    void addBack(int num) {

        if(hash[num] == 0) {
            hash[num]=1;
            pq.push(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */