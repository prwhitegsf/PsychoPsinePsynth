/*
  ==============================================================================

    Filter.cpp
    Created: 16 Jan 2026 10:43:57am
    Author:  User

  ==============================================================================
*/

#include "Filter.h"

float Filter::getNextSample(float sample)
{
      updateSmoothers();

      return processSample(sample, 0);
}

