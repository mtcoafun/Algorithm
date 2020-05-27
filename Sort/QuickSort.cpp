#include <vector>
#include <iostream>
using namespace std;
int myints[] = {21,432,454,1,235,546,122,5,123,23,6,3,567, 58,74,44,63,456,667,45};
vector<int> arr (myints, myints + sizeof(myints) / sizeof(int));
int htimes = 0, qtimes = 0;
int helper(int begin, int end) {
    htimes++;
    int copy = arr[begin];
    while (begin < end) {
        while (begin < end) {
            if (arr[end] > copy) end--;
            else { arr[begin++] = arr[end]; break; }
        }
        while (begin < end) {
            if (arr[begin] < copy) begin++;
            else { arr[end--] = arr[begin]; break; }
        }
    }
    arr[begin] = copy;
    return begin;
}

void quickSort(int begin, int end) {
    qtimes++;
    if (begin >= end) return;
    int mid = helper(begin, end);
    quickSort(begin, mid);
    quickSort(mid + 1, end);
}

int main() {
    quickSort(0, arr.size() - 1);
    cout << endl;
    for (auto& e : arr) {
        cout << " " << e; 
    }
    cout << endl;
    cout << "helper times: " << htimes << endl;
    cout << "quickSort times: " << qtimes << endl;
    cout << endl;
}