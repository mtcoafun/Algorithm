#include <vector>
#include <math.h>
#include <algorithm>
#include <iostream>
using namespace std;
int myints[] = {21,432,454,1,235,546,122,5,123,23,6,2,676,43,12,89,45,34,65,23,567,22,58};
vector<int> arr (myints, myints + sizeof(myints) / sizeof(int));
int stimes = 0;

void insertSort() {
    for (int i = 1; i < arr.size(); i++) {
        int cur = i;
        while (arr[cur] < arr[cur - 1]) {
            stimes++;
            int temp = arr[cur];
            arr[cur] = arr[cur - 1];
            arr[cur - 1] = temp;
            cur--;
        }
    }
}

int main() {
    insertSort();
    cout << endl;
    for (auto& e : arr) {
        cout << " " << e;
    }
    cout << endl;
    cout << stimes << endl;
}