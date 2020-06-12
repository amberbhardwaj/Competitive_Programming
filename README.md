# Competitive_Programming
This repo contains algorithms implementation

Hi,
I am Amber Bhardwaj. I think my background is not important here. I am learning DS & Algorithms so whatever i solve, i upload here only. 


# BackTracking Algorithm

*Power set is all possible combinations of all possible lengths, from 0 to n.*

Given the definition, the problem can also be interpreted as finding the power set from a sequence.

So, this time let us loop over the length of combination, rather than the candidate numbers, and generate all combinations for a given length with the help of backtracking technique.

![alt text](https://github.com/amberbhardwaj/Competitive_Programming/blob/master/combinations.png?raw=true)


Backtracking is an algorithm for finding all solutions by exploring all potential candidates. If the solution candidate turns to be not a solution (or at least not the last one), backtracking algorithm discards it by making some changes on the previous step, i.e. backtracks and then try again.

![alt text](https://github.com/amberbhardwaj/Competitive_Programming/blob/master/backtracking.png?raw=true)

Algorithm

We define a backtrack function named backtrack(first, curr) which takes the index of first element to add and a current combination as arguments.

If the current combination is done, we add the combination to the final output.


class Solution {
  List<List<Integer>> output = new ArrayList();
  int n, k;

  public void backtrack(int first, ArrayList<Integer> curr, int[] nums) {
    // if the combination is done
    if (curr.size() == k)
      output.add(new ArrayList(curr));

    for (int i = first; i < n; ++i) {
      // add i into the current combination
      curr.add(nums[i]);
      // use next integers to complete the combination
      backtrack(i + 1, curr, nums);
      // backtrack
      curr.remove(curr.size() - 1);
    }
  }

  public List<List<Integer>> subsets(int[] nums) {
    n = nums.length;
    for (k = 0; k < n + 1; ++k) {
      backtrack(0, new ArrayList<Integer>(), nums);
    }
    return output;
  }
}
  
  
Complexity Analysis

Time complexity: N*2powN to generate all subsets and then copy them into output list.

Space complexity: N*2powN to keep all the subsets of length N, since each of N elements could be present or absent.


Otherwise, we iterate over the indexes i from first to the length of the entire sequence n.

Add integer nums[i] into the current combination curr.

Proceed to add more integers into the combination : backtrack(i + 1, curr).

Backtrack by removing nums[i] from curr.

