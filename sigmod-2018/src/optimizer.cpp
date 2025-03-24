/**
 * @file optimizer.h
 * @author zhangm365
 * @date 2025-03-25
 * @brief 定义 Optimizer 类，用于优化查询计划。
 *
 */
 #include "optimizer.h"

void Optimizer::preparation(Joiner& joiner) {
    // Make statistical data for relations
    for (auto& relation: joiner.getRelations()) {
        for (auto& col: relation.columns()) {
            // sort key
            std::map<uint64_t, uint64_t> mp_count;
            for (uint64_t i = 0; i < relation.size(); ++i) {
                mp_count[col[i]]++;
            }

            auto min_col = mp_count.begin()->first;
            auto max_col = mp_count.rbegin()->first;
            auto alike = std::max_element(mp_count.begin(), mp_count.end(), [](auto &lhs, auto &rhs) -> bool {
                return lhs.second < rhs.second;
            })->second;

            auto ndv = mp_count.size();
            relation.statistics.emplace_back(max_col, min_col, ndv, alike, relation.size());

        }

    }
}
