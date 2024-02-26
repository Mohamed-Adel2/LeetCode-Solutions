#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int sz1 = nums1.size(), sz2 = nums2.size();
        if (!sz1)
            return (sz2 & 1 ? (double) nums2[sz2 / 2] : (double) (nums2[sz2 / 2] + nums2[sz2 / 2 - 1]) / 2);
        if (!sz2)
            return (sz1 & 1 ? (double) nums1[sz1 / 2] : (double) (nums1[sz1 / 2] + nums1[sz1 / 2 - 1]) / 2);
        int sz = sz1 + sz2, target = (sz + 1) / 2;
        int lo = max(0, target - sz2 - 1), hi = min(target, sz1) - 1;
        int left = -1, right = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if ((!valid(sz2, target - (mid + 1)) || nums1[mid] <= nums2[target - (mid + 1)]) &&
                ((!valid(sz2, target - (mid + 1) - 1)) || !valid(sz1, mid + 1) ||
                 (nums2[target - (mid + 1) - 1] <= nums1[mid + 1]))) {
                left = mid + 1, right = target - (mid + 1);
                break;
            } else if (!(!valid(sz2, target - (mid + 1)) || nums1[mid] <= nums2[target - (mid + 1)])) {
                hi = mid - 1;
            } else
                lo = mid + 1;
        }
        if (left == -1 && right == -1)
            left = 0, right = target;
        int a1 = (left - 1 >= 0 ? nums1[left - 1] : -10000000), a2 = (right - 1 >= 0 ? nums2[right - 1] : -10000000);
        int b1 = (left < sz1 ? nums1[left] : 10000000), b2 = (right < sz2 ? nums2[right] : 10000000);
        if (sz & 1)
            return max(a1, a2);
        else
            return (double) (max(a1, a2) + min(b1, b2)) / 2;
    }

    bool valid(int sz, int idx) {
        return (idx >= 0 && idx < sz);
    }
};