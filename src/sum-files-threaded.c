/* Author: Abhishek Poudel. UID number : 119452868 TA:Derrick Section: 0302
  "I pledge on my honor that I have not given or received any unauthorized
   assistance on this assignment."
*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct {
  long x, y;
} Point;

void *thread_call_function(void *arg) {
  FILE *fp;
  int n;
  char *filename = (char *)arg;
  long negative_numbers = 0, positive_numbers = 0;
  Point *pt = malloc(sizeof(Point));
  if (pt ==NULL) {
    perror("Failed to allocate memory");
    exit(EXIT_FAILURE);
  }

  fp = fopen(filename, "r");
  if (fp != NULL) {
    while (fscanf(fp, "%d", &n) != EOF) {
      if (n < 0)
        negative_numbers += n;
      else if (n > 0)
        positive_numbers += n;
    }

    pt->x = positive_numbers;
    pt->y = negative_numbers;
    fclose(fp);
  } else {
    pt->x = pt->y = 0;
  }

  pthread_exit(pt);
}

int main(int argc, char *argv[]) {
  pthread_t *tid;
  Point *p;
  int i = 0;
  long sum_pos = 0, sum_neg = 0;

  if (argc > 1) {
    tid = malloc((argc - 1) * sizeof(*tid));
    if (tid == NULL) {
      perror("Failed to allocate memory for threads");
      exit(EXIT_FAILURE);
    }

    for (i = 0; i < argc - 1; i++) {
      if (pthread_create(&tid[i], NULL, thread_call_function, argv[i + 1])) {
        perror("Failed to create thread");
      }
    }

    for (i = 0; i < argc - 1; i++) {
      if (pthread_join(tid[i], (void **)&p) == 0) {
        sum_pos += p->x;
        sum_neg += p->y;
        free(p);
      }
    }

    free(tid);

    printf("%ld %ld\n", sum_neg, sum_pos);
  }

  return 0;
}
