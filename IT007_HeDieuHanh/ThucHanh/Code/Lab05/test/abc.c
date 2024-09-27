#include <stdio.h>
#include <unistd.h>
#define MAX LINE 80 /* The maximum length command */
int main(void) {
char *args[MAX LINE/2 + 1]; /* command line arguments */
int should run = 1; /* flag to determine when to exit program
*/
while (should run) { printf("it007sh>"); fflush(stdout);
/**
Do something
*/ }
return 0;
}
