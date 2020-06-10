//Given a set of distinct integers, S, return all possible subsets.
// https://www.educative.io/courses/grokking-the-coding-interview/gx2OqlvEnWG

vector<vector<int> > Solution::subsets(vector<int> &A) {
    vector<vector<int> > subsets;
    //There are 2 simple steps to solve this problem (Set Theory)
    //  Given set: [1, 5, 3

    //1.Start with an empty set: [[]]
    //2. Add the first number (1) to all the existing subsets to create new subsets: [[], [1]];
    //2.i.  Add the second number (5) to all the existing subsets: [[], [1], [5], [1,5]];
    //2.ii. Add the third number (3) to all the existing subsets: [[], [1], [5], [1,5], [3], [1,3], [5,3], [1,5,3]].

    // Step1: push an empty vector
    subsets.push_back(vector<int>());
    // Come to step 2 but for that we need to iterate the vector
    for (const auto &val : A)
    {
        // We need another loop to iterate the existing subsets
        int numOfSubsets = subsets.size();
        for (int i = 0; i < numOfSubsets; i++)
        {
         // Now, come to final step 2 and its subsequent steps
         // Take a temp vector to perform operations on (i)th subset
         vector<int> temp(subsets[i]);
         // Add the value to the ith subset as describe in Step 2/2.i/2.ii
         temp.push_back(val);
         // Add the final result to the subset.
         subsets.push_back(temp);
        }
    }
    return subsets;
}
