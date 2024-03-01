class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        return vector<int>{firstPosition(nums, target), lastPosition(nums, target)};
    }

    int lastPosition(vector<int> &v, int target) {
        int l = 0, r = v.size() - 1;
        int ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (v[mid] <= target) {
                if (v[mid] == target)
                    ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }

    int firstPosition(vector<int> &v, int target) {
        int l = 0, r = v.size() - 1;
        int ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (v[mid] < target)
                l = mid + 1;
            else {
                if (v[mid] == target)
                    ans = mid;
                r = mid - 1;
            }
        }
        return ans;
    }

};