void RemoveDups(char* str)
{
    if (!str)
        return;

    char* new_str = str;

    while (*(str++) != '\0')
    {
        if (*str != *new_str)
            *(++new_str) = *str;
    }

    *new_str = '\0';
}
