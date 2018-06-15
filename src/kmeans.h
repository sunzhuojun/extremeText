/**
 * Copyright (c) 2018 by Marek Wydmuch
 * All rights reserved.
 */

#pragma once

#include <vector>
#include "smatrix.h"

namespace fasttext {

struct Assignation{
  int index;
  int value;

  bool operator<(const Assignation& r) const { return value < r.value; }
  bool operator>(const Assignation& r) const { return value > r.value; }
};

// (Heuristic) Balanced K-Means clustering
struct Distances{
    int index;
    std::vector<Feature> values;

    bool operator<(const Distances &r) const { return values[0].value < r.values[0].value; }
};

// Partition is returned via reference, calculated for cosine distance
void kMeans(std::vector<Assignation>* partition, SRMatrix<Feature>& pointsFeatures,
                    int centroids, double eps, bool balanced, int seed);

}