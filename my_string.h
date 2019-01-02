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
      static constexpr std::size_t default_capacity_ = 16;
      std::size_t current_capacity_;
      std::size_t sz_;
      std::unique_ptr<char[]> ptr_;
    public:
      string();
      string(const string&);
      string(string&&) noexcept;
      string(const char*);
      explicit string(char);
      ~string() noexcept;

      std::size_t capacity() const noexcept;
      static std::size_t get_default_capacity() noexcept;
      std::size_t size() const noexcept;
      std::size_t length() const noexcept;
      void resize(std::size_t, char ch = '\0');
      void clear();
      bool empty() const noexcept;
      char& at(int);
      const char& at(int) const;
      char& back();
      const char& back() const;
      char& front();
      const char& front() const;
      string& append(const string&);
      string& append(const char*);
      string& append(string&&);
      string& append(char);
      void push_back(char);
      string& assign(const string&);
      string& assign(const char*);
      string& assign(string&&) noexcept;
      void swap(string&);
      const char* c_str() const noexcept;
      const char* data() const noexcept;

      
      
      string& operator = (const string&);
      string& operator = (string&&) noexcept;
      string& operator = (const char*);
      string& operator = (char);
      string& operator += (const string&);
      string& operator += (const char*);
      string& operator += (char);
      string& operator += (string&&);
      char& operator[] (int);
      const char& operator[] (int) const;

      friend std::ostream& operator << (std::ostream&, const string&);
      friend string operator + (const string&, const string&);
      friend string operator + (const string&, const char*);
      friend string operator + (const char*, const string&);
      friend string operator + (string&&, string&&);
      friend string operator + (string&&, const char*);
      friend string operator + (const char*, string&&);
      friend string operator + (const string&, string&&);
      friend string operator + (string&&, const string&);
      friend string operator + (const string&, char);
      friend string operator + (char, const string&);
      friend string operator + (string&&, char);
      friend string operator + (char, string&&);
      friend bool operator == (const string&, const string&) noexcept;
      friend bool operator == (const string&, const char*) noexcept;
      friend bool operator == (const char*, const string&) noexcept;
      friend bool operator == (const string&, char) noexcept;
      friend bool operator == (char, const string&) noexcept;
      friend bool operator == (const string&, string&&) noexcept;
      friend bool operator == (string&&, const string&) noexcept;
      friend bool operator == (string&&, string&&) noexcept;
      friend bool operator == (string&&, char) noexcept;
      friend bool operator == (char, string&&) noexcept;
      friend bool operator == (const char*, string&&) noexcept;
      friend bool operator == (string&&, const char*) noexcept;
      friend bool operator != (const string&, const string&) noexcept;
      friend bool operator != (const string&, const char*) noexcept;
      friend bool operator != (const char*, const string&) noexcept;
      friend bool operator != (const string&, char) noexcept;
      friend bool operator != (char, const string&) noexcept;
      friend bool operator != (const string&, string&&) noexcept;
      friend bool operator != (string&&, const string&) noexcept;
      friend bool operator != (string&&, string&&) noexcept;
      friend bool operator != (string&&, char) noexcept;
      friend bool operator != (char, string&&) noexcept;
      friend bool operator != (const char*, string&&) noexcept;
      friend bool operator != (string&&, const char*) noexcept;

      class iterator
      {
        private:
          string* str_;
          int index_;
        public:
          iterator(string* = nullptr, int = 0) noexcept;
          iterator(const iterator&) noexcept;
          iterator(iterator&&) noexcept;
          ~iterator() noexcept;

          iterator& operator = (const iterator&) noexcept;
          iterator& operator = (iterator&&) noexcept;
          bool operator != (const iterator&) const noexcept;
          bool operator == (const iterator&) const noexcept;
          iterator& operator ++ () noexcept;
          iterator operator ++ (int) noexcept;
          iterator& operator -- () noexcept;
          iterator operator -- (int) noexcept;
          char& operator * () const;
      };

      iterator begin();
      iterator end();

      class const_iterator
      {
        private:
          const string* str_;
          int index_;
        public:
          const_iterator(const string*, int) noexcept;
          const_iterator(const const_iterator&) noexcept;
          const_iterator(const_iterator&&) noexcept;
          ~const_iterator() noexcept;

          const_iterator& operator = (const const_iterator&) noexcept;
          const_iterator& operator = (const_iterator&&) noexcept;
          bool operator != (const const_iterator&) const noexcept;
          bool operator == (const const_iterator&) const noexcept;
          const_iterator& operator ++ () noexcept;
          const_iterator operator ++ (int) noexcept;
          const_iterator& operator -- () noexcept;
          const_iterator operator -- (int) noexcept;
          const char& operator * () const;
      };

      const_iterator cbegin() const;
      const_iterator cend() const;

      class reverse_iterator
      {
        private:
          string* str_;
          int index_;
        public:
          reverse_iterator(string* = nullptr, int = 0) noexcept;
          reverse_iterator(const reverse_iterator&) noexcept;
          reverse_iterator(reverse_iterator&&) noexcept;
          ~reverse_iterator() noexcept;

          reverse_iterator& operator = (const reverse_iterator&) noexcept;
          reverse_iterator& operator = (reverse_iterator&&) noexcept;
          bool operator != (const reverse_iterator&) const noexcept;
          bool operator == (const reverse_iterator&) const noexcept;
          reverse_iterator& operator ++ () noexcept;
          reverse_iterator operator ++ (int) noexcept;
          reverse_iterator& operator -- () noexcept;
          reverse_iterator operator -- (int) noexcept;
          char& operator * () const;
      };

      reverse_iterator rbegin();
      reverse_iterator rend();

      class reverse_const_iterator
      {
        private:
          const string* str_;
          int index_;
        public:
          reverse_const_iterator(const string*, int) noexcept;
          reverse_const_iterator(const reverse_const_iterator&) noexcept;
          reverse_const_iterator(reverse_const_iterator&&) noexcept;
          ~reverse_const_iterator() noexcept;

          reverse_const_iterator& operator = (const reverse_const_iterator&) noexcept;
          reverse_const_iterator& operator = (reverse_const_iterator&&) noexcept;
          bool operator != (const reverse_const_iterator&) const noexcept;
          bool operator == (const reverse_const_iterator&) const noexcept;
          reverse_const_iterator& operator ++ () noexcept;
          reverse_const_iterator operator ++ (int) noexcept;
          reverse_const_iterator& operator -- () noexcept;
          reverse_const_iterator operator -- (int) noexcept;
          const char& operator * () const;
      };

      reverse_const_iterator crbegin() const;
      reverse_const_iterator crend() const;
  };
  void swap(string&, string&) noexcept;
} //kapil

#endif
