/*
  Three little pigs want to build houses along the river.
  There are many apple trees along the river. Each tree
  has its own quality level which affects the overall
  quality of the garden. A positive value means that the
  tree is bad.
  The little pigs want to divide the territory in such a
  way that each of them gets gardens of the same quality.
  They need your help to determine how many ways they
  can divide the territory.
*/

#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>

int nShare(std::vector<int> qualities) {
    int tot = std::accumulate(qualities.begin(), qualities.end(), 0);
	if (tot % 3 != 0)
		return 0;
	int t = tot / 3;
	int count = 0;
	int preSum = 0;
	std::unordered_map<int,int> preSumMap;
	for (int i = 0; i < (qualities.size() - 1); ++i) {
		preSum += qualities[i];
		if (preSum == 2 * t) {
			if (preSumMap.count(t) > 0)
				count += preSumMap[t];
		}
		preSumMap[preSum] = preSumMap.count(preSum) + 1;
	}
	return count;
}

int main() {
    std::vector<int> tree_qualities = {-2, 4, 2, 1, 1}; // Example list of tree qualities

	std::cout << "Number of ways to share: " << nShare(tree_qualities) << "\n";
    return 0;
}
