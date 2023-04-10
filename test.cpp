#include "BasicString.h"
#include <utility>

using basicstring::BasicString;

int main() {
  BasicString a{100};
  a.append_line("Hello there!");
  a.print("a");

  // Copy assignment
  BasicString b{50};
  b.append_line("General Kenobi...");
  b.print("b");

  b = a;
  a.print("a");
  b.print("b");

  // Copy constructor
  //   BasicString b{a};
  //   b.print("b");
  //   a.print("a");

  // Move constructor
  //   BasicString b{std::move(a)};
  //   b.print("b");
  //   // undefined behavior after move
  //   a.print("a");

  // Move assignment
  //   BasicString b{50};
  //   b.append_line("General Kenobi...");
  //   b.print("b");

  //   b = std::move(a);
}