//
// Created by ilya on 28.10.16.
// Copyright (c) 2016, ilya. All rights reserved.
//

#include "Analyzer.h"

void Analyzer::SetRequiredL(int l) {
  l_ = l;
}

void Analyzer::SetModule(int k) {
  k_ = k;
}

void Analyzer::SetRegex(string alpha) {
  alpha_ = alpha;
}

LengthItem plus(const LengthItem &len1, const LengthItem &len2) {
  LengthItem new_len_item(len1.GetSize());
  for (int i = 0; i < len1.GetSize(); ++i) {
    new_len_item[i] = make_pair(len1[i].first || len2[i].first, min(len1[i].second, len2[i].second));
  }
  return new_len_item;
}

LengthItem dot(const LengthItem &len1, const LengthItem &len2) {
  LengthItem new_len_item(len1.GetSize());
  int mod = len1.GetSize();
  for (int i = 0; i < len2.GetSize(); ++i) {
    if (len2[i].first) {
      for (int j = 0; j < len1.GetSize(); ++j) {
        if (len1[j].first) {
          new_len_item[(i + j) % mod].first = true;
          new_len_item[(i + j) % mod].second = min(len1[j].second + len2[i].second, new_len_item[(i + j) % mod].second);
        }
      }
    }
  }
  return new_len_item;
}

void LengthItem::asterisk() {
  int mod = this->lengths_.size();
  for (int i = 0; i < this->lengths_.size(); ++i) {
    if (lengths_[i].first) {
      int rem = (i + i) % mod;
      int cur_len = lengths_[i].second;
      while (rem != i && cur_len + lengths_[i].second < lengths_[rem].second) {
        lengths_[rem].first = true;
        lengths_[rem].second = cur_len + lengths_[i].second;
        cur_len += lengths_[i].second;
        rem = (rem + i) % mod;
      }
    }
  }
  lengths_[0].first = true;
  lengths_[0].second = 0;
}

void Analyzer::FindMinimalLength() {
  const unordered_set<char> ALPHABET = {'a', 'b', 'c'};
  stack<LengthItem> len_stack;
  for (const auto &letter : alpha_) {
    if (ALPHABET.find(letter) != ALPHABET.end()) {
      LengthItem item(k_);
      item[1].first = 1;
      item[1].second = 1;
      len_stack.push(item);
    } else if (letter == '1') {
      LengthItem item(k_);
      item[0].first = 1;
      item[0].second = 0;
      len_stack.push(item);
    } else if (letter == '+') {
      if (len_stack.size() >= 2) {
        LengthItem operand2 = len_stack.top();
        len_stack.pop();
        LengthItem operand1 = len_stack.top();
        len_stack.pop();
        LengthItem new_len_item = plus(operand1, operand2);
        len_stack.push(new_len_item);
      } else {
        result_ = -1;
        break;
      }
    } else if (letter == '.') {
      if (len_stack.size() >= 2) {
        LengthItem operand2 = len_stack.top();
        len_stack.pop();
        LengthItem operand1 = len_stack.top();
        len_stack.pop();
        LengthItem new_len_item = dot(operand1, operand2);
        len_stack.push(new_len_item);
      } else {
        result_ = -1;
        break;
      }
    } else if (letter == '*') {
      LengthItem top_item = len_stack.top();
      len_stack.pop();
      top_item.asterisk();
      len_stack.push(top_item);
    } else { // incorrect alpha
      result_ = -1;
      break;
    }
  }
  if (len_stack.size() == 1) {
    LengthItem cur_length = len_stack.top();
    if (cur_length[l_].first) {
      result_ = cur_length[l_].second;
    } else {
      result_ = -1;
    }
  } else {
    result_ = -1;
  }
}

int Analyzer::GetMinimalLength() const {
  return result_;
}