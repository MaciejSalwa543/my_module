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

// Component Integration Test (CIT) for component_example component.
TEST(ComponentExampleTest, MultiplyAddReturnsExpectedResult) {
    EXPECT_EQ(multiply_add(6, 7, 0), 42);
    EXPECT_EQ(multiply_add(2, 3, 4), 10);
    EXPECT_EQ(multiply_add(-2, 3, 10), 4);
}

TEST(ComponentExampleTest, MultiplyAddPropagatesMultiplyOverflow) {
    EXPECT_EQ(multiply_add(std::numeric_limits<std::int64_t>::max(), 2, 0), std::nullopt);
}

TEST(ComponentExampleTest, MultiplyAddPropagatesAddOverflow) {
    EXPECT_EQ(multiply_add(std::numeric_limits<std::int64_t>::max(), 1, 1), std::nullopt);
}

}  // namespace component_example
}  // namespace score
