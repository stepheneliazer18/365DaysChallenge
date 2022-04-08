class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int K;
    KthLargest(int k, vector<int>& nums) {
        
        int len = nums.size();
        K = k;
        
        for(int i=0; i<len; i++){
            if(pq.size() < k){
                pq.push(nums[i]);
            } 
            else {
                if(nums[i] > pq.top()){
                    pq.pop();
                    pq.push(nums[i]);    
                }
            }        
        }
    }
    
    int add(int val) {
        if(pq.size() < K) {
            pq.push(val);
        } else {
            if(val > pq.top()){
                pq.pop();
                pq.push(val);    
            }
        }
        
        return pq.top();
    }
};
