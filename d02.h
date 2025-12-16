#pragma once
#include "common.h"

namespace AOC {
    class D02a {
        public:


        void run() {

            auto file = std::ifstream("./input/d02a.txt");
            std::string line;
            uint64_t sum = 0;   
            while (std::getline(file,line,',')) {
                int pos = line.find('-');
                std::string a = line.substr(0,pos);
                std::string b = line.substr(pos+1);


                

                uint64_t an = std::atol(a.c_str());
                uint64_t bn = std::atol(b.c_str());

                uint64_t start = std::min(an,bn);
                uint64_t end   = std::max(an,bn);
                
                
                uint64_t count = 0;
                std::println("Check {0} to {1}", start, end);
                for (uint64_t k = start; k <= end; k += 1) {
                    // std::println("    {0}", k);
                    count += 1;
                    std::string x = std::to_string(k);
                    bool matching = false;
                    // if (x.length() % 2 == 1) continue;
                    for (size_t len = 1; len < x.length(); len += 1) {

                    
                        // size_t len = x.length() / 2;
                        
                        std::string chunk = x.substr(0,len);
                        matching = true;
                        
                        for (size_t pos = 0; pos < x.length(); pos += len) {
                            if (chunk.compare(x.substr(pos,len)) != 0) {
                                matching = false;
                                break;
                            }

                        }

                        if (matching) {
                            std::println("   {0} is invalid",k);
                            sum += k;
                            break;
                        }
                    }
                    
                    // std::println("{0}",x);
                    // break;
                }
                
                // 
// 

            }
            std::println("Sum : {0}",sum);

        }

    };
}