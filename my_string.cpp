#include "my_string.h"

namespace kapil {

/**************************************** member functions *********************/

  string::string() noexcept {
    ptr_.reset();
    sz_ = 0;
  }

  string::string(const string& other) {
    sz_ = other.sz_;
    ptr_ = std::make_unique<char[]>(sz_ + 1);
    std::strcpy(ptr_.get(), other.ptr_.get()); 
  }

  string::string(string&& rval) noexcept {
    sz_ = rval.sz_;
    ptr_ = std::move(rval.ptr_);
  }
  
  string::string(const char* c_string) {
    sz_ = strlen(c_string);
    ptr_ = std::make_unique<char[]>(sz_ + 1);
    std::strcpy(ptr_.get(), c_string);
  }

  string::string(char ch) {
    sz_ = 1;
    ptr_ = std::make_unique<char[]>(sz_ + 1);
    ptr_.get()[0] = ch;
    ptr_.get()[1] = '\0';
  }
  
  string::~string() noexcept {
    ptr_.reset();
  };


/**************************************** member functions *********************/
  
  size_t string::size() const noexcept {
    return sz_;
  }
  
  size_t string::length() const noexcept {
    return sz_;
  }

  void string::resize(size_t n, char ch) {
    if (n == sz_) {
      return;
    }

    std::unique_ptr<char[]> temp = std::make_unique<char[]>(n + 1);

    if (n < sz_) {
      std::strncpy(temp.get(), ptr_.get(), n);
      temp.get()[n] = '\0';
    } else if (n > sz_) {
      std::strncpy(temp.get(), ptr_.get(), sz_);
      std::fill(temp.get() + sz_, temp.get() + n + 1, ch);
    }

    ptr_.reset();
    sz_ = n;
    ptr_ = std::move(temp);
  }
  
  void string::clear() noexcept {
    ptr_.reset();
    sz_ = 0;
  }

  bool string::empty() const noexcept {
    return sz_ == 0;
  }

  char& string::at(size_t idx) {
    if (idx < 0 || idx >= sz_) {
      throw std::out_of_range{"out of range memory access"};
    }
    return (*this)[idx];
  }

