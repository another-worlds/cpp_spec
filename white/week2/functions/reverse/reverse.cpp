#include <iostream>
#include <vector>
using namespace std;

void Reverse(vector<int>& v) {
    int size = v.size();
    for(int i = 0; i < size / 2; i++) {
        int first = v[i];
        v[i] = v[v.size() - i - 1];
        v[v.size() - i - 1] = first;
    }
}

int main() {
    vector<int> nums = {1, 5, 3, 4, 2};
    Reverse(nums);

    for(int num : nums) {
        cout << num;
    }

    return 0;
}