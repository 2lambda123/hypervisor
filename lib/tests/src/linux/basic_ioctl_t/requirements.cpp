/// @copyright
/// Copyright (C) 2020 Assured Information Security, Inc.
///
/// @copyright
/// Permission is hereby granted, free of charge, to any person obtaining a copy
/// of this software and associated documentation files (the "Software"), to deal
/// in the Software without restriction, including without limitation the rights
/// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
/// copies of the Software, and to permit persons to whom the Software is
/// furnished to do so, subject to the following conditions:
///
/// @copyright
/// The above copyright notice and this permission notice shall be included in
/// all copies or substantial portions of the Software.
///
/// @copyright
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
/// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
/// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
/// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
/// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
/// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
/// SOFTWARE.

#include "../../../../src/linux/basic_ioctl_t.hpp"

#include <bsl/safe_integral.hpp>
#include <bsl/ut.hpp>

/// <!-- description -->
///   @brief Main function for this unit test. If a call to bsl::ut_check() fails
///     the application will fast fail. If all calls to bsl::ut_check() pass, this
///     function will successfully return with bsl::exit_success.
///
/// <!-- inputs/outputs -->
///   @return Always returns bsl::exit_success.
///
[[nodiscard]] auto
main() noexcept -> bsl::exit_code
{
    bsl::ut_scenario{"verify noexcept"} = []() noexcept {
        bsl::ut_given{} = []() noexcept {
            lib::basic_ioctl_t mut_ioctl{};
            lib::basic_ioctl_t const ioctl{};
            bsl::safe_i64 mut_data{};
            bsl::ut_then{} = []() noexcept {
                static_assert(noexcept(lib::basic_ioctl_t{}));
                static_assert(noexcept(lib::basic_ioctl_t{""}));
                static_assert(noexcept(lib::basic_ioctl_t{bsl::safe_i32::magic_1()}));

                static_assert(noexcept(mut_ioctl.close()));
                static_assert(noexcept(mut_ioctl.is_open()));
                static_assert(noexcept(mut_ioctl.send({})));
                static_assert(noexcept(mut_ioctl.read({}, mut_data.data())));
                static_assert(noexcept(mut_ioctl.write({}, mut_data.data())));
                static_assert(noexcept(mut_ioctl.write({}, mut_data)));
                static_assert(noexcept(mut_ioctl.read_write({}, mut_data.data())));

                static_assert(noexcept(ioctl.is_open()));
                static_assert(noexcept(ioctl.send({})));
                static_assert(noexcept(ioctl.read({}, mut_data.data())));
            };
        };
    };

    return bsl::ut_success();
}
