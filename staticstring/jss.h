#pragma once

#include "staticstring.h"

namespace jss {

#define JSS(x) constexpr ::Json::StaticString x(#x)

    JSS(test);
}

