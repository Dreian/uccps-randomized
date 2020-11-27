#include <cstdio>
#include <cstdlib>
#include <ctime>

#define MAXN 1000000
#define REPEATS 15

int n, p;
int a[MAXN];
bool found = false;
int found_num;
int chosen_value;
int occurences;

int main() {
  srand(time(NULL));
  // input
  scanf("%d %d", &n, &p);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  // repeat the basic algorithm REPEATS times
  for (int k = 0; k < REPEATS && !found; k++) {
    occurences = 0;
    chosen_value = a[rand() % n];
    for (int i = 0; i < n; i++) {
      occurences += (chosen_value == a[i]); 
    }
    if (occurences >= (n * p + 99) / 100) {
      found = true;
      found_num = chosen_value;
    }
  }
  if (found) {
    printf("%d\n", found_num);
  } else {
    printf("-1\n");
  }
  return 0;
}
