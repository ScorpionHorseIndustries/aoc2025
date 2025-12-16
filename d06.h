#pragma once

#include "common.h"
class D06b {
    public:
    char* data;

    void run() {
        loadData();
    }
    void loadData() {
        std::ifstream file;
        file.open("./input/d06.txt", std::ios::in | std::ios::binary);

        file.seekg(0, std::ios::end);

        size_t file_size_bytes = file.tellg();

        data = (char*) malloc(sizeof(char) * file_size_bytes);
        file.seekg(0,std::ios::beg);
        file.read(data, file_size_bytes);
        data[file_size_bytes] = '\0';
        file.close();
        std::printf("%s\n", data);

        
    }

};


class D06a {
    public:
    std::vector<std::string> data;
    int w = 0, h = 0;

    
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

    uint64_t op(uint64_t a, uint64_t b, char op) {
        if (op == '*') {
            return a * b;
        } else {
            return a + b;
        }
    }

    void run() {
        loadData();
        std::cout << "dims:(" << w << "," << h << ")\n";
        std::vector<uint64_t> nums;
        // char operator = '\0';
        uint64_t sum = 0;
        for (int x = 0; x < w; x += 1) {
            char optr = get(x,4)[0];
            
            uint64_t a = std::strtoimax(get(x,0).c_str(),NULL,10);
            a = op(a, std::strtoimax(get(x,1).c_str(),NULL,10),optr);
            a = op(a, std::strtoimax(get(x,2).c_str(),NULL,10),optr);
            a = op(a, std::strtoimax(get(x,3).c_str(),NULL,10),optr);
            sum += a;

            
        }

        std::cout << "sum : " << sum << "\n";
    }
    

    void loadData() {
        auto file = std::ifstream("./input/d06.txt");

        std::string line;
        
        bool first_row = true;
        h = 0;
        w = 0;
        
        while (std::getline(file,line)) {
            std::cout << "reading line " << h << "\n";
      
            h += 1;
            std::string current = "";
            for (size_t x = 0; x < line.length(); x += 1) {
                char c = line[x];
                if (c == ' ') {
                    if (current.length() > 0) {
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