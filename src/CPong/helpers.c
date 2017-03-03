#include "helpers.h"
#pragma once

coerce_value(int *result, int min, int max)
{
    int value = *result;
    if (value < min)
    {
        *result = min;
    }

    if (value > max)
    {
        *result = max;
    }
}