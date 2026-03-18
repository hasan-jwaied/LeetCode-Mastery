class Solution {
public:
    std::string mergeAlternately(std::string word1, std::string word2) {
        int w1_len = size(word1);
        int w2_len = size(word2);
        std::string result = "";
        result.reserve(w1_len+w2_len);

        int i=0, j=0;
        while (i<w1_len && j<w2_len)
        {
            result += word1[i++];
            result += word2[j++];
        }

        if (i<w1_len) // Append the rest of word1 (if any characters are left)
        {
            result.append(word1, i, std::string::npos);
        }

        if (j<w2_len) // Append the rest of word2 (if any characters are left)
        {
            result.append(word2, j, std::string::npos);
        }

        return result;
    }
};