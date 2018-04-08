#include <iostream>
#include <vector>

using namespace std;

int kadane(const std::vector<int> arr) {
	int sum_till_yet = 0, max_sum = 0;

	for(const int& i : arr) {
		sum_till_yet += i;

		if(sum_till_yet < 0)
			sum_till_yet = 0;
		if(max_sum < sum_till_yet)
			max_sum = sum_till_yet;
	}

	return max_sum;
}

int main() {
	std::vector<int> v{-2, -3, 4, -1, -2, 1, 5, -3};

	int result = kadane(v);

	cout<<result<<endl;
	return 0;
}
