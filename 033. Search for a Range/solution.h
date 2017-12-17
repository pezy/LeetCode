#include <vector>

using std::vector;

class Solution {
    int binarySearch(int A[], int l, int r, int target) {
        for (int mid; l <= r; ) {
            mid = ( l + r ) >> 1;
            if      ( A[mid] < target ) l = mid + 1;
            else if ( A[mid] > target ) r = mid - 1;
            else return mid;
        }
        return -1;
    }
public:
    vector<int> searchRange(int A[], int n, int target) {
        int iPos = binarySearch( A, 0, n-1, target ), l = -1, r = -1;
        if ( iPos != -1 ) {
            l = r = iPos;
            for (int lo = l; (lo = binarySearch(A, 0,   lo-1, target)) != -1; l = lo ) ;
            for (int hi = r; (hi = binarySearch(A, hi+1, n-1, target)) != -1; r = hi ) ;
        }
        return {l ,r};
    }
};
