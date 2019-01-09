#include "my_string.h"

namespace kapil {

/**************************************** member functions *********************/
  static std::size_t get_appropriate_capacity(std::size_t new_string_length) noexcept {
    std::size_t appropriate_capacity = string::get_default_capacity();
    if ((new_string_length << 1) < new_string_length) {
      appropriate_capacity = new_string_length;
    } else {
      if (appropriate_capacity <= new_string_length) {
         if (!(new_string_length & (new_string_length - 1))) {
           appropriate_capacity = new_string_length << 1;
         } else {
           appropriate_capacity = 1;
           while (appropriate_capacity < new_string_length) {
             appropriate_capacity <<= 1;
           }
         }
      }
    }
    return appropriate_capacity;
  }

  string::string() 
    : current_capacity_{ default_capacity_ } {
    sz_ = 0;
    ptr_ = std::make_unique<char[]>(current_capacity_ + 1);
    ptr_.get()[0] = '\0';
  }

  string::string(const string& other) {
    current_capacity_ = other.current_capacity_;
    sz_ = other.sz_;
    ptr_ = std::make_unique<char[]>(current_capacity_ + 1);
    std::memcpy(ptr_.get(), other.ptr_.get(), other.sz_ + 1); 
  }

  string::string(string&& rval) noexcept
    : current_capacity_{ rval.current_capacity_ },
      sz_{ rval.sz_ },
      ptr_{ std::move(rval.ptr_) } {
  }
  
  string::string(const char* c_string) {
    sz_ = std::strlen(c_string);
    current_capacity_ = get_appropriate_capacity(sz_);
    ptr_ = std::make_unique<char[]>(current_capacity_ + 1);
    std::memcpy(ptr_.get(), c_string, sz_ + 1);
  }

  string::string(char ch) {
    sz_ = 1;
    current_capacity_ = get_appropriate_capacity(sz_);
    ptr_ = std::make_unique<char[]>(current_capacity_ + 1);
    ptr_.get()[0] = ch;
    ptr_.get()[1] = '\0';
  }
  
  string::~string() noexcept {
    current_capacity_ = 0;
    sz_ = 0;
    ptr_.reset(nullptr);
  }


/**************************************** member functions *********************/
 
  std::size_t string::capacity() const noexcept {
    return current_capacity_;
  }

  std::size_t string::get_default_capacity() noexcept {
    return default_capacity_;
  }

  std::size_t string::size() const noexcept {
    return sz_;
  }
  
  std::size_t string::length() const noexcept {
    return sz_;
  }

  void string::resize(std::size_t n, char ch) {
    if (static_cast<long int>(n) < 0) {
      return;
    }

    if (n == sz_) {
      return;
    }

    if (n < sz_) {
      sz_ = n;
      ptr_.get()[sz_] = '\0';
      return;
    }

    current_capacity_ = get_appropriate_capacity(n);
    std::unique_ptr<char[]> temp = std::make_unique<char[]>(current_capacity_ + 1);

    std::memcpy(temp.get(), ptr_.get(), sz_);
    std::fill(temp.get() + sz_, temp.get() + n, ch);
    temp.get()[n] = '\0';

    sz_ = n;
    ptr_ = std::move(temp);
  }
  
  void string::clear() {
    ptr_.get()[0] = '\0';
    sz_ = 0;
  }

  bool string::empty() const noexcept {
    return sz_ == 0;
  }

  char& string::at(size_t idx) {
    if (static_cast<long int>(idx) < 0 || idx >= sz_) {
      throw std::out_of_range{"out of range memory access"};
    }
    return (*this)[idx];
  }

  const char& string::at(size_t idx) const {
    if (static_cast<long int>(idx) < 0 || idx >= sz_) {
      throw std::out_of_range{"out of range memory access"};
    }
    return (*this)[idx];
  }

  char& string::back() {
    return (*this)[sz_ - 1];
  }

