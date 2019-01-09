#ifndef MY_STRING_H_
#define MY_STRING_H_

#include <cstring>
#include <iostream>
#include <memory>
#include <algorithm>
#include <stdexcept>
#include <limits>

namespace kapil {
  class string final {
    private:
      static constexpr std::size_t default_capacity_ = 0;
      std::size_t current_capacity_;
      std::size_t sz_;
      std::unique_ptr<char[]> ptr_;
    public:
      string();
      string(const string& str);
      string(string&& rval) noexcept;
      string(const char* c_string);                // Undefined behavior if c_string is nullptr.
      string(char ch);
      string(int) = delete;
      ~string() noexcept;

      std::size_t capacity() const noexcept;
      static std::size_t get_default_capacity() noexcept;
      std::size_t size() const noexcept;
      std::size_t length() const noexcept;
      void resize(std::size_t sz, char ch = '\0'); // String remains unchanged if new size, sz < 0.
      void clear();
      bool empty() const noexcept;
      char& at(size_t idx);                        // Throws exception if idx is invalid character index in string.
      const char& at(size_t idx) const;            // Throws exception if idx is invalid character index in string.
      char& back();                                // Undefined behavior if string is empty.
      const char& back() const;                    // Undefined behavior if string is empty.
      char& front();                               // Undefined behavior if string is empty.
      const char& front() const;                   // Undefined behavior if string is empty.
      string& append(const string& rhs);
      string& append(const char* rhs);             // Undefined behavior if rhs is nullptr.
      string& append(string&& rhs);
      string& append(char rhs);
      void push_back(char ch);
      string& assign(const string& str);
      string& assign(const char* c_string);        // Undefined behavior if c_string is nullptr.
      string& assign(string&& rval) noexcept;
      void swap(string& str);
      const char* c_str() const noexcept;
      const char* data() const noexcept;

      
      
      string& operator = (const string& rhs);
      string& operator = (string&& rhs) noexcept;
      string& operator = (const char* rhs);        // Undefined behavior if rhs is nullptr.
      string& operator = (char rhs);
      string& operator += (const string& rhs);
      string& operator += (const char* rhs);       // Undefined behavior if rhs is nullptr.
      string& operator += (char rhs);
      char& operator[] (size_t idx);               // Does not check if idx is a valid character index in string.
      const char& operator[] (size_t idx) const;   // Does not check if idx is a valid character index in string.

      friend std::ostream& operator << (std::ostream& os, const string& str);
      friend string operator + (const string& lhs, const string& rhs);
      friend string operator + (const string& lhs, const char* rhs);         // Undefined behavior if rhs is nullptr.
      friend string operator + (const char* lhs, const string& rhs);         // Undefined behavior if lhs is nullptr.
      friend string operator + (const string& lhs, char rhs);
      friend string operator + (char lhs, const string& rhs);
      friend bool operator == (const string& lhs, const string& rhs) noexcept;
      friend bool operator == (const string& lhs, const char* rhs) noexcept; // Undefined behavior if rhs is nullptr.
      friend bool operator == (const char* lhs, const string& rhs) noexcept; // Undefined behavior if lhs is nullptr.
      friend bool operator == (const string& lhs, char rhs) noexcept;
      friend bool operator == (char lhs, const string& rhs) noexcept;
      friend bool operator != (const string& lhs, const string& rhs) noexcept;
      friend bool operator != (const string& lhs, const char* rhs) noexcept; // Undefined behavior if rhs is nullptr.
      friend bool operator != (const char* lhs, const string& rhs) noexcept; // Undefined behavior if lhs is nullptr.
      friend bool operator != (const string& lhs, char rhs) noexcept;
      friend bool operator != (char lhs, const string& rhs) noexcept;
      friend bool operator < (const string& lhs, const string& rhs) noexcept;
      friend bool operator < (const string& lhs, const char* rhs) noexcept;  // Undefined behavior if rhs is nullptr.
      friend bool operator < (const char* lhs, const string& rhs) noexcept;  // Undefined behavior if lhs is nullptr.
      friend bool operator < (const string& lhs, char rhs) noexcept;
      friend bool operator < (char lhs, const string& rhs) noexcept;
      friend bool operator > (const string& lhs, const string& rhs) noexcept;
      friend bool operator > (const string& lhs, const char* rhs) noexcept;  // Undefined behavior if rhs is nullptr.
      friend bool operator > (const char* lhs, const string& rhs) noexcept;  // Undefined behavior if lhs is nullptr.
      friend bool operator > (const string& lhs, char rhs) noexcept;
      friend bool operator > (char lhs, const string& rhs) noexcept;


