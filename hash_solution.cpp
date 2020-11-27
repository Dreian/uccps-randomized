#include <cstdio>
#include <unordered_map>

#define MAXN 1000000

int n, p;
int a[MAXN];
bool found = false;
int found_num;

int main() {
  // input
  scanf("%d %d", &n, &p);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  std::unordered_map<int, int> value_count;
  // go through the array and fill in the map
  for (int i = 0; i < n && !found; i++) {
    if (value_count.find(a[i]) == value_count.end()) {
      value_count[a[i]] = 1;
    } else {
      value_count[a[i]] += 1;
    }
    if (value_count[a[i]] >= (n * p + 99) / 100) {
      found = true;
      found_num = a[i];
    }
  }
  if (found) {
    printf("%d\n", found_num);
  } else {
    printf("-1\n");
  }
  return 0;
}
