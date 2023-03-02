#include <iostream>
#include <vector>
#include <algorithm>

//Given an array, determine and return the minimum number of swaps that must be performed to make the array sorted.

//4 3 2 1 -> 2

int MinSwapCount(std::vector<int>& vec) {
  
  std::vector<std::pair<int , int>> ElementAndIndex;
  for(int i = 0 ; i < vec.size() ; ++i) {
    ElementAndIndex.push_back({vec[i] , i}); //{4 0} {3 1} {2 2} {1 3}
  }

  std::sort(ElementAndIndex.begin() , ElementAndIndex.end());
  
  int countOfSwaps = 0;
  for(int i = 0 ; i < vec.size() ; ++i) {
    std::pair<int , int> ElementAndIndex2 = ElementAndIndex[i];
    int value = ElementAndIndex2.first;
    int index = ElementAndIndex2.second;
    if(i != index) {
      countOfSwaps++;
      std::swap(ElementAndIndex[i] , ElementAndIndex[index]);
      i--;
    }
  }
  
  return countOfSwaps;
}

int main() {
  int N;
  std::cin >> N;
  std::vector<int> vec(N);
  for(int i = 0 ; i < vec.size() ; ++i) {
    std::cin >> vec[i];
  }
  int result;
  result = MinSwapCount(vec);
  std::cout << result;
}