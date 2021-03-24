#include "Board.hpp"
#include "Direction.hpp"
#include <string>
#include <iostream>
#include <stdexcept>
#include <limits>
#include <vector>

using namespace std;
namespace ariel{

    Board::Board(){
        unsigned long i,j;
        len = 100;
        //cout << "Board 1";
        for(i=0;i<len;i++){
            board.push_back(vector<char>());
            for(j=0;j<len;j++){
                board[i].push_back('_');
            }
        }
        //cout << "Board constructor";
    }


    void Board::post(unsigned int row, unsigned int column, Direction dr, string str){
        unsigned long i=0;
        unsigned long cast_row = (unsigned long) row, cast_column = (unsigned long) column;
        if (cast_row >= board.size() || cast_column >= board[0].size()) {
            unsigned long new_size;
            if (cast_row > cast_column)
                new_size = cast_row + str.size();
            else
                new_size = cast_column + str.size();

            for (unsigned long i = 0; i < board.size(); i++) {
                for (unsigned long j = board[i].size(); j < new_size; j++) {
                    board.at(i).push_back('_');
                }
            }

            for (int i =board.size(); i < new_size; i++) {
                vector<char> new_row;
                for (int j=0; j < new_size; j++) {
                    new_row.push_back('_');
                }
                board.push_back(new_row);
            }
            len = (int) new_size;
        }

        if(dr==ariel::Direction::Horizontal){
            for(i=0;i<str.length();i++){
                board[cast_row][cast_column+i]= str[(unsigned long)i];
            }
        }
        if(dr==ariel::Direction::Vertical){
            for(i=0;i<str.length();i++){
                board[cast_row+i][cast_column]=str[(unsigned long)i];
            }
        }
        //cout << "post func";
    }

    string Board::read(unsigned int row, unsigned int column, Direction dr, unsigned int length){
        unsigned long cast_row = (unsigned long) row, cast_column = (unsigned long) column;
        string str = "";
        unsigned long i;
        if(dr==ariel::Direction::Horizontal){
            for(i=0;i<length;i++){
                str += board[cast_row][cast_column+i];
            }
        }
        if(dr==ariel::Direction::Vertical){
            for(i=0;i<length;i++){
                str += board[cast_row+i][cast_column];
            }
        }
        //cout << "read func";
        return str;
    }

    void Board::show(){
        unsigned long i=0, j=0;
        for(i=0; i<len;i++){
            for(j=0;j<len;j++){
                cout << board[i][j];
            }
            cout << '\n';
        }
        cout << endl;
    }
}