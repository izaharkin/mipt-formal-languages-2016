//
// Created by ilya on 28.10.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#ifndef FIRST_REGEXSOLVER_H
#define FIRST_REGEXSOLVER_H

#include <iostream>
#include <fstream>

#include "Analyzer.h"

using std::ifstream;
using std::ofstream;
using std::istream;
using std::ostream;

class RegexSolver {
 public:
  void Input(istream &in_stream);
  void Run();
  void PrintAnswer(ostream &out_stream);
 private:
  Analyzer checker_;
  string alpha_;
  int answer_; // == -1 if alpha_ is incorrect
  int l_;
  int k_;
};

#endif //FIRST_REGEXSOLVER_H
