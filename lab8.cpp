#include <iostream>
#include <deque>
#include <map>
#include <ctime>

using namespace std;

#define MAX 30000000

int main() {
   deque<int> myDeque;
   map<int, int> myMap;

   clock_t start, end;
   double cpu_time_used;

  // Добавление в deque
  start = clock();
  for(int i = 0; i < 100000; i++) {
      myDeque.push_back(i);
  }
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  std::cout << "Время добавления в deque: " << cpu_time_used << " секунд\n";

   // Добавление в словарь
   start = clock();
   for(int i = 0; i < MAX; i++) {
       myMap.insert(make_pair(i, i));
   }
   end = clock();
   cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
   cout << "Время добавления в словарь: " << cpu_time_used << " секунд\n";

  
  // Удаление из deque
  start = clock();
  for(int i = 0; i < 100000; i++) {
      myDeque.pop_front();
  }
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  std::cout << "Время удаления из deque: " << cpu_time_used << " секунд\n";


   // Удаление из словаря
   start = clock();
   for(int i = 0; i < MAX; i++) {
       myMap.erase(i);
   }
   end = clock();
   cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
   cout << "Время удаления из словаря: " << cpu_time_used << " секунд\n";

   // Поиск в словаре
   start = clock();
   for(int i = 0; i < MAX; i++) {
       myMap.find(i);
   }
   end = clock();
   cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
   cout << "Время поиска в словаре: " << cpu_time_used << " секунд\n";

   return 0;
}
