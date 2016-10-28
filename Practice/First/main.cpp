#include <iostream>
#include <fstream>

#include "RegexSolver.h"

using std::cout;
using std::cin;

// @params alpha - given regular expression
//         l - required reminder
//         k - module
// @return n - minimal length of word, that is accepted by alpha
//              and n % k == l
int main() {
  RegexSolver solver;
  ifstream in_stream("input.txt");
  ofstream out_stream("output.txt");
  solver.Input(cin);
  solver.Run();
  solver.PrintAnswer(cout);
  return 0;
}