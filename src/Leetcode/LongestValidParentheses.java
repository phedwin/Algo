package Leetcode;

import java.util.Stack;

public class LongestValidParentheses {
    public int longestValidParentheses(String s) {
        Stack<Integer> stack = new Stack<>();
        int maxLength = 0;
        int lastInvalid = -1; // last invalid position

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                stack.push(i);
            } else {
                if (stack.isEmpty()) {
                    lastInvalid = i;
                } else {
                    stack.pop();
                    if (stack.isEmpty()) {
                        maxLength = Math.max(maxLength, i - lastInvalid);
                    } else {
                        maxLength = Math.max(maxLength, i - stack.peek());
                    }
                }
            }
        }

        return maxLength;
    }
}
