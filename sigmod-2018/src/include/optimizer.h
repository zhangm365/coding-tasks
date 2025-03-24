/**
 * @file optimizer.h
 * @author zhangm365
 * @date 2025-03-25
 * @brief 定义 Optimizer 类，用于优化查询计划。
 *
 * 该文件包含 Optimizer 类的声明，主要功能是为查询执行提供优化支持。
 * Optimizer 类通过与 Joiner 模块协作，完成查询计划的预处理和优化。
 */

#pragma once

#include <parser.h>
#include <joiner.h>
#include <map>

class Optimizer {
public:
    Optimizer() = default;
    ~Optimizer() = default;

    static void preparation(Joiner&);

private:

};