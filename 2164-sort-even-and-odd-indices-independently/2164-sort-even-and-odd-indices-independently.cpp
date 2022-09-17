class Solution {
public:

    vector<int> sortEvenOdd(vector<int>& nums) {
       
        priority_queue<int> maxheap;
        priority_queue<int,vector<int>,greater<int>> minheap;
        
        for(auto i=0;i<nums.size();i+=2)
            minheap.push(nums[i]);
        
        for(auto i=1;i<nums.size();i+=2)
            maxheap.push(nums[i]);
        
        //nums.clear();
        
        int i=0;
        while(i<nums.size()){
            if(i%2){
                nums[i]=maxheap.top();
                maxheap.pop();
                i++;
            }
            else{
                nums[i]=minheap.top();
                minheap.pop();
                i++;
            }
        }
        return nums;
    }
};