```C++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	vector<int> nums = {1, 3 , 2};
	nums.clear();
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(9);
	nums.insert(nums.begin() + 1, 80);
	vector<int> nums_i = { 0 , 4 , 5 };
	nums.insert(nums.end(), nums_i.begin(), nums_i.end());
	nums.erase(nums.begin() + 2);
	cout << "NUM:" << nums.size() << endl;
	for (auto it = nums.begin(); it != nums.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	sort(nums.begin(), nums.end());
	for (auto it = nums.begin(); it != nums.end(); ++it) {
		cout << *it << " ";
	}
}
```