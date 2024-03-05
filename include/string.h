int strcmp(const char *s1, const char *s2);
int strcmp(const char *s1, const char *s2)
{
    int k = 0;
    for (int i = 0; i < strlen(s1); i++)
    {
        for (int j = 0; j < strlen(s2); j++)
        {
            if (s1[i] != s2[j])
            {
                k++;
            }
        }
    }
    return k;
}
int strlen(const char *s);
{
    int k = 0;
    do 
        {
            k++;
        } while (s[k] != '\0')
    return k;
}