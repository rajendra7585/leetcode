class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if (start < 0 || start >= arr.size())
            return false;
        if (arr[start] == 0)
            return true;
        if (arr[start] < 0)
            return false;
        int jump = arr[start];
        arr[start] = -arr[start];
        return canReach(arr, start + jump) || canReach(arr, start - jump);
    }
};
