#include <algorithm>
#include <iostream>
#include <utility>

using namespace std;

struct Item {
  int value;
  int weight;
};

bool sortFunction(Item i, Item j) {
  return (i.value / i.weight) > (j.value / j.weight);
}

void printArray(Item arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << "value, weight:\t" << arr[i].value << ", " << arr[i].weight << endl;
  }
}

class Solution {
 public:
  // Function to get the maximum total value in the knapsack.
  double fractionalKnapsack(int W, Item arr[], int n) {
    sort(arr, arr + n, sortFunction);

    double currWeight = 0, value = 0;
    int i = 0;
    while (i < n && currWeight < W) {
      double diff = W - currWeight;

      if (arr[i].weight <= diff) {
        currWeight += arr[i].weight;
        value += arr[i].value;
      } else {
        currWeight += diff;
        value += ((arr[i].value / arr[i].weight) * diff);
        break;
      }

      i++;
    }

    return value;
  }
};

int main() {
  int n = 3;
  int W = 50;
  Item arr[n] = {{60, 10}, {100, 20}, {120, 30}};

  Solution sol = Solution();
  cout << sol.fractionalKnapsack(W, arr, n) << endl;
}