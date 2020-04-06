//
//  TestMacros.hpp
//  6502-emulator
//
//  Created by Rakesh Ayyaswami on 04 Apr 2020.
//  Copyright (c) 2020 Rakesh Ayyaswami. All rights reserved.
//

#ifndef __TEST_MACROS_HPP__
#define __TEST_MACROS_HPP__

#include <stdio.h>

#define RunTestSuite(name) \
    extern void _run_##name(); _run_##name();

#define TestSuite(name, block) \
    void _run_##name() { \
        printf("\n[SUITE] ------- %s -------\n", #name); \
        block \
    }

#define TestSetUp(block) \
    void _setup_() block

#define TestTearDown(block) \
    void _teardown_() block \

#define TestCase(name, label, block) \
    bool __block__test__##name() { \
        block \
        return true; \
    } \
    void test_##name() { \
        printf("[START] %s\n", label); \
        _setup_(); \
        bool pass = __block__test__##name(); \
        _teardown_(); \
        if (pass) { \
            printf("[ PASS] %s\n", label); \
        } \
        else { \
            printf("[ FAIL] %s\n", label); \
        } \
    }


#define TestAssert(condition, message, ...) \
    if (!(condition)) { \
        printf("Assertion Failure: "); \
        printf((message), ##__VA_ARGS__); \
        printf("\n    in %s:%d\n", __FILE__, __LINE__); \
        return false; \
    }


#endif // __TEST_MACROS_HPP__