  const char& string::back() const {
    return (*this)[sz_ - 1];
  }

  char& string::front() {
    return (*this)[0];
  }

  const char& string::front() const {
    return (*this)[0];
  }

  string& string::append(const string& rhs) {
    (*this) += rhs;
    return *this;
  }

  string& string::append(const char* rhs) {
    (*this) += rhs;
    return *this;
  }

  string& string::append(string&& rhs) {
    (*this) += rhs;
    return *this;
  }

  string& string::append(char ch) {
    (*this) += ch;
    return *this;
  }

  void string::push_back(char ch) {
    (*this) += ch;
    return;
  }

  string& string::assign(const string& rhs) {
    (*this) = rhs;
    return *this;
  }

  string& string::assign(const char* rhs) {
    (*this) = rhs;
    return *this;
  }

  string& string::assign(string&& rhs) noexcept {
    (*this) = rhs;
    return *this;
  }

  void string::swap(string &str) {
    using std::swap;
    swap(current_capacity_, str.current_capacity_);
    swap(sz_, str.sz_);
    swap(ptr_, str.ptr_);
  }

  const char* string::c_str() const noexcept {
    return ptr_.get();
  }

  const char* string::data() const noexcept {
    return c_str();
  }



/**************************************** member operator overloads*********************/
  
  string& string::operator = (const string& rhs) {
    if (this != &rhs) {
      if (current_capacity_ < rhs.sz_) {
        current_capacity_ = rhs.current_capacity_;
        ptr_ = std::make_unique<char[]>(current_capacity_ + 1);
      }
      sz_ = rhs.sz_;
      std::memcpy(ptr_.get(), rhs.c_str(), rhs.sz_ + 1);
    }
    return *this;
  }

  string& string::operator = (string&& rval) noexcept {
    current_capacity_ = rval.current_capacity_;
    sz_ = rval.sz_;
    ptr_ = std::move(rval.ptr_);
    return *this;
  }

  string& string::operator = (const char* c_string) {
    sz_ = std::strlen(c_string);
    auto appropriate_capacity = get_appropriate_capacity(sz_);
    if (current_capacity_ < appropriate_capacity) {
      current_capacity_ = appropriate_capacity;
      ptr_ = std::make_unique<char[]>(current_capacity_ + 1);
    }
    std::memcpy(ptr_.get(), c_string, sz_ + 1);
    return *this;
  }

  string& string::operator = (char ch) {
    sz_ = 1;
    current_capacity_ = get_appropriate_capacity(sz_);
    ptr_ = std::make_unique<char[]>(current_capacity_ + 1);
    ptr_.get()[0] = ch;
    ptr_.get()[1] = '\0';
    return *this;
  }

  string& string::operator += (const string& rhs) {
    auto appropriate_capacity = get_appropriate_capacity(sz_ + rhs.sz_);
 
    if (current_capacity_ < appropriate_capacity) {
      current_capacity_ = appropriate_capacity;
      std::unique_ptr<char[]> temp = std::make_unique<char[]>(current_capacity_ + 1);
      std::memcpy(temp.get(), ptr_.get(), sz_);
      ptr_ = std::move(temp);
    }

    std::memcpy(ptr_.get() + sz_, rhs.c_str(), rhs.sz_ + 1);
    sz_ += rhs.sz_;

    return *this;
  }

  string& string::operator += (const char* rhs) {
    auto rhs_sz = std::strlen(rhs);
    auto appropriate_capacity = get_appropriate_capacity(sz_ + rhs_sz);
 
    if (current_capacity_ < appropriate_capacity) {
      current_capacity_ = appropriate_capacity;
      std::unique_ptr<char[]> temp = std::make_unique<char[]>(current_capacity_ + 1);
      std::memcpy(temp.get(), ptr_.get(), sz_);
      ptr_ = std::move(temp);
    }

    std::memcpy(ptr_.get() + sz_, rhs, rhs_sz + 1);
    sz_ += rhs_sz;

    return *this;
  }

