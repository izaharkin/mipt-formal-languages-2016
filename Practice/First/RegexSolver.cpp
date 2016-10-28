//
// Created by ilya on 28.10.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#include "RegexSolver.h"

void RegexSolver::Input(istream &in_stream) {
  in_stream >> alpha_;
  in_stream >> k_ >> l_;
}

void RegexSolver::Run() {
  if (l_ >= k_) {
    answer_ = -1;
    return;
  }
  checker_.SetRegex(alpha_);
  checker_.SetRequiredL(l_);
  checker_.SetModule(k_);
  checker_.FindMinimalLength();
  answer_ = checker_.GetMinimalLength();
}

void RegexSolver::PrintAnswer(ostream &out_stream) {
  if (answer_ < 0) {
    out_stream << "INF";
  } else {
    out_stream << answer_;
  }
}
