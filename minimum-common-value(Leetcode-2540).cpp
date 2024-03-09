class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
         int pointer1 = 0;
    int pointer2 = 0;

    while (pointer1 < nums1.size() && pointer2 < nums2.size()) {
        if (nums1[pointer1] == nums2[pointer2]) {
            return nums1[pointer1];
        } else if (nums1[pointer1] < nums2[pointer2]) {
            pointer1++;
        } else {
            pointer2++;
        }
    }

    return -1;
    }
};
