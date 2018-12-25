#ifndef MY_STRING_H_
#define MY_STRING_H_

#include <cstring>
#include <iostream>
#include <memory>
#include <algorithm>
#include <stdexcept>

namespace kapil {
  class string final {
    private:
      std::unique_ptr<char[]> ptr_;
      size_t sz_;
    public:
      string() noexcept;
      string(const string&);
      string(string&&) noexcept;
      explicit string(const char*);
      explicit string(char);
      ~string();

      size_t size() const noexcept;
      size_t length() const noexcept;
      void resize(size_t, char ch = '\0');
      void clear() noexcept;
      bool empty() const noexcept;
      char& at(size_t);
      const char& at(size_t) const;
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
      string& assign(string&&);
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
      char& operator[] (size_t);
      const char& operator[] (size_t) const;

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
      friend bool operator == (const string&, const string&);
      friend bool operator == (const string&, const char*);
      friend bool operator == (const char*, const string&);
      friend bool operator == (const string&, char);
      friend bool operator == (char, const string&);
      friend bool operator == (const string&, string&&);
      friend bool operator == (string&&, const string&);
      friend bool operator == (string&&, string&&);
      friend bool operator == (string&&, char);
      friend bool operator == (char, string&&);
      friend bool operator == (const char*, string&&);
      friend bool operator == (string&&, const char*);
      friend bool operator != (const string&, const string&);
      friend bool operator != (const string&, const char*);
      friend bool operator != (const char*, const string&);
      friend bool operator != (const string&, char);
      friend bool operator != (char, const string&);
      friend bool operator != (const string&, string&&);
      friend bool operator != (string&&, const string&);
      friend bool operator != (string&&, string&&);
      friend bool operator != (string&&, char);
      friend bool operator != (char, string&&);
      friend bool operator != (const char*, string&&);
      friend bool operator != (string&&, const char*);

      class iterator
      {
        private:
          string* str_;
          size_t index_;
        public:
          iterator(string* = nullptr, size_t = 0);
          iterator(const iterator&);
          iterator(iterator&&) noexcept;
          ~iterator();

          iterator& operator = (const iterator&);
          iterator& operator = (iterator&&) noexcept;
          bool operator != (const iterator&) const noexcept;
          bool operator == (const iterator&) const noexcept;
          iterator& operator ++ ();
          iterator& operator ++ (int);
          iterator& operator -- ();
          iterator& operator -- (int);
          char& operator * () const;

      };

      iterator begin();
      iterator end();
      iterator cbegin();
      iterator cend();
  };
} //kapil

#endif
