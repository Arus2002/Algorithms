#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
//Дан массив целых чисел. Выведите элементы массива в порядке убывания
// частоты встречаемости элементов..
// Например:
// Вход: {3, 6, 3, 9, 6, 7, 9, 9}
// Выход: {9, 9, 9, 3, 3, 6, 6, 7}
// (Для решения использовать Insertion sort)

void SortFrequency(std::vector<int> arr){
  std::map<int , int> m;
  for(int i = 0 ; i < arr.size() ; ++i){
    m[arr[i]]++;
  }
  //test
  // for(auto itr = m.begin() ; itr != m.end() ; ++itr){
  //   std::cout << itr -> second << std::endl;
  // }
  
  int index;
  int pastIndex;
  int key;
  int elem;
  std::sort(arr.begin() , arr.end());
  for(index = 1 ; index < arr.size() ; ++index){
    elem = arr[index];
    key = m[arr[index]];
    pastIndex = index - 1;
    while(pastIndex >= 0 && m[arr[pastIndex]] < key){
      arr[pastIndex + 1] = arr[pastIndex];
      pastIndex --;
    }
    arr[pastIndex + 1] = elem;
  }
  
  for (int i = 0; i < arr.size(); i++)
  {
    std::cout << arr[i] << " "; 
  }
}

int main() {
  int N;
  std::cin >> N;
  std::vector<int> vec(N);
  for (int i = 0; i < vec.size(); i++){
    std::cin >> vec[i];
  }
  SortFrequency(vec);

}