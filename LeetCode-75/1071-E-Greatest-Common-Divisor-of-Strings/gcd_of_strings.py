from math import gcd
class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        len1 = len(str1)
        len2 = len(str2)
        concat1 = str1 + str2
        concat2 = str2 + str1
        if concat1 != concat2:
            return ""
        gcd_len = gcd(len1, len2)
        return str1[:gcd_len]