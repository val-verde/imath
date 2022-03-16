//
// SPDX-License-Identifier: BSD-3-Clause
// Copyright Contributors to the OpenEXR Project.
//

#ifndef INCLUDED_HALF_LIMITS_H
#define INCLUDED_HALF_LIMITS_H

//
// This file is now deprecated. It previously included the
// specialization of std::numeric_limits<half>, but those now appear
// directly in half.h, because they should be regarded as inseperable
// from the half class.
//

#warning "ImathLimits is deprecated; use #include <half.h>"

#include "half.h"

#endif
