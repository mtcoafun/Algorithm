#include <vector>
#include <math.h>
#include <algorithm>
#include <iostream>
using namespace std;
int myints[] = {21,432,454,1,235,546,122,5,123,23,6,2,676,43,12,89,45,34,65,23,567,22,58};
vector<int> arr (myints, myints + sizeof(myints) / sizeof(int));
int stimes = 0;

void shellSort() {
    int len = arr.size();
    for (int gap = len / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < len; i++) {
            int j = i;
            int cur = arr[j];
            while (j - gap >= 0 && cur < arr[j - gap]) {
                stimes++;
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = cur;
        }
    }
}
int main() {
    shellSort();
    cout << endl;
    for (auto& e : arr) {
        cout << " " << e;
    }
    cout << endl;
    cout << stimes << endl;
}

