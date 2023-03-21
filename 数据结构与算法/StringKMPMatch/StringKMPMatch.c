#include <stdio.h>
#include <stdlib.h>

typedef struct String
{
    char *data;
    int len;
} String;

String *InitString()
{
    String *string = (String *)malloc(sizeof(String));
    if (string == NULL)
    {
        printf("Allocate fail");
    }
    string->data = NULL;
    string->len = 0;
    return string;
}

String *AssignString(String *string, char *data)
{
    char *temp = data;
    int len = 0;
    while (*temp)
    {
        temp++;
        len++;
    }
    string->len = len;
    if (len == 0)
    {
        string->data = NULL;
    }
    else
    {
        temp = data;
        string->data = (char *)malloc(sizeof(char) * (len + 1));
        for (int i = 0; i < len; i++, temp++)
        {
            string->data[i] = *temp;
        }
    }
    return string;
}

void PrintString(String *string)
{
    for (int i = 0; i < string->len; i++)
    {
        printf((i == 0) ? ("%c") : ("->%c"), string->data[i]);
    }
}

int *CreateNext(String *string)
{
    int *next = (int *)malloc(sizeof(int) * string->len);
    next[0] = 0;
    int i = 1;
    int prefix_len = 0;
    while (i < string->len)
    {
        if (string->data[prefix_len] == string->data[i])
        {
            next[i++] = ++prefix_len;
        }
        else
        {
            if (prefix_len == 0)
            {
                next[i++] = 0;
            }
            else
            {
                prefix_len = next[prefix_len - 1];
            }
        }
    }
    return next;
}

void PrintArray(int *array, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf((i == 0) ? "%d" : "->%d", array[i]);
    }
}

int StringKMPMatch(String *mainString, String *subString)
{
    int i = 0, j = 0;
    int *next = CreateNext(subString);
    while (i < mainString->len)
    {
        if (mainString->data[i] == subString->data[j])
        {
            i++;
            j++;
        }
        else if (j > 0)
        {
            j = next[j - 1];
        }
        else
        {
            // 第一个字符串就匹配失败
            i += 1;
        }
        if (j == subString->len)
        {
            return (i - subString->len);
        }
    }
    return 0;
}

int main()
{
    String *mainString = InitString();
    String *subString = InitString();
    AssignString(mainString, "ABABACAB");
    AssignString(subString, "CAB");
    int index = StringKMPMatch(mainString, subString);
    printf("The index is %d", index);
    free(mainString);
    free(subString);
}