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

#include <limits>

namespace score {
namespace component_example {

std::optional<std::int64_t> add(std::int64_t a, std::int64_t b) {
    std::int64_t result{};
    if (__builtin_add_overflow(a, b, &result)) {
        return std::nullopt;
    }
    return result;
}

std::optional<std::int64_t> subtract(std::int64_t a, std::int64_t b) {
    std::int64_t result{};
    if (__builtin_sub_overflow(a, b, &result)) {
        return std::nullopt;
    }
    return result;
}

std::optional<std::int64_t> multiply(std::int64_t a, std::int64_t b) {
    std::int64_t result{};
    if (__builtin_mul_overflow(a, b, &result)) {
        return std::nullopt;
    }
    return result;
}

std::optional<std::int64_t> divide(std::int64_t a, std::int64_t b) {
    // INT64_MIN / -1 does not fit into int64_t (undefined behavior).
    if ((b == 0) || ((a == std::numeric_limits<std::int64_t>::min()) && (b == -1))) {
        return std::nullopt;
    }
    return a / b;
}

std::optional<std::int64_t> multiply_add(std::int64_t a, std::int64_t b, std::int64_t c) {
    const auto product = multiply(a, b);
    if (!product.has_value()) {
        return std::nullopt;
    }
    return add(product.value(), c);
}

}  // namespace component_example
}  // namespace score
