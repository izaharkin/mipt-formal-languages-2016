//
// Created by ilya on 28.10.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#ifndef FIRST_ANALYZER_H
#define FIRST_ANALYZER_H

#include <unordered_set>
#include <string>
#include <stack>

#include "LengthItem.h"

using std::unordered_set;
using std::string;
using std::stack;
using std::min;

class Analyzer {
 public:
  void SetRequiredL(int l);
  void SetModule(int k);
  void SetRegex(string alpha);
  void FindMinimalLength();
  int GetMinimalLength() const;
 private:
  string alpha_;
  int l_;
  int k_;
  int result_;
};


#endif //FIRST_ANALYZER_H
