//Answer of 1
#include <stdio.h>
#include <stdlib.h>

int compare_ints(const void *a, const void *b) {
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;
    if (arg1 < arg2) return 1;
    if (arg1 > arg2) return -1;
    return 0;
}

int biggest_of_two(int a, int b) {
    int arr[2] = {a, b};
    qsort(arr, 2, sizeof(int), compare_ints);
    return arr[0];
}

int biggest_of_three(int a, int b, int c) {
    int arr[3] = {a, b, c};
    qsort(arr, 3, sizeof(int), compare_ints);
    return arr[0];
}

int main() {
    int x = 5;
    int y = 10;
    int z = 15;

    int max_two = biggest_of_two(x, y);
    int max_three = biggest_of_three(x, y, z);

    printf("The biggest of %d and %d is %d\n", x, y, max_two);
    printf("The biggest of %d, %d, and %d is %d\n", x, y, z, max_three);

    return 0;
}
//Answer of 2
#include <stdio.h>

void div_rem(int a, int b, int *quotient, int *remainder) {
    int q = 0;
    int r = a;

    while (r >= b) {
        r -= b;
        q++;
    }

    *quotient = q;
    *remainder = r;
}

int main() {
    int a = 17;
    int b = 5;
    int quotient, remainder;

    div_rem(a, b, &quotient, &remainder);

    printf("%d divided by %d:\n", a, b);
    printf("Quotient = %d\n", quotient);
    printf("Remainder = %d\n", remainder);

    return 0;
}
//Answer of 3
#include <stdio.h>

int stringLength(char*);

int main()
{
    char str[100];
    int len;

    printf("Input a string : ");
    fgets(str, sizeof(str), stdin);

    len = stringLength(str);

    printf("The length of the given string %s is: %d\n", str, len);

    return 0;
}

int stringLength(char *str)
{
    char *ptr = str;

    while (*ptr)
    {
        ptr++;
    }

    return ptr-str -1;
}
//Answer of 4
#include <stdio.h>

void reverseString(char *);

int main()
{
    char str[100];

    printf("Input a string : ");
    fgets(str, sizeof(str), stdin);

    // Remove newline character from the input string
    if (str[strlen(str) - 1] == '\n')
    {
        str[strlen(str) - 1] = '\0';
    }

    reverseString(str);

    printf("Reverse of the string is : %s\n", str);

    return 0;
}

void reverseString(char *str)
{
    // Initialize pointer to the end of the string
    char *end = str + strlen(str) - 1;

    // Loop through the string using two pointers
    while (str < end)
    {
        // Swap the characters pointed by str and end
        char temp = *str;
        *str = *end;
        *end = temp;

        // Increment str and decrement end pointers
        str++;
        end--;
    }
}
//Answer of 5
#include <stdio.h>
#include <string.h>

int main()
{
    char sentence[1000];
    int wordCount = 0;
    int charCount = 0;
    int i;

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    // Remove newline character from the input sentence
    if (sentence[strlen(sentence) - 1] == '\n')
    {
        sentence[strlen(sentence) - 1] = '\0';
    }

    // Loop through the sentence to count words and characters
    for (i = 0; sentence[i] != '\0'; i++)
    {
        if (sentence[i] == ' ')
        {
            wordCount++;
            printf("%d ", charCount);
            charCount = 0;
        }
        else
        {
            charCount++;
        }
    }

    // Count the last word
    wordCount++;
    printf("%d\n", charCount);

    printf("Total number of words: %d\n", wordCount);
    return 0;
}
//Answer of 6
#include <stdio.h>
#include <string.h>

int main()
{
    char sentence[1000];
    char modified[1000];
    int i, j = 0;

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    // Remove newline character from the input sentence
    if (sentence[strlen(sentence) - 1] == '\n')
    {
        sentence[strlen(sentence) - 1] = '\0';
    }

    // Remove white spaces and replace "." with ":" in the sentence
    for (i = 0; sentence[i] != '\0'; i++)
    {
        if (sentence[i] != ' ')
        {
            if (sentence[i] == '.')
            {
                modified[j] = ':';
            }
            else
            {
                modified[j] = sentence[i];
            }
            j++;
        }
    }
    modified[j] = '\0';

    printf("Modified sentence: %s\n", modified);

    return 0;
}
//Answer of 7
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concat(const char*, const char*);

int main()
{
    char str1[1000], str2[1000];
    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);

    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);

    str1[strcspn(str1, "\n")] = '\0'; // remove newline character
    str2[strcspn(str2, "\n")] = '\0'; // remove newline character

    char *result = concat(str1, str2);
    printf("Concatenated string: %s\n", result);

    free(result); // free dynamically allocated memory

    return 0;
}

char* concat(const char* s1, const char* s2)
{
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);
    char* result = (char*)malloc(len1 + len2 + 1);

    if (result == NULL)
    {
        printf("Error: memory allocation failed\n");
        exit(1);
    }

    memcpy(result, s1, len1);
    memcpy(result + len1, s2, len2 + 1);

    return result;
}
//Answer of 8
#include <stdio.h>

void factorial(int*, int*);

int main()
{
    int num, fact = 1;
    int* p_num = &num;
    int* p_fact = &fact;

    printf("Enter a number: ");
    scanf("%d", p_num);

    factorial(p_num, p_fact);

    printf("%d's factorial: %d\n", num, fact);

    return 0;
}

void factorial(int* num, int* fact)
{
    int i;
    for (i = 1; i <= *num; i++)
    {
        *fact *= i;
    }
}
//Answer of 9
#include <stdio.h>

int* calculate(int a, int b, int c);

int main()
{
    int a = 10, b = 20, c = 30;
    int* result = calculate(a, b, c);

    printf("The sum is %d\n", result[0]);
    printf("The average is %d\n", result[1]);
    printf("The product is %d\n", result[2]);

    return 0;
}

int* calculate(int a, int b, int c)
{
    static int arr[3];

    arr[0] = a + b + c;
    arr[1] = arr[0] / 3;
    arr[2] = a * b * c;

    return arr;
}
//Answer of 10
#include <stdio.h>
#include <string.h>

#define MAX_NAMES 50
#define MAX_LENGTH 20

void sort_names(char *names[], int count);

int main()
{
    char *names[MAX_NAMES];
    int count = 0;

    printf("Enter names: ");

    char input[MAX_NAMES * MAX_LENGTH];
    fgets(input, sizeof(input), stdin);

    char *token = strtok(input, " \n");

    while (token != NULL && count < MAX_NAMES) {
        names[count] = token;
        count++;
        token = strtok(NULL, " \n");
    }

    sort_names(names, count);

    printf("alphabetical list:\n");
    for (int i = 0; i < count; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}

void sort_names(char *names[], int count)
{
    char *temp;
    int sorted = 0;

    while (!sorted) {
        sorted = 1;

        for (int i = 0; i < count - 1; i++) {
            if (strcmp(names[i], names[i+1]) > 0) {
                temp = names[i];
                names[i] = names[i+1];
                names[i+1] = temp;
                sorted = 0;
            }
        }
    }
}
