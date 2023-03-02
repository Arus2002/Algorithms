#include <iostream>
#include <vector>
#include <algorithm>

//Given K sorted arrays, return their sorted concatenation.
// Example
// For arrays = [[1, 3, 5], [2, 3], [2, 3, 5, 8]], the output should be
// solution(arrays) = [1, 2, 2, 3, 3, 3, 5, 5, 8].

std::vector<int> merge(
  const std::vector<int>& v1, 
  const std::vector<int>& v2
) {
  int i = 0;
  int j = 0;

  std::vector<int> result;
  result.reserve(v1.size() + v2.size());
  while(i < v1.size() && j < v2.size()) {
    if(v1[i] < v2[j]) {
      result.push_back(v1[i]);
      ++i;
    } else {
      result.push_back(v2[j]);
      ++j;
    }
  }
  while(i < v1.size()) {
    result.push_back(v1[i]);
    ++i;
  }
  while(j < v2.size()) {
    result.push_back(v2[j]);
    ++j;
  }
  return result;
}



std::vector<int> SortedVector(std::vector<std::vector<int>>& vec) {
  std::vector<std::vector<int>> secondary_vec;
  while(vec.size() > 1) {
    secondary_vec.clear();
    int i = 0;
    while(i < vec.size()) {
      if( i == vec.size() - 1) {
        secondary_vec.push_back(vec[i]);
      }
      else {
        secondary_vec.push_back(merge(vec[i] , vec[i + 1]));
      }
      i += 2;
    }
    vec = secondary_vec;
  }
  return vec[0];
  
}

void Print(std::vector<int>& vec) {
  for(auto& itr : vec) {
    std::cout << itr << " ";
  }
  std::cout << std::endl;
}

int main() {
  std::vector<std::vector<int>> vec = {{1, 3, 5} , {2, 3} , {2, 3, 5, 8}};
  std::vector<int> Result;
  Result = SortedVector(vec);
  Print(Result);
  
  
}