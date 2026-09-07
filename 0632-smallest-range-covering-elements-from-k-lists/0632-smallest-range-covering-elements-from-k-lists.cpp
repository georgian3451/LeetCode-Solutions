class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k=nums.size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> minHeap;
        int highest=INT_MIN;
        for (int i=0;i<k;i++) {
            minHeap.push({nums[i][0], i, 0});
            highest = max(highest,nums[i][0]);
        }

        int rangeStart=0,rangeEnd=INT_MAX;
        while (true){
            vector<int> smallest = minHeap.top();
            minHeap.pop();

            int lowest = smallest[0];
            int listIdx = smallest[1];
            int pos = smallest[2];

          
            int currentLen = highest-lowest;
            int bestLen = rangeEnd-rangeStart;
            if (currentLen < bestLen || (currentLen==bestLen && lowest<rangeStart)) {
                rangeStart = lowest;
                rangeEnd = highest;
            }           
            if (pos+1>= (int)nums[listIdx].size()) {
                break;
            }

            int nextVal = nums[listIdx][pos+1];
            minHeap.push({nextVal,listIdx,pos+1});
            highest = max(highest,nextVal);
        }
        return {rangeStart,rangeEnd};
    }
};