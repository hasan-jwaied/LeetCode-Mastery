class Solution {
public:
    int gcd(int a, int b)
    {
        if (b==0)
            return a;
        return gcd(b, a%b);
    }

    string gcdOfStrings(string str1, string str2) {
        int len1 = str1.length();
        int len2 = str2.length();
        string concat1 = str1 + str2;
        string concat2 = str2 + str1;
        if (concat1 != concat2)
            return "";
        int gcd_len = gcd(len1, len2);
        return str1.substr(0, gcd_len);
    }
};
