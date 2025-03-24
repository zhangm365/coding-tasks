#include <ios>
#include <iostream>

#include "joiner.h"
#include "parser.h"
#include "optimizer.h"

#include <unordered_map>
#include <mutex>

int main(int argc, char *argv[]) {

    std::ios::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();


    Joiner joiner;

    // Read join relations
    std::string line;
    while (getline(std::cin, line)) {
        if (line == "Done") break;
        joiner.addRelation(line.c_str());
    }

    // Preparation phase (not timed)
    // Build histograms, indexes,...

    std::unordered_map<std::string, std::string> cache;
    Optimizer::preparation(joiner);

    QueryInfo i;
    while (getline(std::cin, line)) {
        if (line == "F") continue; // End of a batch
        i.parseQuery(line);
        std::cout << joiner.join(i);
    }

    return 0;
}
