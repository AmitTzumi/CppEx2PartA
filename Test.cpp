/**
 * AUTHORS: <Amit Tzumi>
 * 
 * Date: 2021-02
 */

#include "doctest.h"
#include "Board.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

Board b;

TEST_CASE("Good Board code") {
    b.post(100, 200, Direction::Horizontal, "abcd");
	CHECK(b.read(99, 201, Direction::Vertical, 3) == "_b_");
	b.post(99, 202, Direction::Vertical, "xyz");
	CHECK(b.read(100, 200, Direction::Horizontal, 4) == "abyd");
    b.post(101,7,ariel::Direction::Horizontal, "MyBoard");
    CHECK(b.read(101,7, ariel::Direction::Horizontal, 7) == "MyBoard");
    CHECK(b.read(101,7, ariel::Direction::Horizontal, 2) == "My");
    b.post(208,202,ariel::Direction::Vertical, "Found a dog");
    CHECK(b.read(208,202,ariel::Direction::Vertical, 3) == "Fou");
    CHECK(b.read(208,202,ariel::Direction::Vertical, 11) == "Found a dog");
    b.post(200,200,ariel::Direction::Vertical,"House for sale");
    CHECK(b.read(200,200,ariel::Direction::Vertical, 9) == "House for");
    b.post(202,204,ariel::Direction::Horizontal, "bye");
    CHECK(b.read(202,204, ariel::Direction::Horizontal, 4) == "bye_");
    b.post(203,201,ariel::Direction::Horizontal, "Math lessons");
    CHECK(b.read(203,201, ariel::Direction::Horizontal, 3) == "Mat");
    b.post(205,200,ariel::Direction::Horizontal, "Amit");
    CHECK(b.read(205,200, ariel::Direction::Horizontal, 2) == "Am");
    CHECK(b.read(205,200, ariel::Direction::Horizontal, 5) == "Amit_");
    b.post(202,202,ariel::Direction::Vertical, "____");
    CHECK(b.read(202,202,ariel::Direction::Vertical, 4) == "____");
    CHECK(b.read(202,202,ariel::Direction::Vertical, 5) == "_____");
    CHECK(b.read(202,202,ariel::Direction::Vertical, 3) == "___");
    b.post(200,200,ariel::Direction::Vertical,"0507859677");
    CHECK(b.read(200,200,ariel::Direction::Vertical, 10) == "0507859677");
    b.post(204,204,ariel::Direction::Horizontal, "Good evening");
    CHECK(b.read(204,204, ariel::Direction::Horizontal, 5) == "Good ");
    CHECK(b.read(204,204, ariel::Direction::Horizontal, 8) == "Good eve");
    CHECK(b.read(204,204, ariel::Direction::Horizontal, 12) == "Good evening");
    CHECK(b.read(204,204, ariel::Direction::Horizontal, 13) == "Good evening_");
    b.post(205,205,ariel::Direction::Horizontal, "BMW 2020 for sale");
    CHECK(b.read(205,205, ariel::Direction::Horizontal, 12) == "BMW 2020 for");
    CHECK(b.read(205,205, ariel::Direction::Horizontal, 1) == "B");
}

TEST_CASE("Bad Board code") {
    CHECK_FALSE(b.read(205,205, ariel::Direction::Horizontal, 1) == "Bt");
    CHECK_FALSE(b.read(202,202,ariel::Direction::Vertical, 3) == "____");
    CHECK_FALSE(b.read(205,200, ariel::Direction::Horizontal, 5) == "Azit_");
    CHECK_FALSE(b.read(202,204, ariel::Direction::Horizontal, 6) == "bye_");
    CHECK_FALSE(b.read(101,7, ariel::Direction::Horizontal, 2) == "My_");
}


