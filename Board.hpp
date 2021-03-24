#pragma once
#include <string>
#include "Direction.hpp"
#include <limits.h>
#include <vector>
using namespace std;
namespace ariel
{
  class  Board{
      vector<vector<char>> board;
      int len;
    public: 
        Board(); 
        void post(unsigned int row, unsigned int column, Direction dr, string str);
        string read(unsigned int row, unsigned int column, Direction dr, unsigned int length);
        void show(); 
  };
}