#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char **argv)
{
    char nr[3] = "..\0";
    int sum = 0;
    int lines = 0;
    char zn;

    while ((zn = getchar()) != EOF) {
        if ((zn == '\n') && (nr[0] != '.')) {
            sum += 10 * (nr[0] - '0') + (nr[1] - '0');
            nr[0] = '.';
            lines++;
        } 
        else if (isdigit(zn)) { 
            if (nr[0] == '.') {
                nr[0] = zn;
                nr[1] = zn;
            }
            else {
                nr[1] = zn;
            }
        }
    }
    printf("Lines: %d\nSum: %d\n",lines, sum);
    
    return 0;
}