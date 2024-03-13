// class Solution {
// public:
//     int pivotInteger(int n) {
//         long long totalSum = (long long)n * (n + 1) / 2;

//         long long leftSum = 0;
//         for (int i = 1; i <= n; i++) {
//             leftSum += i;
//             long long rightSum = totalSum - leftSum + i; // Include the current integer in the right sum

//             if (rightSum == leftSum)
//                 return i;
//         }
//         return -1;
//     }
// };

// binary search
class Solution {
public:
    int pivotInteger(int n) {
        int totalSum = n * (n + 1) / 2; // Sum of integers from 1 to n
        
        int left = 1, right = n;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int leftSum = (mid * (mid + 1)) / 2;
            int rightSum = totalSum - leftSum+mid;
            
            if (leftSum == rightSum) {
                return mid;
            } else if (leftSum < rightSum) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return -1; // No such integer exists
    }
};
