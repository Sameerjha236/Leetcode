class DataStream {
public:
    int req, curr, val;
    DataStream(int value, int k) {
        val = value;
        curr = 0;
        req = k;
    }
    
    bool consec(int num) {
        if(num == val)
            curr++;
        else curr = 0;
        return curr >= req;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */