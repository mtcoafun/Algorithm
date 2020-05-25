#include <vector>
#include <math.h>
#include <iostream>
using namespace std;
int myints[] = {21,432,454,1,235,546,122,5,123,23,6,2,676,43,12,89,45,34,65,23,567,22,58};
vector<int> arr (myints, myints + sizeof(myints) / sizeof(int));

vector<int> selectSort(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        int min = i;
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[j] < nums[min]) min = j; 
        }
        int temp = nums[min];
        nums[min] = nums[i];
        nums[i] = temp;
    }
    return nums;
}

int main() {
    cout << endl;
    for (auto& e : selectSort(arr)) {
        cout << " " << e;
    }
    cout << endl;
}