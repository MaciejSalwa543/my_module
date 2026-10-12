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

namespace score {
namespace component_example {

// Module-level tests (e.g. feature integration tests)
// Only one component in this example.
TEST(ComponentExampleTest, CalculatorScenarioProducesExpectedResult) {
    // (10 + 5) * 4 - 20 = 40, then 40 / 8 = 5
    const auto sum = add(10, 5);
    ASSERT_TRUE(sum.has_value());
    const auto value = multiply_add(sum.value(), 4, -20);
    ASSERT_TRUE(value.has_value());
    EXPECT_EQ(divide(value.value(), 8), 5);
}

TEST(ComponentExampleTest, CalculatorScenarioReportsDivisionByZero) {
    const auto difference = subtract(3, 3);
    ASSERT_TRUE(difference.has_value());
    EXPECT_EQ(divide(100, difference.value()), std::nullopt);
}

}  // namespace component_example
}  // namespace score
