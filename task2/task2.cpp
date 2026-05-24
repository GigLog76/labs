#include "HashTable.h"
#include <cassert>


int task2(){
  HashTable PracsovaList;
  {
    std::cout << "Test1" << std::endl;
    assert(PracsovaList.isEmpty());
  };
  PracsovaList.add("Brick", 67);
  PracsovaList.add("Tile", 52);
  {
    std::cout << "Test2" << std::endl;
    double value=67;
    assert(value == PracsovaList.find("Brick"));
    double value2=52;
    assert(value2 == PracsovaList.find("Tile"));
  }
  std::cout << "OK" << std::endl;
  return 0;
}