/********************************************************************************
 * Copyright (c) 2026 Contributors to the Eclipse Foundation
 *
 * See the NOTICE file(s) distributed with this work for additional
 * information regarding copyright ownership.
 *
 * This program and the accompanying materials are made available under the
 * terms of the Apache License Version 2.0 which is available at
 * https://www.apache.org/licenses/LICENSE-2.0
 *
 * SPDX-License-Identifier: Apache-2.0
 ********************************************************************************/

#include "score/component_example/src/component_example.hpp"

#include <gtest/gtest.h>
#include <cstdint>
#include <limits>

namespace score {
namespace component_example {
namespace {

constexpr std::int64_t kMax = std::numeric_limits<std::int64_t>::max();
constexpr std::int64_t kMin = std::numeric_limits<std::int64_t>::min();

}  // namespace

// Unit tests for add()
TEST(ComponentExampleTest, AddReturnsSum) {
    EXPECT_EQ(add(2, 3), 5);
    EXPECT_EQ(add(-7, 4), -3);
}

TEST(ComponentExampleTest, AddReturnsNulloptOnOverflow) {
    EXPECT_EQ(add(kMax, 1), std::nullopt);
    EXPECT_EQ(add(kMin, -1), std::nullopt);
}

// Unit tests for subtract()
TEST(ComponentExampleTest, SubtractReturnsDifference) {
    EXPECT_EQ(subtract(10, 4), 6);
    EXPECT_EQ(subtract(4, 10), -6);
}

TEST(ComponentExampleTest, SubtractReturnsNulloptOnOverflow) {
    EXPECT_EQ(subtract(kMin, 1), std::nullopt);
    EXPECT_EQ(subtract(kMax, -1), std::nullopt);
}

// Unit tests for multiply()
TEST(ComponentExampleTest, MultiplyReturnsProduct) {
    EXPECT_EQ(multiply(6, 7), 42);
    EXPECT_EQ(multiply(-3, 5), -15);
    EXPECT_EQ(multiply(kMax, 0), 0);
}

TEST(ComponentExampleTest, MultiplyReturnsNulloptOnOverflow) {
    EXPECT_EQ(multiply(kMax, 2), std::nullopt);
    EXPECT_EQ(multiply(kMin, -1), std::nullopt);
}

// Unit tests for divide()
TEST(ComponentExampleTest, DivideReturnsQuotient) {
    EXPECT_EQ(divide(42, 6), 7);
    EXPECT_EQ(divide(7, 2), 3);
    EXPECT_EQ(divide(-7, 2), -3);
}

TEST(ComponentExampleTest, DivideReturnsNulloptOnDivisionByZero) {
    EXPECT_EQ(divide(1, 0), std::nullopt);
}

TEST(ComponentExampleTest, DivideReturnsNulloptOnMinDividedByMinusOne) {
    EXPECT_EQ(divide(kMin, -1), std::nullopt);
}

}  // namespace component_example
}  // namespace score
