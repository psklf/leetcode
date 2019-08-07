/**
 * Solution of mark result
 */
class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        int[] markList = new int[s.length()];
        for (int i = 0; i < markList.length; ++i) { markList[i] = -1; }

        return innerBreak(s, wordDict, 0, markList);
    }
    
    private boolean innerBreak(String s, List<String> wordDict, int sIndex, int[] marks) {
        if (marks[sIndex] != -1) { return marks[sIndex] == 1; }
        
        if (sIndex >= s.length()) { return false; }
        
        for (String word : wordDict) {
            if (word.length() > s.length() - sIndex) { continue; }
            // System.out.println(" " + s.substring(sIndex, sIndex + word.length()) + " " + word);
            if (s.substring(sIndex, sIndex + word.length()).equals(word)) {
                if (sIndex + word.length() == s.length()) {return true;}
                if (innerBreak(s, wordDict, sIndex + word.length(), marks)) {
                    marks[sIndex] = 1;
                    return true;
                } else {
                    continue;
                }
            }
        }
        marks[sIndex] = 0;
        return false;
    }
}

/**
 * Solution of Dynamic Programming
 */
class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        int[] dp = new int[s.length()];
        for (int i = 0; i < dp.length; ++i) { dp[i] = -1; }

        for (int i = s.length() - 1; i >= 0; --i) {
            for (String word : wordDict) {
                if (s.length() - i < word.length()) { continue; }
                if (s.substring(i, i + word.length()).equals(word)) {
                    // find a match
                    if (i + word.length() == s.length() || dp[i + word.length()] == 1) {
                        dp[i] = 1;
                        break;
                    }
                }
            }
            if (dp[i] != 1) { dp[i] = 0; }
        }

        return dp[0] == 1;
    }
}

