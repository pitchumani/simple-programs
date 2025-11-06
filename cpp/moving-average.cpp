/*
  Implement a moving average function. Define the function,
  that takes a list of numbers and an interval argument K
  that defines the number of points to use for the average,
  as inputs, and returns the smoothed array.
  Print elements of smoothed array separated by spaces. If
  the input cannot be smoothed, print -1

  e.g. #1
  Input:
  7
  1 1 1 1 2 1 1
  3
  Output:
  1.00 1.00 1.33 1.33 1.33
  
  e.g. #2
  Input:
  9
  2 3 4 5 1 2 5 1 3
  5
  Output:
  3.00 3.00 3.00 2.40 2.00
*/
/*
  python
  def smoothData(arr, k):
      if k > len(arr):
	      return -1

	  m = []
	  for i in range (len(arr) - k + 1):
	      t = arr[i:i+k]
		  m.append(sum(t) / k)

	  return ' '.join([f"{i:.2f}" for i in m])
*/
#include <vector>
#include <iostream>

void smoothedArray(std::vector<int> numbers, int interval) {
	if (numbers.size() < interval) {
		std::cout << "-1";
		return;
	}
	std::vector<float> mavgs;
	for (int i = 0; i < (numbers.size() - interval + 1); ++i) {
		int sum = 0;
		for (int j = i; j < (i + interval); ++j) {
			sum += numbers[j];
		}
		mavgs.emplace_back((float)sum / interval);
	}
	for (auto &a : mavgs) {
		std::cout << a << " ";
	}
	std::cout << "\n";
}

int main() {
	std::vector<int> v1 = {1,1,1,1,2,1,1};
	smoothedArray(v1, 3);
	std::vector<int> v2 = {2,3,4,5,1,2,5,1,3};
	smoothedArray(v2, 5);
	return 0;
}
