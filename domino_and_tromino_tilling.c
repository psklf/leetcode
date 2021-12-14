#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/**
 * index: cur index(0-index)
 * max: max index (size - 1)
 */
long accumu(int index, bool flat, int max, int *map) {
  /*
  if (index > max) {
    return 0;
  }
  if (index == max) {
    if (flat) { return 1; } else { return 0; }
  }
  */

  if (flat) {
    map[index]++;
    return accumu(index + 1, true, max, map)
      + accumu(index + 2, true, max, map)
      + 2 * accumu(index + 3, true, max, map)
      + 2 * accumu(index + 3, false, max, map)
      + 2 * accumu(index + 2, false, max, map);
  } else {
    return accumu(index + 2, false, max, map)
      + accumu(index + 2, true, max, map);
  }

}

int numTilings(int n) {
  /*
  long i = accumu(0, true, n - 1) + accumu(1, true, n - 1)
    + 2 * accumu(1, false, n - 1)
    + 2 * accumu(2, true, n - 1)
    + 2 * accumu(2, false, n - 1);
    */
  if (n == 1) { return 1; }
  if (n == 2) { return 2; }
  if (n == 3) { return 5; }
  long long *map = (long long *)malloc(sizeof(long long) * n);
  long long *gap_map = (long long *)malloc(sizeof(long long) * n);
  gap_map[0] = 0;
  gap_map[1] = 2;
  gap_map[2] = 4;

  map[0] = 1;
  map[1] = 2;
  map[2] = 5;
  for (int i = 3; i < n; ++i) {
    map[i] = map[i-1]  // flat to flat
      + map[i-2]
      + map[i-3] * 2
      + gap_map[i - 2];  // gap to flat
    gap_map[i] =
      gap_map[i - 2]     // gap to gap
      + map[i - 2] * 2   // flat to gap
      + map[i - 3] * 2;
    if (map[i] > (long long)(1e9+7)) { map[i] = map[i] % (long long)(1e9+7); }
    if (gap_map[i] > (long long)(1e9+7)) { gap_map[i] = gap_map[i] % (long long)(1e9+7); }
  }

  return map[n-1] % (long long)(1e9+7);
}

int main() {
  int i = numTilings(25);
  printf("Main Ret %d\n", i);
  return 0;
}
