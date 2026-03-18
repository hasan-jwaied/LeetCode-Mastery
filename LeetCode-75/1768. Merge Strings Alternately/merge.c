char * mergeAlternately(char * word1, char * word2){
    int w1_len = strlen(word1);
    int w2_len = strlen(word2);

    char *result = malloc(w1_len + w2_len + 1);
    if (!result) return NULL; // if failed to allocate memory, return NULL ptr.

    int i=0, j=0, k=0;
    while (i<w1_len && j<w2_len)
    {
        result[k++]=word1[i++];
        result[k++]=word2[j++];
    }

    while (i<w1_len)
    {
        result[k++] = word1[i++];
    }
    while (j<w2_len)
    {
        result[k++] = word2[j++];
    }
    result[k] = '\0';
    return result;
}