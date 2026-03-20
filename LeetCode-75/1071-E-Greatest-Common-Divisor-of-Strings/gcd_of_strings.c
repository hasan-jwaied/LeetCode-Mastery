int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

char* gcdOfStrings(char* str1, char* str2) {
    if (!str1 || !str2) return NULL;

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    char* concat1 = malloc(len1 + len2 + 1);
    if (!concat1) return NULL;
    char* concat2 = malloc(len1 + len2 + 1);
    if (!concat2) {
        free(concat1);
        return NULL;
    }

    strcpy(concat1, str1);
    strcat(concat1, str2);

    strcpy(concat2, str2);
    strcat(concat2, str1);

    if (strcmp(concat1, concat2) != 0) {
        free(concat1);
        free(concat2);        
        char* empty = malloc(1);
        if (!empty) return NULL;
        empty[0] = '\0';
        return empty; 
    }
    free(concat1);
    free(concat2);

    int gcd_len = gcd(len1, len2);

    char* result = malloc(gcd_len + 1);
    if (!result) return NULL;

    strncpy(result, str1, gcd_len);
    result[gcd_len] = '\0';

    return result;
}