  string& string::operator += (char ch) {
    auto appropriate_capacity = get_appropriate_capacity(sz_ + 1);

    if (current_capacity_ < appropriate_capacity) {
      current_capacity_ = appropriate_capacity;
      std::unique_ptr<char[]> temp = std::make_unique<char[]>(current_capacity_ + 1);
      std::memcpy(temp.get(), ptr_.get(), sz_);
      ptr_ = std::move(temp);
    }

    ptr_.get()[sz_] = ch;
    ptr_.get()[sz_ + 1] = '\0';
    sz_ += 1;

    return *this;
  }
  
  char& string::operator [] (size_t idx) {
    return ptr_.get()[idx];
  }

  const char& string::operator [] (size_t idx) const {
    return ptr_.get()[idx];
  }
  


/**************************************** friend operator overloads *********************/

  std::ostream& operator << (std::ostream& out, const string& str) {
    if (str.size() > 0) {
      out.write(str.c_str(), static_cast<std::streamsize>(str.size()));
    }
    return out;
  }

  string operator + (const string& lhs, const string& rhs) {
    string temp{lhs};
    temp += rhs;
    return temp;
  }

  string operator + (const string& lhs, const char* rhs) {
    string temp{lhs};
    temp += rhs;
    return temp;
  }

  string operator + (const char* lhs, const string& rhs) {
    string temp{lhs};
    temp += rhs;
    return temp;
  }

  string operator + (const string& lhs, char rhs) {
    string temp{lhs};
    temp += rhs;
    return temp;
  }

  string operator + (char lhs, const string& rhs) {
    string temp{lhs};
    temp += rhs;
    return temp;
  }

  bool operator == (const string& lhs, const string& rhs) noexcept {
    if (lhs.sz_ != rhs.sz_) {
      return false;
    }

    const char* lhs_c_string = lhs.c_str();
    const char* rhs_c_string = rhs.c_str();
    const size_t range_to_compare = lhs.sz_;

    for (size_t idx{0}; idx < range_to_compare; ++idx) {
      if (lhs_c_string[idx] != rhs_c_string[idx]) {
        return false;
      }
    }

    return true;
  }


  bool operator == (const string& lhs, const char* rhs) noexcept {
    const size_t rhs_sz = std::strlen(rhs);
    if (lhs.sz_ != rhs_sz) {
      return false;
    }

    const char* lhs_c_string = lhs.c_str();
    const char* rhs_c_string = rhs;
    const size_t range_to_compare = lhs.sz_;

    for (size_t idx{0}; idx < range_to_compare; ++idx) {
      if (lhs_c_string[idx] != rhs_c_string[idx]) {
        return false;
      }
    }

    return true;
  }


  bool operator == (const char* lhs, const string& rhs) noexcept {
    const size_t lhs_sz = std::strlen(lhs);
    if (lhs_sz != rhs.sz_) {
      return false;
    }

    const char* lhs_c_string = lhs;
    const char* rhs_c_string = rhs.c_str();
    const size_t range_to_compare = rhs.sz_;

    for (size_t idx{0}; idx < range_to_compare; ++idx) {
      if (lhs_c_string[idx] != rhs_c_string[idx]) {
        return false;
      }
    }

    return true;
  }

  bool operator == (const string& lhs, char rhs) noexcept {
    return (lhs.sz_ == 1) && (lhs.c_str()[0] == rhs);
  }

  bool operator == (char lhs, const string& rhs) noexcept {
    return (rhs.sz_ == 1) && (lhs == rhs.c_str()[0]);
  }
  
  bool operator != (const string& lhs, const string& rhs) noexcept {
    return !(lhs == rhs);
  }

  bool operator != (const string& lhs, const char* rhs) noexcept {
    return !(lhs == rhs);
  }

