#pragma once
#include <string>
#include <iostream>
#include <algorithm> 
#include <random>
#include <ctime>
extern void check_int(int&num); //use extern to get this void to another cpp
int loop_checkint(std::string& string_loop);
extern void lower(std::string& l_string);
extern float randomChance();
extern int randomMove();
extern bool alert(std::string currentstate, std::string destinationstate);
extern void pause();