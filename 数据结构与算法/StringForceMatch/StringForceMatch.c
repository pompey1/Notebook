#include <stdio.h>
#include <stdlib.h>

typedef struct String
{
    char *data;
    int length;
} String;

typedef enum Bool
{
    false,
    true
} Bool;

String *InitString()
{
    String *string = (String *)malloc(sizeof(String));
    string->data = NULL;
    string->length = 0;
    return string;
}

void *StringAssign(String *string, char *data)
{
    if (string->data)
    {
        // 防止野指针的出现
        free(string->data);
    }
    char *temp = data;
    int len = 0;
    while (*temp)
    {
        len++;
        temp++;
    }
    if (len == 0)
    {
        // 判断的目的：避免在空字符串的情况下存入一个'/0'
        string->length = 0;
        string->data = NULL;
    }
    else
    {
        string->length = len;
        string->data = (char *)malloc(sizeof(char) * (len + 1));
        temp = data;
        for (int i = 0; i < len + 1; i++, temp++)
        {
            string->data[i] = *temp;
        }
    }
}

void PrintString(String *string)
{
    for (int i = 0; i < string->length; i++)
    {
        printf(((i == 0) ? ("%c") : ("->%c")), string->data[i]);
    }
}

Bool ForceMatch(String *main, String *sub)
{
    int i = 0, j = 0;
    while (i < main->length && j < sub->length)
    {
        if (main->data[i] == sub->data[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
    }
    if (j == sub->length)
    {
        return true;
    }
    return false;
}

int main()
{
    String *string = InitString();
    String *subString = InitString();
    StringAssign(string, "ABCDEFG");
    StringAssign(subString, "EFG");
    PrintString(string);
    printf((ForceMatch(string, subString)==true)?("\nTrue"):("\nFalse"));
    free(string);
    free(subString);
    return 0;
}