  bool operator != (const char* lhs, const string& rhs) noexcept {
    return !(lhs == rhs);
  }

  bool operator != (const string& lhs, char rhs) noexcept {
    return !(lhs == rhs);
  }

  bool operator != (char lhs, const string& rhs) noexcept {
    return !(lhs == rhs);
  }
  
  bool operator < (const string& lhs, const string& rhs) noexcept {
    const size_t range_to_loop = (lhs.sz_ < rhs.sz_) ? lhs.sz_ : rhs.sz_;
    const char* lhs_c_string = lhs.c_str();
    const char* rhs_c_string = rhs.c_str();

    for (size_t idx{0}; idx < range_to_loop; ++idx) {
      if (lhs_c_string[idx] < rhs_c_string[idx]) {
        return true;
      } else if (lhs_c_string[idx] > rhs_c_string[idx]) {
        return false;
      }
    }

    if (lhs.sz_ >= rhs.sz_) {
      return false;
    }

    return true;
  }


  bool operator < (const string& lhs, const char* rhs) noexcept {
    const size_t rhs_sz = std::strlen(rhs);
    const size_t range_to_loop = (lhs.sz_ < rhs_sz) ? lhs.sz_ : rhs_sz;
    const char* lhs_c_string = lhs.c_str();
    const char* rhs_c_string = rhs;

    for (size_t idx{0}; idx < range_to_loop; ++idx) {
      if (lhs_c_string[idx] < rhs_c_string[idx]) {
        return true;
      } else if (lhs_c_string[idx] > rhs_c_string[idx]) {
        return false;
      }
    }

    if (lhs.sz_ >= rhs_sz) {
      return false;
    }

    return true;
  }


  bool operator < (const char* lhs, const string& rhs) noexcept {
    const size_t lhs_sz = std::strlen(lhs);
    const size_t range_to_loop = (lhs_sz < rhs.sz_) ? lhs_sz : rhs.sz_;
    const char* lhs_c_string = lhs;
    const char* rhs_c_string = rhs.c_str();

    for (size_t idx{0}; idx < range_to_loop; ++idx) {
      if (lhs_c_string[idx] < rhs_c_string[idx]) {
        return true;
      } else if (lhs_c_string[idx] > rhs_c_string[idx]) {
        return false;
      }
    }

    if (lhs_sz >= rhs.sz_) {
      return false;
    }

    return true;
  }

  bool operator < (const string& lhs, char rhs) noexcept {
    if ((lhs.sz_ == 0) || (lhs.c_str()[0] < rhs)) {
      return true;
    }

    return false;
  }

  bool operator < (char lhs, const string& rhs) noexcept {
    if ((rhs.sz_ > 0) && (lhs < rhs.c_str()[0])) {
      return true;
    }

    return false;
  }

  bool operator > (const string& lhs, const string& rhs) noexcept {
    return (lhs != rhs) && (!(lhs < rhs));
  }

  bool operator > (const string& lhs, const char* rhs) noexcept {
    return (lhs != rhs) && (!(lhs < rhs));
  }

  bool operator > (const char* lhs, const string& rhs) noexcept {
    return (lhs != rhs) && (!(lhs < rhs));
  }

  bool operator > (const string& lhs, char rhs) noexcept {
    return (lhs != rhs) && (!(lhs < rhs));
  }

  bool operator > (char lhs, const string& rhs) noexcept {
    return (lhs != rhs) && (!(lhs < rhs));
  }

/**************************************** iterator related implementations *********************/

  using iterator = string::iterator;

  iterator::iterator(string *str, long int index) noexcept
    : str_{str}, index_{index} {
  }

  iterator::iterator(const iterator& itr) noexcept
    : str_{itr.str_}, index_{itr.index_} {
  }

  iterator::iterator(iterator&& rval) noexcept
    : str_{rval.str_}, index_{rval.index_} {
  }

