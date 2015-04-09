#include <algorithm>

class Solution {
public:
    int maxSubArray(int A[], int n) {
        int maxv = A[0];
        for (int i=0, benefited = 0; i != n; ++i)
        {
            benefited = std::max(A[i], benefited + A[i]);
            maxv = std::max(maxv, benefited);
        }
        return maxv;
    }
};

class SolutionByDivideAndConquer{
	//O(n)
	int find_max_crossing_subarray(int arr[], unsigned low, unsigned mid, unsigned hgh)
	{
		auto accumulation = 0;

		auto lft_sum = accumulation = arr[mid];
		if (mid > low)
			for (auto i = mid - 1; i != low - 1; --i)
				if ((accumulation += arr[i]) > lft_sum)
					lft_sum = accumulation;

		auto rht_sum = accumulation = arr[mid + 1];
		if (hgh > mid)
			for (auto i = mid + 2; i != hgh + 1; ++i)
				if ((accumulation += arr[i]) > rht_sum)
					rht_sum = accumulation;

		return lft_sum + rht_sum;
	}

	//O(n lg n)
	int divide_and_conquer(int arr[], unsigned low, unsigned hgh)
	{
		if (low == hgh) return arr[low];

		auto mid = (low + hgh) / 2;
		auto lft = divide_and_conquer(arr, low, mid);
		auto rht = divide_and_conquer(arr, mid + 1, hgh);
		auto crs = find_max_crossing_subarray(arr, low, mid, hgh);

		return std::max({ lft, rht, crs });
	}

public:
	int maxSubArray(int A[], int n)
	{
		return divide_and_conquer(A, 0, n - 1);
	}
};
