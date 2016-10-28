//
// Created by ilya on 28.10.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#include "LengthItem.h"

LengthItem::LengthItem()
    : lengths_(0) {}

LengthItem::LengthItem(int size)
    : lengths_(size, make_pair(false, INF)) {}

int LengthItem::GetSize() const {
  return lengths_.size();
}

pair<bool, int> LengthItem::operator[](int index) const {
  return lengths_[index];
}

pair<bool, int> &LengthItem::operator[](int index) {
  return lengths_[index];
}