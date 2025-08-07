void build(int index, int low, int high, vector<int> &seg, vector<int> & nums){
    if(low ==high){
        seg[index] = nums[low];
        return ;
    }
    else{
        int mid = (low + high) / 2;
        build(2*index + 1, low, mid, seg, nums);
        build(2*index + 2, mid + 1, high, seg, nums);
        seg[index] = seg[2*index+1] + seg[2*index + 2];
        return ;
    }
}



void updageseg(int index, int low, int high, vector<int> &seg, int i, int val){
    if(low == high){
        seg[index] = val;
        return;
    }
    else{
        int mid = (low + high) / 2;
        if(i<=mid){
            updageseg(2*index + 1, low, mid, seg, i,val);
        }
        else {
            updageseg(2*index + 2, mid + 1, high, seg, i, val);
        }
        seg[index] = seg[2*index+1] + seg[2*index + 2];
        return ;
    }
}



int sumRangeFunct(int index, int low, int high, vector<int> & seg, int l, int r){
    if(high<l || r<low){
        return 0;
    }
    else if(l<=low && r>=high){
        return seg[index];
    }
    else{
        int mid = (low + high) / 2;
        int left = sumRangeFunct(2*index + 1, low, mid, seg, l, r);
        int right = sumRangeFunct(2*index + 2, mid + 1, high, seg, l, r);
        return left + right;
    }
}
class NumArray {
public:
    vector<int> nums;
    vector<int> seg;
    int size;
    NumArray(vector<int>& nums) {
        int size = nums.size();
        this->size = size;
        for(int i=0;i<size;i++){
            this->nums.push_back(nums[i]);
        }
        this->seg = vector<int> (4*size+1, 0);
        build(0, 0, size-1, seg, nums);
    }
    
    void update(int index, int val) {
        updageseg(0, 0 ,this->size-1, this->seg, index, val);
        nums[index] = val;
    }
    
    int sumRange(int left, int right) {
        return sumRangeFunct(0, 0 ,this->size-1, this->seg, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */