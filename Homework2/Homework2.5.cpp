#include <iostream>
#include <vector>

//Implement counting sort to sort numbers from any given range [a, b] with size k, using O(n+k) space.

int getMax (const std::vector<int>& vec) {
  int max = vec[0];
  for(int i = 0 ; i < vec.size() ; ++i) {
    if(vec[i] > max) {
      max = vec[i];
    }
    
  }
  return max;
}
int getMin (const std::vector<int>& vec) {
  int min = vec[0];
  for(int i = 0 ; i < vec.size() ; ++i) {
    if(vec[i] < min) {
      min = vec[i];
    }
    
  }
  return min;
}
std::vector<int> SortedVector (std::vector<int>& vec) {
  int min_element = getMin(vec);
  int max_element = getMax(vec);
  std::vector<int> CountVector(max_element - min_element + 1);
  for(auto& itr : vec) { // count same elements
    CountVector[itr - min_element]++;
  }
  for(int i = 1 ; i < CountVector.size() ; ++i) {
    CountVector[i] += CountVector[i - 1]; //bac enq toxum 1-y
  }
  std::vector<int> SortedVector(vec.size());
  for(int i = vec.size() - 1 ; i >= 0 ; i--) {
    SortedVector[CountVector[vec[i] - min_element] - 1] = vec[i];
    CountVector[vec[i] - min_element] --;
  }
  return SortedVector;
  
}

void Print (std::vector<int>& vec) {
  for(auto& itr: vec) {
     std::cout << itr << " ";
  }
  std::cout << std::endl;
}

int main() {
  std::cout << "Size: ";
  int N;
  std::cin >> N;
  std::vector<int> vec(N);
  std::cout << "Vector: ";
  for(int i = 0 ; i < vec.size() ; ++i) {
    std::cin >> vec[i];
  }
  std::vector<int> ResultVector = SortedVector(vec);
  std::cout << "Sorted vector: ";
  Print(ResultVector);
}