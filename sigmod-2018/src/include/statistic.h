#pragma once

#include <cstdint>
#include <map>

class ColumnStatistics {

public :
    // histograms
    std::map<uint64_t, uint64_t> histograms;

    uint64_t GetGreaterCount(uint64_t constant);

    uint64_t GetLessCount(uint64_t constant);

    ColumnStatistics(uint64_t maxx, uint64_t minn, uint64_t ndv, uint64_t alike, uint64_t rowcount)
            : max_val_(maxx), min_val_(minn), ndv_(ndv), alike_(alike),row_count_(rowcount) {}

private:
    uint64_t estimated_size_;
    // uint64_t max_count_;
    uint64_t step_;

    uint64_t max_val_;
    uint64_t min_val_;

    uint64_t ndv_;
    uint64_t alike_;

    uint64_t row_count_;
};
