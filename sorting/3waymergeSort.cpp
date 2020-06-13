// C++ Program to perform 3 way Merge Sort 
#include <bits/stdc++.h> 
using namespace std; 

/* Merge the sorted ranges [low, mid1), [mid1,mid2) 
and [mid2, high) mid1 is first midpoint 
index in overall range to merge mid2 is second 
midpoint index in overall range to merge*/
void merge(int ori[], int low, int mid1, 
		int mid2, int high, int destArray[]) 
{ 
	int i = low, j = mid1, k = mid2, l = low; 

	// choose smaller of the smallest in the three ranges 
	while ((i < mid1) && (j < mid2) && (k < high)) 
	{ 
		if(ori[i] < ori[j]) 
		{ 
			if(ori[i] < ori[k]) 
			{ 
				destArray[l++] = ori[i++]; 
			} 
			else
			{ 
				destArray[l++] = ori[k++]; 
			} 
		} 
		else
		{ 
			if(ori[j] < ori[k]) 
			{ 
				destArray[l++] = ori[j++]; 
			} 
			else
			{ 
				destArray[l++] = ori[k++]; 
			} 
		} 
	} 

	// case where first and second ranges 
	// have remaining values 
	while ((i < mid1) && (j < mid2)) 
	{ 
		if(ori[i] < ori[j]) 
		{ 
			destArray[l++] = ori[i++]; 
		} 
		else
		{ 
			destArray[l++] = ori[j++]; 
		} 
	} 

	// case where second and third ranges 
	// have remaining values 
	while ((j < mid2) && (k < high)) 
	{ 
		if(ori[j] < ori[k]) 
		{ 
			destArray[l++] = ori[j++]; 
		} 
		else
		{ 
			destArray[l++] = ori[k++]; 
		} 
	} 

	// case where first and third ranges have 
	// remaining values 
	while ((i < mid1) && (k < high)) 
	{ 
		if(ori[i] < ori[k]) 
		{ 
			destArray[l++] = ori[i++]; 
		} 
		else
		{ 
			destArray[l++] = ori[k++]; 
		} 
	} 

	// copy remaining values from the first range 
	while (i < mid1) 
		destArray[l++] = ori[i++]; 

	// copy remaining values from the second range 
	while (j < mid2) 
		destArray[l++] = ori[j++]; 

	// copy remaining values from the third range 
	while (k < high) 
		destArray[l++] = ori[k++]; 
} 


/* Performing the merge sort algorithm on the 
given array of values in the rangeof indices 
[low, high). low is minimum index, high is 
maximum index (exclusive) */
void mergeSort3WayRec(int dup[], int low, 
					int high, int ori[]) 
{ 
	// If array size is 1 then do nothing 
	if (high - low < 2) 
		return; //minimum 3 elements should be present

	// Splitting array into 3 parts 
	int mid1 = low + ((high - low) / 3); 
	int mid2 = low + 2 * ((high - low) / 3) + 1; 

	// Sorting 3 arrays recursively 
	mergeSort3WayRec(ori, low, mid1, dup); 
	mergeSort3WayRec(ori, mid1, mid2, dup); 
	mergeSort3WayRec(ori, mid2, high, dup); 

	// Merging the sorted arrays 
	merge(ori, low, mid1, mid2, high, dup); 
} 

void mergeSort3Way(int ori[], int n) 
{ 
	// if array size is zero return null 
	if (n == 0) 
		return; 

	// creating duplicate of given array 
	int dup[n]; 

	// copying alements of given array into 
	// duplicate array 
	for (int i = 0; i < n; i++) 
		dup[i] = ori[i]; 

	// sort function 
	mergeSort3WayRec(dup, 0, n, ori); 

	// copy back elements of duplicate array 
	// to given array 
	for (int i = 0; i < n; i++) 
		ori[i] = dup[i]; 
} 

// Driver Code 
int main() 
{ 
	int a[] = {45, -2, -45, 78, 30, 
				-42, 10, 19, 73, 93}; 
	mergeSort3Way(a,10); 
	cout << "After 3 way merge sort: "; 
	for (int i = 0; i < 10; i++) 
	{ 
		cout << a[i] << " "; 
	} 
	return 0; 
} 

// This code is contributed by Rashmi Kumari 

