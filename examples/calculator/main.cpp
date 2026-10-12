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

#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <optional>
#include <string>

namespace {

// Prints one operation and checks it against the expected result.
bool check(const std::string& expression,
           const std::optional<std::int64_t>& actual,
           const std::optional<std::int64_t>& expected) {
    std::cout << expression << " = ";
    if (actual.has_value()) {
        std::cout << actual.value();
    } else {
        std::cout << "error";
    }
    const bool ok = (actual == expected);
    std::cout << (ok ? "  [OK]" : "  [UNEXPECTED]") << '\n';
    return ok;
}

}  // namespace

int main() {
    using namespace score::component_example;

    std::cout << "my_module calculator example\n";

    bool ok = true;
    ok &= check("add(2, 3)", add(2, 3), 5);
    ok &= check("subtract(10, 4)", subtract(10, 4), 6);
    ok &= check("multiply(6, 7)", multiply(6, 7), 42);
    ok &= check("divide(42, 6)", divide(42, 6), 7);
    ok &= check("multiply_add(2, 3, 4)", multiply_add(2, 3, 4), 10);
    ok &= check("divide(1, 0)", divide(1, 0), std::nullopt);

    std::cout << (ok ? "All operations succeeded\n" : "Some operations failed\n");
    return ok ? EXIT_SUCCESS : EXIT_FAILURE;
}
