#pragma once
#include "common.h"

namespace AOC {
    class D03a {
        public:


        void run() {

            auto file = std::ifstream("./input/d03.txt");
            std::string line;
            uint64_t sum = 0;   
            while (std::getline(file,line)) {

                char highest = 0;
                size_t highest_pos = 0;
                
                for (size_t i = 0; i < line.length()-1; i += 1) {
                    if (static_cast<int>(line[i]) > static_cast<int>(highest)) {
                        highest = line[i];
                        highest_pos = i;

                    }
                    if (highest == '9') break;
                }
                char second_digit = '0';
                for (size_t i = highest_pos + 1; i < line.length(); i += 1) {
                    if (line[i] > second_digit) {
                        second_digit = line[i];
                    }

                    if (second_digit == '9') {
                        break;
                    }
                }

                std::string joltage = "";
                joltage += highest;
                joltage += second_digit;
                
                sum += (highest - 48) * 10;
                sum += (second_digit - 48);
                std::println("{0} {1}{2} {3} sum({4})", line, highest, second_digit,joltage, sum);





            }
            std::println("total joltage: {0}", sum);

            

        }

    };
    
    class D03b {
        public:

        

        void run() {

            auto file = std::ifstream("./input/d03.txt");
            std::string line;
            uint64_t sum = 0;   
            while (std::getline(file,line)) {

                char highest = 0;
                size_t highest_pos = 0;
                
                for (size_t i = 0; i < line.length()-1; i += 1) {
                    if (static_cast<int>(line[i]) > static_cast<int>(highest)) {
                        highest = line[i];
                        highest_pos = i;

                    }
                    if (highest == '9') break;
                }
                char second_digit = '0';
                for (size_t i = highest_pos + 1; i < line.length(); i += 1) {
                    if (line[i] > second_digit) {
                        second_digit = line[i];
                    }

                    if (second_digit == '9') {
                        break;
                    }
                }

                std::string joltage = "";
                joltage += highest;
                joltage += second_digit;
                
                sum += (highest - 48) * 10;
                sum += (second_digit - 48);
                std::println("{0} {1}{2} {3} sum({4})", line, highest, second_digit,joltage, sum);





            }
            std::println("total joltage: {0}", sum);

            

        }

    };
}