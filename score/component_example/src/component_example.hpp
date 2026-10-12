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
#ifndef SCORE_COMPONENT_EXAMPLE_COMPONENT_EXAMPLE_HPP_
#define SCORE_COMPONENT_EXAMPLE_COMPONENT_EXAMPLE_HPP_

#include <cstdint>
#include <optional>

namespace score {
namespace component_example {

// Units
// Each operation returns std::nullopt instead of overflowing or dividing by zero.
std::optional<std::int64_t> add(std::int64_t a, std::int64_t b);
std::optional<std::int64_t> subtract(std::int64_t a, std::int64_t b);
std::optional<std::int64_t> multiply(std::int64_t a, std::int64_t b);
std::optional<std::int64_t> divide(std::int64_t a, std::int64_t b);

// Component API
// Computes a * b + c; returns std::nullopt if any step overflows.
std::optional<std::int64_t> multiply_add(std::int64_t a, std::int64_t b, std::int64_t c);

}  // namespace component_example
}  // namespace score

#endif  // SCORE_COMPONENT_EXAMPLE_COMPONENT_EXAMPLE_HPP_
