/*
 * Complete the 'pairs' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY arr
 */

int pairs(int k, vector<int> arr) {
    unordered_set<int> nums(arr.begin(), arr.end());
    int npairs = 0;
    for (auto num : nums) {
        int nvals = nums.count(num + k);
        npairs += nvals;
    }
    return npairs;
}

