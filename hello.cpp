/* hello.cpp
 */

#include <cassert>
#include <iostream>
#include "TimeSpan.h"

const TimeSpan ONE_MINUTE = TimeSpan(60.0_s);

int main()
{
    std::cout << "Hello, world!" << std::endl;

    const auto t1 = TimeSpan(1000.0_ms);
    const auto t2 = TimeSpan(2000.0_ms);
    std::cout << "t1 + t2 = " << (t1 + t2).Sec() << " s" << std::endl;

    (void)ONE_MINUTE;
    return 0;
}
