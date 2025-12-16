#pragma once
#include "common.h"

namespace AOC {
    class D01a {
        public:
        static const int RANGE_LOW = 0;
        static const int RANGE_HIGH = 100;
        static const int RANGE = RANGE_HIGH - RANGE_LOW;
        int v;
        int counter;
        static int p_add(int a, int b) {
            int c = a + b;
            while (c < RANGE_LOW) c += RANGE;
            while (c >= RANGE_HIGH) c-= RANGE;

            return c;
        }

        static int p_sub(int a, int b) {
            return p_add(a, -b);
        }

        void run() {
            auto file = std::ifstream("input/d01.txt");
            std::string line;
            v = 50;
            counter = 0;
            while (std::getline(file, line)) {
                char d = line[0];
                int  k = std::atoi(line.substr(1).c_str());
                if (line[0] == 'L') {
                    
                    v = p_sub(v, k);
                } else {
                    v = p_add(v, k);
                }

                if (v == 0) {
                    counter += 1;
                }
            }

            std::cout << "counter: " << counter << "\n";
            
        }


    };

        class D01b {
        public:
        static const int RANGE_LOW = 0;
        static const int RANGE_HIGH = 100;
        static const int RANGE = RANGE_HIGH - RANGE_LOW;
        int v;
        int counter;
        static int p_add(int a, int b, int* counter) {
            int c = a + b;
            int end = c;
            int start = a;
            int current = a;

       

            while (c < RANGE_LOW) {
                c += RANGE;
                // *counter += 1;
            }
            while (c >= RANGE_HIGH){
                c-= RANGE;
                // *counter += 1;
            }    

            while (current != end) {
                if (end < current) {
                    current -= 1;
                } else if (end > current) {
                    current += 1;
                }

                if (current == 0 || current % RANGE_HIGH == 0) {
                    *counter += 1;
                }
            }




            return c;
        }

        static int p_sub(int a, int b, int* counter) {
            return p_add(a, -b, counter);
        }

        void run() {
            auto file = std::ifstream("input/d01.txt");
            std::string line;
            v = 50;
            counter = 0;
            while (std::getline(file, line)) {
                char d = line[0];
                int  k = std::atoi(line.substr(1).c_str());
                if (line[0] == 'L') {
                    
                    v = p_sub(v, k, &counter);
                } else {
                    v = p_add(v, k, &counter);
                }


            }

            std::cout << "counter: " << counter << "\n";
            
        }


    };
}