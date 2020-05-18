#include <iostream>
#include <vector>
using namespace std;

int main() {
    int val1, val2, val3;
    int lowest = 0;

    vector<int> nums;
    cout << "Enter three ints: " << endl;
    cin >> val1 >> val2 >> val3;

    nums.push_back(val1);
    nums.push_back(val2);
    nums.push_back(val3);

    // sort vector in ascending order
    for(int i = 0; i < nums.size(); i++) {
        for(int j = i + 1; j < nums.size(); j++) {
            if (nums[i] > nums[j]) {
                lowest = nums[i];
                nums[i] = nums[j];
                nums[j] = lowest;
            }
        }
    }

    cout << "Numbers in ascending order" << endl;
    for (int k = 0; k < nums.size(); k++){
        cout << nums[k] << " ";
    }
    cout << endl;
}
