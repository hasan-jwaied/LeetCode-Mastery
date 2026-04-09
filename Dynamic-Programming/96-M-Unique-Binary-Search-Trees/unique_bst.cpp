class Solution {
public:
    int factorial (int n) {
        if (n <= 1)
            return 1;
        return factorial(n-1)*n;
    }

    int numTrees(int n) {
        if (n <= 1)
            return 1;
        return factorial(2*n)/(factorial(n)*factorial(n+1));    
    }
};