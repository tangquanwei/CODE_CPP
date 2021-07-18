#include <iostream>

using namespace std;




void swap(int* a, int* b) //交換兩個變數
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void swap(int& a, int& b) {
	a = a + b;
	b = a - b;
	a = a - b;
}

void selection_sort(int arr[], int len) {
	int i, j;
	for (i = 0; i < len - 1; i++) {
		int min = i;
		for (j = i + 1; j < len; j++)
			if (arr[j] < arr[min])
				min = j;
		swap(&arr[min], &arr[i]);
		// arr[min] ^= arr[i] ^= arr[min] ^= arr[i];
		// swap(arr[min], arr[i]);
	}
}


void bouble_sort(int* a, int n) {
	int i, j;
	for (i = 0; i < n - 1; ++i)
		for (j = i + 1; j < n; ++j)
			if (a[i] > a[j])
				a[i] ^= a[j] ^= a[i] ^= a[j];
}


int Paritition1(int A[], int low, int high) {
	int pivot = A[low];
	while (low < high) {
		while (low < high && A[high] >= pivot) {
			--high;
		}
		A[low] = A[high];
		while (low < high && A[low] <= pivot) {
			++low;
		}
		A[high] = A[low];
	}
	A[low] = pivot;
	return low;
}

void QuickSort(int A[], int low, int high) //快排母函数
{
	if (low < high) {
		int pivot = Paritition1(A, low, high);
		QuickSort(A, low, pivot - 1);
		QuickSort(A, pivot + 1, high);
	}
}

#include <vector>
class MergeSort {
public:
	MergeSort(vector<int> vi) {
		int low = 0;
		int high = vi.size() - 1;
		sort(vi, low, high);
	}
	void operator()(vector<int> vi) {
		// 1. initialize assist;
		// 2. define low,high to record the index
		// 3. 用sort排序
		int low = 0;
		int high = vi.size() - 1;
		sort(vi, low, high);
	}

private:
	vector<int> assist; // 辅助数组

	// using viter = vector<int>::iterator;
	void sort(vector<int> vi, int low, int high) {
		if (low > high)
			return;
		// group data between low and hight
		// sort every group
		int mid = low + (high - low) / 2;
		sort(vi, low, mid);
		sort(vi, mid, high);
		merge(vi, low, mid, high);
	}
	void swap(vector<int> vi, int i, int j) {
		int temp = vi[i];
		vi[i] = vi[j];
		vi[j] = temp;
	}
	bool less(int i, int j) {
		return i < j;
	}
	void merge(vector<int> vi, int low, int mid, int high) {
		//define 3 pointer
		int i = low;
		int p1 = low;
		int p2 = mid + 1;
		//compare the value of pointer
		while (p1 <= mid && p2 <= high) {
			if (less(vi[p1], vi[p2]))
				assist[i++] = vi[p1++];
			else
				assist[i++] = vi[p2++];
		}
		//traverse
		// if p1 finish first, copy p2_value to assist
		while (p1 <= mid)
			assist[i++] = vi[p1++];
		// if p2 finish first, copy p1_value to assist
		while (p2 <= mid)
			assist[i++] = vi[p2++];
		// copy assist to vi
		for (int i = low; i <= high; ++i)
			vi[i] = assist[i];
	}
};
#include <limits>
void Merge(vector<int>& Array, int front, int mid, int end) {
	// preconditions:
	// Array[front...mid] is sorted
	// Array[mid+1 ... end] is sorted
	// Copy Array[front ... mid] to LeftSubArray
	// Copy Array[mid+1 ... end] to RightSubArray
	vector<int> LeftSubArray(Array.begin() + front, Array.begin() + mid + 1);
	vector<int> RightSubArray(Array.begin() + mid + 1, Array.begin() + end + 1);
	int idxLeft = 0, idxRight = 0;
	LeftSubArray.insert(LeftSubArray.end(), numeric_limits<int>::max());
	RightSubArray.insert(RightSubArray.end(), numeric_limits<int>::max());
	// Pick min of LeftSubArray[idxLeft] and RightSubArray[idxRight], and put into Array[i]
	for (int i = front; i <= end; i++) {
		if (LeftSubArray[idxLeft] < RightSubArray[idxRight]) {
			Array[i] = LeftSubArray[idxLeft];
			idxLeft++;
		}
		else {
			Array[i] = RightSubArray[idxRight];
			idxRight++;
		}
	}
}

void MergeSort(vector<int>& Array, int front, int end) {
	if (front >= end)
		return;
	int mid = (front + end) / 2;
	MergeSort(Array, front, mid);
	MergeSort(Array, mid + 1, end);
	Merge(Array, front, mid, end);
}

int main() {
	// int len = 12;
	// int a[]{ 1, 2, 3, 5, 1, 2, 2, 6, 9, 7, 1, 0 };
	// int* p=choose_sort(a,len);
	// for(int i = 0;i<len;++i,++p)
	// cout<<*p<<"  ";
	// selection_sort(a, len);
	// QuickSort(a, 0, 12);
	// for (int i = 0, *p = a; i < len; ++i, ++p)
	// 	cout << *p << "  ";

	vector<int> vi{ 11, 3, 2, 1, 4, 5, 6, 9, 8, 7, 0 };
	// for (auto&& i : vi)
	// 	cout << i << ' ';
	// MergeSort s(vi);
	// for (auto&& i : vi)
	// 	cout << i << ' ';
	MergeSort(vi, 0, vi.size() - 1);
	for (auto&& i : vi)
		cout << i << ' ';




	return 0;
}