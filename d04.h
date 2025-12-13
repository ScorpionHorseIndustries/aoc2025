#pragma once

#include "common.h"


class D04a {
    public:
  
    size_t w, h;
    char* data;

    bool oob(int x, int y) {
        return x < 0 || x >= w || y < 0 || y >= h;
    }

    int idx(int x, int y) {
        return y * w + x;
    }
    char get(int x, int y) {
        if (!oob(x,y)) {
            return data[idx(x,y)];
        } else {
            return 0;
        }
    }

    void run() {
        auto file = std::ifstream("./input/d04.txt");

        std::string line;
        std::vector<std::string> lines;

        while (std::getline(file,line)) {
            lines.push_back(line);
        }

        w = lines[0].length();
        h = lines.size();

        data = new char[w * h];

        for (int y = 0; y < lines.size(); y += 1) {
            auto& line = lines[y];
            for (int x = 0; x < line.length(); x += 1) {
                data[idx(x,y)] = line[x];
            }
        }
        int count_accessible = 0;
        for (int y = 0; y < h; y += 1) {
            for (int x = 0; x < w; x += 1) {
                char c = data[idx(x,y)];
                if (c != '@') continue;
                int count = 0;

                for (int yy = -1; yy <= 1; yy += 1) {
                    int py = y + yy;
                    for (int xx = -1; xx <= 1; xx += 1) {
                        int px = x + xx;

                        if (xx == 0 && yy == 0) continue;

                        if (!oob(px,py)) {
                            if (get(px,py) == '@') {
                                count += 1;
                            }
                        }
                    }
                }

                if (count < 4) {
                    count_accessible += 1;
                }

            }
            // std::cout << "\n";
        }

        std::cout << "count: " << count_accessible << "\n";

    }
};

class D04b {
    public:
  
    size_t w, h;
    char* data;

    bool oob(int x, int y) {
        return x < 0 || x >= w || y < 0 || y >= h;
    }

    int idx(int x, int y) {
        return y * w + x;
    }
    char get(int x, int y) {
        if (!oob(x,y)) {
            return data[idx(x,y)];
        } else {
            return 0;
        }
    }

    void set(int x, int y, char v) {
        if (!oob(x,y)) {
            data[idx(x,y)] = v;
        }
    }
    void loadData() {
        auto file = std::ifstream("./input/d04.txt");

        std::string line;
        std::vector<std::string> lines;

        while (std::getline(file,line)) {
            lines.push_back(line);
        }

        w = lines[0].length();
        h = lines.size();

        data = new char[w * h];

        for (int y = 0; y < lines.size(); y += 1) {
            auto& line = lines[y];
            for (int x = 0; x < line.length(); x += 1) {
                data[idx(x,y)] = line[x];
            }
        }
    }
    void run() {
        loadData();
    
        int last_count_accessible = -1;
        int count_accessible = 0;
        int count_removed = 0;
        int iterations = 0;
        int count_removed_this_time = 1;
        while (count_removed_this_time > 0) {
 
            count_removed_this_time = 0;
            iterations += 1;
            for (int y = 0; y < h; y += 1) {
                for (int x = 0; x < w; x += 1) {
                    char c = data[idx(x,y)];
                    if (c != '@') continue;
                    int count = 0;

                    for (int yy = -1; yy <= 1; yy += 1) {
                        int py = y + yy;
                        for (int xx = -1; xx <= 1; xx += 1) {
                            int px = x + xx;

                            if (xx == 0 && yy == 0) continue;

                            if (!oob(px,py)) {
                                if (get(px,py) == '@') {
                                    count += 1;
                                }
                            }
                        }
                    }

                    if (count < 4) {
                        set(x,y,'.');
                        count_removed += 1;
                        count_removed_this_time += 1;
                    }

                }
                // std::cout << "\n";
            }

        }

        std::cout << "count: " << count_accessible << "\n";
        std::cout << "removed: " << count_removed << "\n";
        std::cout << "iterations: " << iterations << "\n";
        // }
    }
};