#include <iostream>
#include <vector>
#include <cmath>

// Имея отсортированный целочисленный массив, найти k ближайших
// элементов к заданному числу target в массиве, где k и target заданы
// положительными целыми числами.
// Input: [10, 12, 15, 17, 18, 20, 25], k = 4, target = 16
// Output: [12, 15, 17, 18]
// Input: [2, 3, 4, 5, 6, 7], k = 3, target = 1
// Output: [2, 3, 4]
  
std::vector<int> PrintKValues(std::vector<int> vec , int k , int target) {
  std::vector<int> Result{};
  int left = 0;
  int right = vec.size() - k;
  while( left < right ) {
    int mid = (left + right) / 2;
    if(std::abs(target - vec[mid]) > std::abs(target - vec[mid + k])) {
      left = mid + 1;
    }
    else {
      right = mid;
    }
  }

  -- left;
  for(int i = k ; i != 0 ; -- i) {
    Result.push_back(vec[++ left]);
  }

  return Result;
}

int main() {
  int N;
  std::cin >> N;
  int target;
  std::cin >> target;
  int k;
  std::cin >> k;
  std::vector<int> vec(N);
  for(int i = 0 ; i < vec.size() ; ++i){
    std::cin >> vec[i];
  }
  std::vector<int> result = PrintKValues(vec , k , target);
  for(auto itr : result) {
    std::cout << itr << " ";
  }
}