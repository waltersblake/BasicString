#include "BasicString.h"
#include <cstddef>
#include <cstring>
#include <stdexcept>

namespace basicstring {

BasicString::BasicString(size_t max_size) : max_size{max_size}, length{} {
  if (max_size == 0) {
    throw std::runtime_error("Max size must be greater than 0");
  }
  buffer = new char[max_size];
  memset(buffer, 0, max_size);
}

BasicString::~BasicString() { delete[] buffer; }

// Copy constructor
BasicString::BasicString(const BasicString& other)
    : max_size{other.max_size}, length{other.length} {
  buffer = new char[max_size];
  std::strncpy(buffer, other.buffer, length);
}

// Move constructor
BasicString::BasicString(BasicString&& other) noexcept
    : max_size{other.max_size}, length{other.length}, buffer{other.buffer} {
  other.length = 0;
  other.max_size = 0;
  other.buffer = nullptr;
}

// Copy assignment
BasicString& BasicString::operator=(const BasicString& other) {
  if (this == &other) {
    return *this;
  }
  delete[] buffer;
  max_size = other.max_size;
  length = other.length;
  buffer = new char[max_size];
  memset(buffer, 0, max_size);
  std::strncpy(buffer, other.buffer, length);

  return *this;
}

// Move assignment
BasicString& BasicString::operator=(BasicString&& other) {
  if (this == &other) {
    return *this;
  }
  max_size = other.max_size;
  length = other.length;
  buffer = other.buffer;

  other.max_size = 0;
  other.length = 0;
  other.buffer = nullptr;

  return *this;
}

bool BasicString::append_line(const char* line) {
  size_t line_length = strlen(line);
  if (line_length + length + 2 > max_size) {
    return false;
  }
  std::strncpy(buffer + length, line, max_size - length);
  length += line_length;
  buffer[length++] = '\n';
  buffer[length] = 0;
  return true;
}

void BasicString::print(const char* prefix) const { printf("%s: %s", prefix, buffer); }

} // namespace basicstring