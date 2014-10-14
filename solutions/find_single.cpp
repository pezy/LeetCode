//!
//! @author Yue Wang
//! @date   15 Oct 2014
//!

//!
//! Given an array of integers, every element appears twice except for one.
//! Find that single one.
//!
//! Note:
//!     Your algorithm should have a linear runtime complexity. Could you implement
//!     it without using extra memory?
//!

#include <iostream>
#include <algorithm>

/**
 * @brief find_single
 * @param first
 * @param last
 * @time complx     O(n)
 * @extra space     O(1)
 *
 * use xor to iterate through the range.
 */
template<typename Iter>
Iter find_single(Iter first, Iter last)
{
    auto unique = *first;
    for(auto curr = first + 1; curr != last; ++curr)
        unique  ^=  *curr;

    return std::find(first, last, unique);
}



int main()
{
    std::vector<int> v {1,2,3,5,2,1,3};
    std::cout << *find_single(v.cbegin(),v.cend());

    return 0;
}

//! @output :
//! 5
