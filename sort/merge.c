#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

#define N 20

void merge(int a[], int t[], int lo, int mid, int hi) {
	int i = lo, j = mid + 1;
	for (int k = lo; k <= hi; k++) {
		if (i > mid)          a[k] = t[j++];
		else if (j > hi)      a[k] = t[i++];
		else if (t[i] < t[j]) a[k] = t[i++];
		else                  a[k] = t[j++];
	}
}

void sort(int a[], int t[], int lo, int hi) {
	if (lo >= hi) return;
	// if (hi - lo < 15) insertion_sort(a, lo, hi); return;
	int mid = lo + (hi - lo) / 2;
	sort(t, a, lo, mid);
	sort(t, a, mid + 1, hi);
	if (t[mid] <= t[mid + 1]) {
		memcpy(a + lo, t + lo, sizeof(int) * (hi - lo + 1));
	} else {
		merge(a, t, lo, mid, hi);
	}
}

void merge_sort(int a[], int length) {
	int* t = (int*)malloc(sizeof(int) * length);
	if (t != NULL) {
		memcpy(t, a, sizeof(int) * length);
		sort(a, t, 0, length - 1);
	} else {
		printf("malloc fail\n");
	}
}

int main(int argc, char const *argv[])
{
	int a[N];
	generate_array(a, N);
	print_array(a, N);
	merge_sort(a, N);
	print_array(a, N);
	printf(is_sorted(a, N) ? "Sort Success\n" : "Sort Error\n");
	return 0;
}