class Solution {
    public String mergeAlternately(String word1, String word2) {
        int w1_len = word1.length();
        int w2_len = word2.length();
        StringBuilder result = new StringBuilder(w1_len + w2_len);
        int i = 0;
        while (i < w1_len && i < w2_len) {
            result.append(word1.charAt(i));
            result.append(word2.charAt(i));
            i++;
        }
        
        if (i < w1_len) {
            result.append(word1.substring(i)); 
        }
        if (i < w2_len) {
            result.append(word2.substring(i)); 
        }
        
        return result.toString();
    }
}