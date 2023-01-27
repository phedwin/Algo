package Leetcode;

public class PermutationSequence {


    /**
     *
     * The set [1, 2, 3, ..., n] contains a total of n! unique permutations.
     *
     * By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
     *
     * "123"
     * "132"
     * "213"
     * "231"
     * "312"
     * "321"
     * Given n and k, return the kth permutation sequence.
     *
     *
     * @param n
     * @param k
     * @return
     */


    public String getPermutation(int n, int k) {
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = i + 1;
        }
        boolean[] visited = new boolean[n];
        StringBuilder sb = new StringBuilder();
        backtrack(nums, k, visited, sb);
        return sb.toString();
    }
    private int count = 0;
    private void backtrack(int[] nums, int k, boolean[] visited, StringBuilder sb) {
        if (sb.length() == nums.length) {
            count++;
            if (count == k) {
                for (int num : nums) {
                    sb.append(num);
                }
                return;
            }
        }
        for (int i = 0; i < nums.length; i++) {
            if (!visited[i]) {
                visited[i] = true;
                backtrack(nums, k, visited, sb);
                visited[i] = false;
                if (count == k) {
                    return;
                }
            }
        }
    }
}