  const char& string::at(size_t idx) const {
    if (idx < 0 || idx >= sz_) {
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

  string& string::assign(string&& rhs) {
    (*this) = rhs;
    return *this;
  }

  void string::swap(string &str) {
    string temp{str};
    str = *this;
    *this = temp;
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
      ptr_.reset();
      sz_ = rhs.sz_;
      ptr_ = std::make_unique<char[]>(sz_ + 1);
      std::strcpy(ptr_.get(), rhs.ptr_.get());
    }
    return *this;
  }

  string& string::operator = (string&& rval) noexcept {
    ptr_.reset();
    sz_ = rval.sz_;
    ptr_ = std::move(rval.ptr_);
    return *this;
  }

  string& string::operator = (const char* c_string) {
    ptr_.reset();
    sz_ = strlen(c_string);
    ptr_ = std::make_unique<char[]>(sz_ + 1);
    std::strcpy(ptr_.get(), c_string);
    return *this;
  }

  string& string::operator = (char ch) {
    ptr_.reset();
    sz_ = 1;
    ptr_ = std::make_unique<char[]>(sz_ + 1);
    ptr_.get()[0] = ch;
    ptr_.get()[1] = '\0';
    return *this;
  }

  string& string::operator += (const string& rhs) {
    std::unique_ptr<char[]> temp = std::make_unique<char[]>(sz_ + rhs.sz_ + 1);
    std::strcpy(temp.get(), ptr_.get());
    std::strcpy(temp.get() + sz_, rhs.ptr_.get());
    
    
    ptr_.reset();
    sz_ += rhs.sz_;
    ptr_ = std::move(temp);

    return *this;
  }

  string& string::operator += (const char* rhs) {
    size_t rhs_len = std::strlen(rhs);

    std::unique_ptr<char[]> temp = std::make_unique<char[]>(sz_ + rhs_len + 1);
    strcpy(temp.get(), ptr_.get());
    strcpy(temp.get() + sz_, rhs);

    ptr_.reset();
    sz_ += rhs_len;
    ptr_ = std::move(temp);

    return *this;
  }

  string& string::operator += (char ch) {
    std::unique_ptr<char[]> temp = std::make_unique<char[]>(sz_ + 1 + 1);
    std::strcpy(temp.get(), ptr_.get());
    temp.get()[sz_] = ch;
    temp.get()[sz_ + 1] = '\0';

    ptr_.reset();
    sz_ += 1;
    ptr_ = std::move(temp);

    return *this;
  }
  
  
  string& string::operator += (string&& rval) {
    std::unique_ptr<char[]> temp = std::make_unique<char[]>(sz_ + rval.sz_ + 1);
    std::strcpy(temp.get(), rval.ptr_.get());
    std::strcpy(temp.get() + sz_, rval.ptr_.get());

    ptr_.reset();
    sz_ += rval.sz_;
    ptr_ = std::move(temp);

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
    if (str.ptr_ != nullptr) {
      const char* ch = str.ptr_.get();
      for (size_t idx{0}; idx < str.size(); ++idx) {
        out << ch[idx];
      }
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

  string operator + (string&& lhs, string&& rhs) {
    string temp{lhs};
    temp += rhs;
    return temp;
  }

  string operator + (string&& lhs, const char* rhs) {
    string temp{lhs};
    temp += rhs;
    return temp;
  }

  string operator + (const char* lhs, string&& rhs) {
    string temp{lhs};
    temp += rhs;
    return temp;
  }

  string operator + (const string& lhs, string&& rhs) {
    string temp{lhs};
    temp += rhs;
    return temp;
  }

  string operator + (string&& lhs, const string& rhs) {
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

  string operator + (string&& lhs, char rhs) {
    string temp{lhs};
    temp += rhs;
    return temp;
  }

  string operator + (char lhs, string&& rhs) {
    string temp{lhs};
    temp += rhs;
    return temp;
  }

  bool operator == (const string& lhs, const string& rhs) {
    return (lhs.sz_ == rhs.sz_) && (std::strncmp(lhs.ptr_.get(), rhs.ptr_.get(), lhs.sz_) == 0);
  }

  bool operator == (const string& lhs, const char* rhs) {
    return (lhs.sz_ == std::strlen(rhs)) && (std::strncmp(lhs.ptr_.get(), rhs, lhs.sz_) == 0);
  }

  bool operator == (const char* lhs, const string& rhs) {
    return (strlen(lhs) == rhs.sz_) && (std::strncmp(lhs, rhs.ptr_.get(), rhs.sz_) == 0);
  }

  bool operator == (const string& lhs, char rhs) {
    return (lhs.sz_ == 1) && (lhs.ptr_.get()[0] == rhs);
  }

  bool operator == (char lhs, const string& rhs) {
    return (rhs.sz_ == 1) && (lhs == rhs.ptr_.get()[0]);
  }

  bool operator == (const string& lhs, string&& rhs) {
    return (lhs.sz_ == rhs.sz_) && (strncmp(lhs.ptr_.get(), rhs.ptr_.get(), lhs.sz_) == 0);
  }

  bool operator == (string&& lhs, const string& rhs) {
    return (lhs.sz_ == rhs.sz_) && (strncmp(lhs.ptr_.get(), rhs.ptr_.get(), lhs.sz_) == 0);
  }

  bool operator == (string&& lhs, string&& rhs) {
    return (lhs.sz_ == rhs.sz_) && (strncmp(lhs.ptr_.get(), rhs.ptr_.get(), lhs.sz_) == 0);
  }

  bool operator == (string&& lhs, char rhs) {
    return (lhs.sz_ == 1) && (lhs.ptr_.get()[0] == rhs);
  }
  
  bool operator == (char lhs, string&& rhs) {
    return (rhs.sz_ == 1) && (rhs.ptr_.get()[0] == lhs);
  }

  bool operator == (string&& lhs, const char* rhs) {
    return (lhs.sz_ == std::strlen(rhs)) && (std::strncmp(lhs.ptr_.get(), rhs, lhs.sz_) == 0);
  }

  bool operator == (const char* lhs, string && rhs) {
    return (std::strlen(lhs) == rhs.sz_) && (std::strncmp(lhs, rhs.ptr_.get(), rhs.sz_) == 0);
  }

  bool operator != (const string& lhs, const string& rhs) {
    return !(lhs == rhs);
  }

  bool operator != (const string& lhs, const char* rhs) {
    return !(lhs == rhs);
  }

  bool operator != (const char* lhs, const string& rhs) {
    return !(lhs == rhs);
  }

  bool operator != (const string& lhs, char rhs) {
    return !(lhs == rhs);
  }

  bool operator != (char lhs, const string& rhs) {
    return !(lhs == rhs);
  }

  bool operator != (const string& lhs, string&& rhs) {
    return (lhs.sz_ != rhs.sz_) || (strncmp(lhs.ptr_.get(), rhs.ptr_.get(), lhs.sz_) != 0);
  }

  bool operator != (string&& lhs, const string& rhs) {
    return (lhs.sz_ != rhs.sz_) || (strncmp(lhs.ptr_.get(), rhs.ptr_.get(), lhs.sz_) != 0);
  }

  bool operator != (string&& lhs, string&& rhs) {
    return (lhs.sz_ != rhs.sz_) || (strncmp(lhs.ptr_.get(), rhs.ptr_.get(), lhs.sz_) != 0);
  }

  bool operator != (string&& lhs, char rhs) {
    return (lhs.sz_ != 1) || (lhs.ptr_.get()[0] != rhs);
  }
  
  bool operator != (char lhs, string&& rhs) {
    return (rhs.sz_ != 1) || (rhs.ptr_.get()[0] != lhs);
  }

  bool operator != (string&& lhs, const char* rhs) {
    return (lhs.sz_ != std::strlen(rhs)) || (std::strncmp(lhs.ptr_.get(), rhs, lhs.sz_) != 0);
  }

  bool operator != (const char* lhs, string && rhs) {
    return (std::strlen(lhs) != rhs.sz_) || (std::strncmp(lhs, rhs.ptr_.get(), rhs.sz_) != 0);
  }



/**************************************** iterator related implementations *********************/

  using iterator = string::iterator;

  iterator::iterator(string *str, size_t index)
    : str_{str}, index_{index} {
  }

  iterator::iterator(const iterator& itr)
    : str_{itr.str_}, index_{itr.index_} {
  }

  iterator::iterator(iterator&& rval) noexcept
    : str_{rval.str_}, index_{rval.index_} {
  }

  iterator::~iterator() {
    str_ = nullptr;
    index_ = 0;
  }



  iterator& iterator::operator = (const iterator& rhs) {
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

  iterator& iterator::operator ++ () {
    ++index_;
    return *this;
  }

  iterator& iterator::operator ++ (int dummy) {
    ++(*this);
    return *this;
  }

  iterator& iterator::operator -- () {
    --index_;
    return *this;
  }

  iterator& iterator::operator -- (int dummy) {
    --(*this);
    return *this;
  }

  char& iterator::operator * () const {
    return (*str_)[index_];
  }

  iterator string::begin() {
    return iterator(this);
  }

  iterator string::end() {
    return iterator(this, sz_);
  }
} //kapil
