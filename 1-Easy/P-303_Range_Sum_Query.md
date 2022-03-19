## [Range Sum Query](https://leetcode.com/problems/range-sum-query-immutable/)

Given an integer array nums, handle multiple queries of the following type:

Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
Implement the NumArray class:

- NumArray(int[] nums) Initializes the object with the integer array nums.
- int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).

*Example-1:*

*Input* <br/>
["NumArray", "sumRange", "sumRange", "sumRange"]
[[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]

*Output* <br/>
[null, 1, -1, -3]

*Explanation* <br/>
NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]); <br/>
numArray.sumRange(0, 2); // return (-2) + 0 + 3 = 1 <br/>
numArray.sumRange(2, 5); // return 3 + (-5) + 2 + (-1) = -1 <br/>
numArray.sumRange(0, 5); // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3 <br/>

### Solution
```
class NumArray {

    private int[] preNums;

    public NumArray(int[] nums) {
      this.preNums = new int[nums.length + 1];
      for (int i = 1; i < preNums.length; i++) {
          preNums[i] = nums[i - 1] + preNums[i - 1];
      }
    }

    public int sumRange(int left, int right) {
        return preNums[right + 1] - preNums[left];
    }
}
```