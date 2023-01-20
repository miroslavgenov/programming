#pragma once

enum GraphFlags : bool {
    empty = true,
    notEmpty = false,
    visited = true,
    notVisited = false,
    hasACycle = true,
    noCycle = false
};