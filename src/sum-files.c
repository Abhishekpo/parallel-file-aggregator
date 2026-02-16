#include <stdio.h>

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

int main(int argc, char *argv[]) {
  long negative_numbers= 0, positive_numbers= 0, negative_sum= 0,
       positive_sum= 0;
  int i, n;
  FILE *fp;

  if (argc > 1) {
    for (i= 1; i < argc; i++) {
      fp= fopen(argv[i], "r");

      /* silently ignore nonexistent files, or ones that there was an error
         trying to open */
      if (fp != NULL) {
        negative_numbers= positive_numbers= 0;
        fscanf(fp, "%d", &n);

        while (!feof(fp)) {
          /* zero obviously doesn't need to be included in either sum */
          if (n < 0)
            negative_numbers += n;
          else
            if (n > 0)
              positive_numbers += n;

          fscanf(fp, "%d", &n);
        }

        negative_sum += negative_numbers;
        positive_sum += positive_numbers;

        fclose(fp);
      }
    }
  }

  printf("%ld %ld\n", negative_sum, positive_sum);

  return 0;
}