  iterator::~iterator() noexcept {
    str_ = nullptr;
    index_ = 0;
  }



  iterator& iterator::operator = (const iterator& rhs) noexcept {
    str_ = rhs.str_;
    index_ = rhs.index_;
    return *this;
  }

  iterator& iterator::operator = (iterator&& rhs) noexcept {
    str_ = rhs.str_;
    index_ = rhs.index_;
    return *this;
  }

  bool iterator::operator != (const iterator& rhs) const noexcept {
    return (str_ != rhs.str_) || (index_ != rhs.index_); 
  }

  bool iterator::operator == (const iterator& rhs) const noexcept {
    return (str_ == rhs.str_) && (index_ == rhs.index_);
  }

  iterator& iterator::operator ++ () noexcept {
    ++index_;
    return *this;
  }

  iterator iterator::operator ++ (int) noexcept {
    auto temp = *this;
    ++(*this);
    return temp;
  }

  iterator& iterator::operator -- () noexcept {
    --index_;
    return *this;
  }

  iterator iterator::operator -- (int) noexcept {
    auto temp = *this;
    --(*this);
    return temp;
  }

  char& iterator::operator * () const {
    return (*str_)[index_];
  }

  iterator string::begin() {
    return iterator(this);
  }

  iterator string::end() {
    return iterator(this, static_cast<long int>(sz_));
  }



  using const_iterator = string::const_iterator;

  const_iterator::const_iterator(const string* str, long index) noexcept
    : str_{str}, index_{index} {
  }

  const_iterator::const_iterator(const const_iterator& itr) noexcept
    : str_{itr.str_}, index_{itr.index_} {
  }

  const_iterator::const_iterator(const_iterator&& rval) noexcept
    : str_{rval.str_}, index_{rval.index_} {
  }

  const_iterator::~const_iterator() noexcept {
    str_ = nullptr;
    index_ = 0;
  }



  const_iterator& const_iterator::operator = (const const_iterator& rhs) noexcept {
    str_ = rhs.str_;
    index_ = rhs.index_;
    return *this;
  }

  const_iterator& const_iterator::operator = (const_iterator&& rhs) noexcept {
    str_ = rhs.str_;
    index_ = rhs.index_;
    return *this;
  }

  bool const_iterator::operator != (const const_iterator& rhs) const noexcept {
    return (str_ != rhs.str_) || (index_ != rhs.index_); 
  }

  bool const_iterator::operator == (const const_iterator& rhs) const noexcept {
    return (str_ == rhs.str_) && (index_ == rhs.index_);
  }

  const_iterator& const_iterator::operator ++ () noexcept {
    ++index_;
    return *this;
  }

  const_iterator const_iterator::operator ++ (int) noexcept {
    auto temp = *this;
    ++(*this);
    return temp;
  }

  const_iterator& const_iterator::operator -- () noexcept {
    --index_;
    return *this;
  }

  const_iterator const_iterator::operator -- (int) noexcept {
    auto temp = *this;
    --(*this);
    return temp;
  }

  const char& const_iterator::operator * () const {
    return (*str_)[index_];
  }

  const_iterator string::cbegin() const {
    return const_iterator(this, 0);
  }

  const_iterator string::cend() const {
    return const_iterator(this, static_cast<long int>(sz_));
  }



  using reverse_iterator = string::reverse_iterator;

  reverse_iterator::reverse_iterator(string *str, long int index) noexcept
    : str_{str}, index_{index} {
  }

  reverse_iterator::reverse_iterator(const reverse_iterator& itr) noexcept
    : str_{itr.str_}, index_{itr.index_} {
  }

  reverse_iterator::reverse_iterator(reverse_iterator&& rval) noexcept
    : str_{rval.str_}, index_{rval.index_} {
  }

  reverse_iterator::~reverse_iterator() noexcept {
    str_ = nullptr;
    index_ = 0;
  }



