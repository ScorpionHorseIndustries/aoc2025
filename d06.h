#pragma once

#include "common.h"

class D06a {
    public:
    std::vector<std::string> data;
    int w, h;

    
    bool oob(int x, int y) {
        return x < 0 || x >= w ||y < 0 || y >= h;
    }

    size_t idx(int x, int y) {
        return y * w + x;
    }
    std::string get(int x, int y) {
        if (!oob(x,y)) {
            return data[idx(x,y)];
        } else {
            return " ";
        }
    }

    void run() {
        loadData();
        std::cout << "dims:(" << w << "," << h << ")\n";
        for (int y = 0; y < h; y += 1) {

            for (int x = 0; x < w; x += 1) {
                std::cout << " " << get(x,y) ;       
            }
            std::cout << "\n";
        }
    }
    

    void loadData() {
        auto file = std::ifstream("./input/d06.txt");

        std::string line;
        
        bool first_row = true;
        h = 0;
        while (std::getline(file,line)) {
            h =+ 1;
            std::string current = "";
            for (size_t x = 0; x < line.length(); x += 1) {
                char c = line[x];
                if (c == ' ') {
                    if (current.length() > 0 || x == line.length()-1) {
                        data.push_back(current);
                        current =  "";
                    }
                } else {
                    current += c;
                }


            }
            if (current.length() > 0) {
                data.push_back(current);
            }


            if (first_row) {
                first_row = false;
                w = data.size();
            }
        }

        
    }
};