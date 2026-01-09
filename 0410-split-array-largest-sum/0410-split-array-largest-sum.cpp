class Solution {
public:
    bool solve(vector<int>& arr, int k, int mid) {
        int n = arr.size();
        int pages = 0;
        int c = 1;
        for (int i = 0; i < n; i++) {
            if ((pages + arr[i]) > mid) {
                pages = arr[i];
                c++;
            } else {
                pages += arr[i];
            }
            if (c > k)
                return false;
        }

        return true;
    }
int splitArray(vector<int>& arr, int k) {

    int n = arr.size();
    int ans;
    if (k > n)
        return -1;
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while (low <= high) {
        int mid = (low + high) / 2;
        if (solve(arr, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;


}
};