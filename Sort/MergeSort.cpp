#include <vector>
#include <math.h>
#include <algorithm>
#include <iostream>
using namespace std;
int myints[] = {21,432,454,1,235,546,122,5,123,23,6,2,676,43,12,89,45,34,65,23,567,22,58};
vector<int> arr (myints, myints + sizeof(myints) / sizeof(int));

//将r[i…m]和r[m +1 …n]归并到辅助数组rf[i…n]
void Merge(vector<int>& r,vector<int>& rf, int i, int m, int n)
{
	int j,k;
	for(j=m+1,k=i; i<=m && j <=n ; ++k){
		if(r[j] < r[i]) rf[k] = r[j++];
		else rf[k] = r[i++];
	}
	while(i <= m)  rf[k++] = r[i++];
	while(j <= n)  rf[k++] = r[j++];
}
 
void MergeSort(vector<int>& r, vector<int>& rf, int lenght)
{ 
	int len = 1;
	vector<int> q = r;
	vector<int> tmp ;
	while(len < lenght) {
		int s = len;
		len = 2 * s ;
		int i = 0;
		while(i+ len <lenght){
			Merge(q, rf,  i, i+ s-1, i+ len-1 ); //对等长的两个子表合并
			i = i+ len;
		}
		if(i + s < lenght){
			Merge(q, rf,  i, i+ s -1, lenght -1); //对不等长的两个子表合并
		}
		tmp = q; q = rf; rf = tmp; //交换q,rf，以保证下一趟归并时，仍从q 归并到rf
	}
}

int main() {
    vector<int> copy;
    MergeSort(arr, copy, arr.size());
    cout << endl;
    for (auto& e : copy) {
        cout << " " << e;
    }
    cout << endl;
}