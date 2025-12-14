#pragma once

#include "common.h"


class D05b {
   public:

    typedef std::pair<uint64_t, uint64_t> uintpair;

    typedef std::set<uintpair> uintpairset;
    uintpairset ranges;


    bool pairs_overlap(const uintpair& a, const uintpair& b) {
        return 
            (a.first >= b.first && a.first <= b.second) ||
            (a.second >= b.first && a.second <= b.second) ||
            (b.first >= a.first && b.first <= a.second) ||
            (b.second >= a.first && b.second <= a.second) ||
            (a.first < b.first && a.second > b.second) ||
            (b.first < a.first && b.second > a.second);
     }

    void run() {
        loadData();

        // uintpairset::reverse_iterator reverse_a;
        // uintpairset::reverse_iterator reverse_b;
        bool no_overlaps = false;
        while (!no_overlaps) {

            uintpairset to_remove;
            uintpairset to_add;
            no_overlaps = true;
            for (auto iter_a = ranges.begin(); iter_a != ranges.end(); iter_a++) {
                // ranges.remo
                uintpair a = *iter_a;
                // std::cout << a.first << "-" << a.second << "\n";

                for (auto iter_b = ranges.begin(); iter_b != ranges.end(); iter_b++) {
                    if (iter_a == iter_b) continue;
                    uintpair b = *iter_b;

                    if (pairs_overlap(a, b)) {

                    

                        
                        
                        no_overlaps = false;
                        uintpair c{ std::min(a.first, b.first), std::max(a.second,b.second)};
                        to_add.insert(c);
                        to_remove.insert(a);
                        to_remove.insert(b);
                        // std::cout << "overlap " << a.first << "-" << a.second <<
                        //     " & " << b.first << "-" << b.second << "\n" <<
                        //     "\t\tnew range: " << c.first << "-" << c.second << "\n";
                        break;


                    }
                }
                if (!no_overlaps) break;
            }
            // std::cout << "removing...\n";
            for (auto remove_iter = to_remove.begin(); remove_iter != to_remove.end(); remove_iter++) {
                // std::cout << "removing " << remove_iter->first << "-" << remove_iter->second << "\n";
                uintpair v = *remove_iter;
                if (ranges.contains(v)) {

                    ranges.erase(v);
                }
            }
            // std::cout << "adding...\n";
            for (auto add_iter = to_add.begin(); add_iter != to_add.end(); add_iter++) {
                // std::cout << "adding " << add_iter->first << "\n";
                uintpair a = *add_iter;
                ranges.insert(a);
            }

            
        }

        uint64_t count = 0;
        for (auto iter_a = ranges.begin(); iter_a != ranges.end(); iter_a++) {
            count += 1 + (iter_a->second - iter_a->first);
        }

        std::cout << "count of fresh: " << count << "\n";
    }

    void loadData() {
        auto file = std::ifstream("./input/d05.txt");

        std::string line;
        

        while (std::getline(file,line)) {
            
            if (line.length() == 0) continue;
            std::string from, to;
            size_t pos = line.find('-');

            if (pos != std::string::npos) {

                from = line.substr(0,pos);
                to = line.substr(pos+1);
                // std::cout << from << " " << to << "\n";
                try {
                    uint64_t a = std::strtoimax(from.c_str(), NULL, 10);
                    uint64_t b = std::strtoimax(to.c_str(), NULL, 10);

                    uintpair v {a,b};
                    uint64_t count = 1 + (b - a);

                    ranges.insert(v);

                    // std::cout << from << " " << a << " " << to << " " << b << "\n";
                    
                } catch (std::exception exp) {
                    std::cout << exp.what() << " " << from << " " << to << "\n";

                }
            
            } else {
                // ids_to_check.insert(std::strtoimax(line.c_str(), NULL, 10));
            }

        }


        file.close();



    }
};
class D05a {
    public:
        std::map<uint64_t, uint64_t> range_lookup;
        std::set<uint64_t> ids_to_check;
        

        void run() {
            // ids_to_check.reserve(1000);
            loadData();
            std::printf("number of ranges: %d\nnumber of ids: %d", range_lookup.size(), ids_to_check.size());
            // for (auto kv = range_lookup.begin(); kv != range_lookup.end(); kv++) {
            //     std::cout << kv->first << "-" << kv->second << "\n";
            // }
  
            
            bool read_mode = false;
            int count_fresh = 0;
            int count_reads = 0;
            for (auto const& id : ids_to_check) {
                    
                bool found = false;
                for (auto const& kv : range_lookup) {
                    if (id >= kv.first && id <= kv.second) {
                        if (count_fresh == 0 || count_reads == 0 || count_reads % 100 == 0) {
                            std::cout << count_reads << " #: " << id << " found in range(" << kv.first << "," << kv.second << ")\n";

                        }
                        
                        count_fresh += 1;
                        found = true;
                        break;
                    } 
                }
                count_reads += 1;

                    // if (!found) {
                    //     std::cout << "not fresh " << check << "\n";
                    // }
                
            }   
            // file.close();
            std::cout << "counted: " << count_reads << " count fresh: " << count_fresh << "\n";

            // for (auto iter = ranges.begin(); iter != ranges.end(); iter++) {
            //     // std::printf("%d %d\n",iter->first, iter->second);
            // }   
        }


        void loadData() {
            auto file = std::ifstream("./input/d05.txt");

            std::string line;
            

            while (std::getline(file,line)) {
                
                if (line.length() == 0) continue;
                std::string from, to;
                size_t pos = line.find('-');

                if (pos != std::string::npos) {

                    from = line.substr(0,pos);
                    to = line.substr(pos+1);
                    // std::cout << from << " " << to << "\n";
                    try {
                        uint64_t a = std::strtoimax(from.c_str(), NULL, 10);
                        uint64_t b = std::strtoimax(to.c_str(), NULL, 10);

                    
                        if (range_lookup.contains(a)) {
                            if (b > range_lookup[a]) {
                                range_lookup[a] =  b;
                            }
                        } else {
                            range_lookup[a] = b;
                        }
                        // std::cout << from << " " << a << " " << to << " " << b << "\n";
                        
                    } catch (std::exception exp) {
                        std::cout << exp.what() << " " << from << " " << to << "\n";

                    }
                
                } else {
                    ids_to_check.insert(std::strtoimax(line.c_str(), NULL, 10));
                }

            }


            file.close();



        }
};