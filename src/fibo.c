#include "fibo.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 20
#define OR ((1.0 + sqrt(5.0)) / 2.0)
#define CON ((1.0 - sqrt(5.0)) / 2.0)

long fibonacci_recursive(int n) {
  if (n <= 1) {
    return n;
  }
  return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

long fibonacci_iterative(int n) {
  if (n <= 1) {
    return n;
  }

  long current;
  long prev_1 = 1;
  long prev_2 = 0;

  for (int i = 0; i < n - 1; i++) {
    current = prev_1 + prev_2;
    prev_2 = prev_1;
    prev_1 = current;
  }
  return current;
}

/*
static void print_matrice(int **M)
{
  printf("=========================\n");
  printf("M[0][0] = %d\n", M[0][0]);
  printf("M[0][1] = %d\n", M[0][1]);
  printf("M[1][0] = %d\n", M[1][0]);
  printf("M[1][1] = %d\n", M[1][1]);
  printf("=========================\n");

}
*/

static void matrix_multiply(int **result, int **M1, int **M2) {
  long top_left = M1[0][0] * M2[0][0] + M1[0][1] * M2[1][0];
  long top_right = M1[0][0] * M2[0][1] + M1[0][1] * M2[1][1];
  long bottom_left = M1[1][0] * M2[0][0] + M1[1][1] * M2[1][0];
  long bottom_right = M1[1][0] * M2[0][1] + M1[1][1] * M2[1][1];

  result[0][0] = top_left;
  result[0][1] = top_right;
  result[1][0] = bottom_left;
  result[1][1] = bottom_right;
  return;
}

static int **matricial_exponentiation(int **M, int n) {

  int nb = n;
  int **M_factor = malloc(2 * sizeof(int *));
  for (size_t i = 0; i < 2; i++)
    M_factor[i] = malloc(2 * sizeof(int));

  M_factor[0][0] = 1;
  M_factor[0][1] = 0;
  M_factor[1][0] = 0;
  M_factor[1][1] = 1;

  int **tmp = malloc(2 * sizeof(int *));
  for (size_t i = 0; i < 2; i++)
    tmp[i] = malloc(2 * sizeof(int));

  while (nb != 0) {
    if (nb & 1) {
      matrix_multiply(tmp, M_factor, M);
      M_factor[0][0] = tmp[0][0];
      M_factor[0][1] = tmp[0][1];
      M_factor[1][0] = tmp[1][0];
      M_factor[1][1] = tmp[1][1];
    }

    matrix_multiply(tmp, M, M);

    M[0][0] = tmp[0][0];
    M[0][1] = tmp[0][1];
    M[1][0] = tmp[1][0];
    M[1][1] = tmp[1][1];

    nb >>= 1;
  }

  for (size_t i = 0; i < 2; i++)
    free(tmp[i]);
  free(tmp);

  return M_factor;
}

long fibonacci_matricial_exponentiation(int n) {

  if (n <= 1)
    return n;

  int **M = malloc(2 * sizeof(int *));
  for (size_t i = 0; i < 2; i++)
    M[i] = malloc(2 * sizeof(int));

  M[0][0] = 1;
  M[0][1] = 1;
  M[1][0] = 1;
  M[1][1] = 0;

  int **result_matrix = matricial_exponentiation(M, n - 1);
  long result = result_matrix[0][0];

  for (size_t i = 0; i < 2; i++) {
    free(result_matrix[i]);
    free(M[i]);
  }
  free(result_matrix);
  free(M);

  return result;
}

long fibonacci_constant(int n) { return (pow(OR, n) - pow(CON, n)) / sqrt(5); }

int main(void) {

  for (size_t i = 0; i < MAX; i++) {
    long expected = fibonacci_recursive(i);
    long result = fibonacci_constant(i);
    // assert(expected == result);
    printf("fibo(%ld) = %ld (expected %ld) %s\n", i, result, expected,
           result == expected ? "OK" : "WRONG");
  }
}
