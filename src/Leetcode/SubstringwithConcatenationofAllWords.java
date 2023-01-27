package Leetcode;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class SubstringwithConcatenationofAllWords {
    public List<Integer> findSubstring(String s, String[] words) {
        List<Integer> result = new ArrayList<>();
        if (s == null || s.length() == 0 || words == null || words.length == 0) {
            return result;
        }
        int wordLen = words[0].length();
        int concatLen = wordLen * words.length;
        Map<String, Integer> wordCount = new HashMap<>();
        for (String word : words) {
            wordCount.put(word, wordCount.getOrDefault(word, 0) + 1);
        }

        for (int i = 0; i <= s.length() - concatLen; i++) {
            Map<String, Integer> copy = new HashMap<>(wordCount);
            for (int j = i; j < i + concatLen; j += wordLen) {
                String sub = s.substring(j, j + wordLen);
                if (copy.containsKey(sub)) {
                    int count = copy.get(sub);
                    if (count == 1) {
                        copy.remove(sub);
                    } else {
                        copy.put(sub, count - 1);
                    }
                } else {
                    break;
                }
            }
            if (copy.isEmpty()) {
                result.add(i);
            }
        }
        return result;
    }
}
