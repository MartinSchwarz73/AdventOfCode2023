#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int text2digit(char *in)
{
    const char *numbers[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"}; 

    for (int i = 0; i < 10; i++) {
        if (strncmp(in, numbers[i], strlen(numbers[i])) == 0) {
            *in = '0' + i;
            return i;
        }
    }
    return 0;
}


int main(int argc, char **argv)
{
    char nr[3] = "..\0";
    char line[MAX];
    char tmp[MAX];
    int sum = 0;
    int lines = 0;
    int i = 0;

    while (!feof(stdin)) {
        if (fgets(line, MAX, stdin) == NULL) continue;
        if (line[strlen(line) - 1] == '\n') line[strlen(line) - 1] = '\0';
        printf("%2d: %s = ", ++lines, line);
        strcpy(tmp, line);
        while (strlen(tmp) > 0) {
            text2digit(tmp);
            if (isdigit(tmp[0])) { 
                if (nr[0] == '.') {
                    nr[0] = tmp[0];
                    nr[1] = tmp[0];
                }
                else {
                    nr[1] = tmp[0];
                }
            }
            i++;
            strcpy(tmp, (char *)(line + i));
        }
        printf("%s - %d\n", nr, 10 * (nr[0] - '0') + (nr[1] - '0'));
        if (nr[0] != '.') 
            sum += 10 * (nr[0] - '0') + (nr[1] - '0');
        i = 0;
        nr[0] = '.';
        nr[1] = '.';
    }
    printf("Lines: %d\nSum: %d\n",lines, sum);
    
    return 0;
}