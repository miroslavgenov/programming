#pragma once

enum GraphFlags : bool {
    empty = true,
    notEmpty = false,
    visited = true,
    notVisited = false,
    allVerticiesAreNotVisited = false,
    allVerticiesAreVisited = true,
    hasACycle = true,
    hasNoCycle = false
};