  reverse_iterator& reverse_iterator::operator = (const reverse_iterator& rhs) noexcept {
    str_ = rhs.str_;
    index_ = rhs.index_;
    return *this;
  }

  reverse_iterator& reverse_iterator::operator = (reverse_iterator&& rhs) noexcept {
    str_ = rhs.str_;
    index_ = rhs.index_;
    return *this;
  }

  bool reverse_iterator::operator != (const reverse_iterator& rhs) const noexcept {
    return (str_ != rhs.str_) || (index_ != rhs.index_); 
  }

  bool reverse_iterator::operator == (const reverse_iterator& rhs) const noexcept {
    return (str_ == rhs.str_) && (index_ == rhs.index_);
  }

  reverse_iterator& reverse_iterator::operator ++ () noexcept {
    --index_;
    return *this;
  }

  reverse_iterator reverse_iterator::operator ++ (int) noexcept {
    auto temp = *this;
    ++(*this);
    return temp;
  }

  reverse_iterator& reverse_iterator::operator -- () noexcept {
    ++index_;
    return *this;
  }

  reverse_iterator reverse_iterator::operator -- (int) noexcept {
    auto temp = *this;
    --(*this);
    return temp;
  }

  char& reverse_iterator::operator * () const {
    return (*str_)[index_];
  }

  reverse_iterator string::rbegin() {
    return reverse_iterator(this, static_cast<long int>(sz_ - 1));
  }

  reverse_iterator string::rend() {
    return reverse_iterator(this, -1);
  }



  using reverse_const_iterator = string::reverse_const_iterator;

  reverse_const_iterator::reverse_const_iterator(const string* str, long int index) noexcept
    : str_{str}, index_{index} {
  }

  reverse_const_iterator::reverse_const_iterator(const reverse_const_iterator& itr) noexcept
    : str_{itr.str_}, index_{itr.index_} {
  }

  reverse_const_iterator::reverse_const_iterator(reverse_const_iterator&& rval) noexcept
    : str_{rval.str_}, index_{rval.index_} {
  }

  reverse_const_iterator::~reverse_const_iterator() noexcept {
    str_ = nullptr;
    index_ = 0;
  }



  reverse_const_iterator& reverse_const_iterator::operator = (const reverse_const_iterator& rhs) noexcept {
    str_ = rhs.str_;
    index_ = rhs.index_;
    return *this;
  }

  reverse_const_iterator& reverse_const_iterator::operator = (reverse_const_iterator&& rhs) noexcept {
    str_ = rhs.str_;
    index_ = rhs.index_;
    return *this;
  }

  bool reverse_const_iterator::operator != (const reverse_const_iterator& rhs) const noexcept {
    return (str_ != rhs.str_) || (index_ != rhs.index_); 
  }

  bool reverse_const_iterator::operator == (const reverse_const_iterator& rhs) const noexcept {
    return (str_ == rhs.str_) && (index_ == rhs.index_);
  }

  reverse_const_iterator& reverse_const_iterator::operator ++ () noexcept {
    --index_;
    return *this;
  }

  reverse_const_iterator reverse_const_iterator::operator ++ (int) noexcept {
    auto temp = *this;
    ++(*this);
    return temp;
  }

  reverse_const_iterator& reverse_const_iterator::operator -- () noexcept {
    ++index_;
    return *this;
  }

  reverse_const_iterator reverse_const_iterator::operator -- (int) noexcept {
    auto temp = *this;
    --(*this);
    return temp;
  }

  const char& reverse_const_iterator::operator * () const {
    return (*str_)[index_];
  }

  reverse_const_iterator string::crbegin() const {
    return reverse_const_iterator(this, static_cast<long int>(sz_ - 1));
  }

  reverse_const_iterator string::crend() const {
    return reverse_const_iterator(this, -1);
  }

  void swap(string& lhs, string& rhs) noexcept {
    lhs.swap(rhs);
  }
} //kapil
