#include <cstddef>
#include <cstring>

namespace basicstring {

class BasicString {
private:
  size_t max_size;
  size_t length;
  char* buffer;

public:
  BasicString(size_t max_size);
  ~BasicString();
  BasicString(const BasicString& other);
  BasicString(BasicString&& other) noexcept;
  BasicString& operator=(const BasicString& other);
  BasicString& operator=(BasicString&& other);
  bool append_line(const char* line);
  void print(const char* prefix) const;
};
} // namespace basicstring