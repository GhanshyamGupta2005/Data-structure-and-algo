class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        
        unordered_map<int, int> freqMap;
    
    // Step 1: Count the frequency of each element
    for(int num : nums) {
        freqMap[num]++;
    }
    
    int maxFreq = 0;
    
    // Step 2: Find the maximum frequency
    for(auto& pair : freqMap) {
        maxFreq = max(maxFreq, pair.second);
    }
    
    int maxFreqCount = 0;
    
    // Step 3: Count the number of elements with maximum frequency
    for(auto& pair : freqMap) {
        if(pair.second == maxFreq) {
            maxFreqCount++;
        }
    }
    
    // Step 4: Return the count
    return maxFreq * maxFreqCount;
    }
};
