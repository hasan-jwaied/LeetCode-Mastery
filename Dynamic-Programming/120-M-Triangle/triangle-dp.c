int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) {
    int m = triangleSize;
    for (int i=m-2; i>=0; i--)
    {
        for (int j=0; j<triangleColSize[i]; j++)
        {
            triangle[i][j] += triangle[i+1][j+1]<triangle[i+1][j]?triangle[i+1][j+1]:triangle[i+1][j];
        }
    }
    return triangle[0][0];
}