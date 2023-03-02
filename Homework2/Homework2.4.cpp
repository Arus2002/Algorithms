#include <iostream>
#include <vector>

//MergeSort 

void MergeTwoSortedVectorts(std::vector<int>& vec , int left , int middle , int right) {
  int leftSize = middle - left + 1;
  int rightSize = right - middle;
  std::vector<int> LeftVector(leftSize);
  std::vector<int> RightVector(rightSize);
  for(int i = 0 ; i < LeftVector.size() ; ++i) {
    LeftVector[i] = vec[i + left];
  }
  for(int i = 0 ; i < RightVector.size() ; ++i) {
    RightVector[i] = vec[middle + 1 + i];
  }
  int j = 0;
  int k = 0;
  for(int i = left ; i <= right ; ++i) {
    if((j < LeftVector.size()) && (k >= RightVector.size() || LeftVector[j] <= RightVector[k])) {
      vec[i] = LeftVector[j];
      j++;
    }
    else {
      vec[i] = RightVector[k];
      k++;
    }
  }
}

void MergeSortRecursion(std::vector<int>& vec , int left , int right) {
  if(left < right) {
    int middle = ( left + right) / 2;
    MergeSortRecursion(vec, left, middle);
    MergeSortRecursion(vec, middle + 1, right);
    MergeTwoSortedVectorts(vec , left , middle , right);
  }
}

void Print(std::vector<int>& vec) {
  for(auto& itr : vec) {
    std::cout << itr << " ";
  }
  std::cout << std::endl;
}

int main() {
  int N;
  std::cout << "Size: ";
  std::cin >> N;
  std::vector<int> vec(N);
  std::cout << "Array: ";
  for( int i = 0 ; i < vec.size() ; ++i ) {
    std::cin >> vec[i];
  }
  MergeSortRecursion(vec , 0 , vec.size() - 1);
  std::cout << "Sorted array: ";
  Print(vec);
  
  
}