      class iterator
      {
        private:
          string* str_;
          long int index_;
        public:
          iterator(string* str = nullptr, long int idx = 0) noexcept;
          iterator(const iterator& itr) noexcept;
          iterator(iterator&& rval) noexcept;
          ~iterator() noexcept;

          iterator& operator = (const iterator& itr) noexcept;
          iterator& operator = (iterator&& rval) noexcept;
          bool operator != (const iterator& itr) const noexcept;
          bool operator == (const iterator& itr) const noexcept;
          iterator& operator ++ () noexcept;
          iterator operator ++ (int dummy) noexcept;
          iterator& operator -- () noexcept;
          iterator operator -- (int dummy) noexcept;
          char& operator * () const;
      };

      iterator begin();
      iterator end();

      class const_iterator
      {
        private:
          const string* str_;
          long int index_;
        public:
          const_iterator(const string* str, long int idx) noexcept;
          const_iterator(const const_iterator& itr) noexcept;
          const_iterator(const_iterator&& rval) noexcept;
          ~const_iterator() noexcept;

          const_iterator& operator = (const const_iterator& citr) noexcept;
          const_iterator& operator = (const_iterator&& rval) noexcept;
          bool operator != (const const_iterator& citr) const noexcept;
          bool operator == (const const_iterator& citr) const noexcept;
          const_iterator& operator ++ () noexcept;
          const_iterator operator ++ (int dummy) noexcept;
          const_iterator& operator -- () noexcept;
          const_iterator operator -- (int dummy) noexcept;
          const char& operator * () const;
      };

      const_iterator cbegin() const;
      const_iterator cend() const;

      class reverse_iterator
      {
        private:
          string* str_;
          long int index_;
        public:
          reverse_iterator(string* str = nullptr, long int idx = 0) noexcept;
          reverse_iterator(const reverse_iterator& ritr) noexcept;
          reverse_iterator(reverse_iterator&& rval) noexcept;
          ~reverse_iterator() noexcept;

          reverse_iterator& operator = (const reverse_iterator& ritr) noexcept;
          reverse_iterator& operator = (reverse_iterator&& rval) noexcept;
          bool operator != (const reverse_iterator& ritr) const noexcept;
          bool operator == (const reverse_iterator& ritr) const noexcept;
          reverse_iterator& operator ++ () noexcept;
          reverse_iterator operator ++ (int dummy) noexcept;
          reverse_iterator& operator -- () noexcept;
          reverse_iterator operator -- (int dummy) noexcept;
          char& operator * () const;
      };

      reverse_iterator rbegin();
      reverse_iterator rend();

      class reverse_const_iterator
      {
        private:
          const string* str_;
          long int index_;
        public:
          reverse_const_iterator(const string* str, long int idx) noexcept;
          reverse_const_iterator(const reverse_const_iterator& rcitr) noexcept;
          reverse_const_iterator(reverse_const_iterator&& rval) noexcept;
          ~reverse_const_iterator() noexcept;

          reverse_const_iterator& operator = (const reverse_const_iterator& rcitr) noexcept;
          reverse_const_iterator& operator = (reverse_const_iterator&& rval) noexcept;
          bool operator != (const reverse_const_iterator& rcitr) const noexcept;
          bool operator == (const reverse_const_iterator& rcitr) const noexcept;
          reverse_const_iterator& operator ++ () noexcept;
          reverse_const_iterator operator ++ (int dummy) noexcept;
          reverse_const_iterator& operator -- () noexcept;
          reverse_const_iterator operator -- (int dummy) noexcept;
          const char& operator * () const;
      };

      reverse_const_iterator crbegin() const;
      reverse_const_iterator crend() const;
  };
  void swap(string& lhs, string& rhs) noexcept;
} //kapil

#endif
