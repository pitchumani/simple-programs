/*
 * Complete the 'pairs' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY arr
 */

int pairs(int k, vector<int> arr) {
    int nPairs = 0;
    for (int i = 0; i < arr.size(); ++i) {
        for (auto j = 1; j < arr.size(); ++j) {
            if ((arr[j] - arr[i]) == k)
                ++nPairs;
        }
    }
    return nPairs;
}

