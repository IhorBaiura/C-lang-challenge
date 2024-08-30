#include <stdio.h>

#define MAXLINES 5000 /* max #lines to be sorted */
#define BUFFERSIZE 7000

char *lineptr[MAXLINES];            /* pointers to text lines */
char buffer[MAXLINES * BUFFERSIZE]; // Pre-allocated buffer for lines

int readlines(char *lineptr[], char *linebuffer, int maxlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);

/* sort input lines */
int main() {
  int nlines; /* number of input lines read */
  if ((nlines = readlines(lineptr, buffer, MAXLINES)) >= 0) {
    qsort(lineptr, 0, nlines - 1);
    writelines(lineptr, nlines);
    return 0;
  } else {
    printf("error: input too big to sort\n");
    return 1;
  }
}
