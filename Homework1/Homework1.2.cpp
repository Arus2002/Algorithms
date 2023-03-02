#include <iostream>
#include <vector>

// Найти пик в массиве. Элемент массива является пиком, если он НЕ меньше
// своих соседей
// Input: arr[] = { 1, 3, 20, 4, 1, 0 }
// Output: 20
// Input: arr[] = {10, 20, 15, 2, 23, 90, 67}
// Output: 20 or 90
// Complexity: O(logn)

int FindPeak(std::vector<int> vec , int start , int end) {

  while (start < end) {
    if(start == end) {
      return vec[start];
    }
    else if(start == end - 1){
      if(vec[start] >= vec[end]) {
        return vec[start];
      }
      return vec[end];
    }
    else {
      int mid = (start + end) / 2;
  
      if(vec[mid] >= vec[mid - 1] && vec[mid] >= vec[mid + 1]){
        return vec[mid];
      }
    
      else if(mid >= 0 && vec[mid - 1] > vec[mid] && vec[mid] > vec[mid + 1]) {  
        end = mid - 1;
      }
  
      else
      {
        start = mid + 1;
      }
    }
  }
  return 0;
}

int main(){
  int N;
  std::cin >> N;
  std::vector<int> vec(N);
  for (int i = 0; i < vec.size(); i++){
    std::cin >> vec[i];
  }
  std::cout << FindPeak(vec , 0 , vec.size() - 1) << std::endl;

}