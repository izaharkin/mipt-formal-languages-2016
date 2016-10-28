//
// Created by ilya on 28.10.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#ifndef FIRST_LENGTHITEM_H
#define FIRST_LENGTHITEM_H

#include <unordered_set>
#include <stdint.h>
#include <vector>

using std::make_pair;
using std::vector;
using std::pair;

const int INF = INT32_MAX;

class LengthItem {
 public:
  LengthItem();
  LengthItem(int size);
  int GetSize() const;
  void asterisk();
  pair<bool, int> operator[](int index) const;
  pair<bool, int> &operator[](int index);
 private:
  vector<pair<bool, int>> lengths_;
};

#endif //FIRST_LENGTHITEM_H
