class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
         unordered_set<int> set1(nums1.begin(), nums1.end());
    unordered_set<int> set2(nums2.begin(), nums2.end());
    
    // Initialize an empty vector to store the intersection
    vector<int> intersection_result;
    
    // Iterate through elements in set1
    for (int num : set1) {
        // Check if the element is also in set2
        if (set2.count(num)) {
            // If it is, add it to the intersection_result vector
            intersection_result.push_back(num);
        }
    }
    
    // Return the intersection result as a vector
    return intersection_result;
    }
};
