#include "my_string.h"

using namespace kapil;

int main() {
  string z1;
  string z2{"kapil dev singh z2 declared"};
  string z3{z2};
  string z4 = z3;
  string z5{string{"kapil dev singh move constructed"}};
  string z6{"kapil dev singh constructed from const char*"};
  string z7 = "kapil dev singh const char*";
  string z8 = string{'c'};
  string z9 = "kapil dev singh I am made from const char*";
  std::cout << "\n z1 : " << z1 << "\n z2 : " << z2 << "\n z3 : " << z3 << "\n z4 : " << z4 << "\n z5 : " << z5 << "\n z6 : " << z6 << "\n z7 : " << z7 << "\n z8 : " << z8 << "\n z9 : " << z9 << std::endl;
  
  z7.resize(13, 'r');
  z2.clear();
  std::cout << " z7.at(10) : " << z7.at(10) << std::endl;
  std::cout << " z7.back() : " << z7.back() << std::endl;
  std::cout << " z7.front() : " << z7.front() << std::endl;
  z3.append(z4);
  z3.append("appended z4 and this string");
  z3.append(string{"append rval"});
  z3.append('c');
  z3.push_back('p');
  z2.assign(z6);
  std::cout << "\n z7 : " << z7 << "\n z3 : " << z3 << "\n z2 : " << z2 << std::endl;
  z2.assign(string{"assign using move"});
  z2.swap(z7);

  z2 = z4;
  z4 = string{"move assignment"};
  z5 = 'a';
  z5 += z2;
  z2 += "z2 calls +=";
  z3 += string{"kapil dev singh"};
  z1 = z2 + z3;
  z2 = z3 + "This is binary add";
  z4 = "this is binary add" + z5;
  z5 = z3 + 'x';
  z5 = 'x' + z4;
  z6 = string{"hello"} + " const char*";
  z7 = z3;
  if (z7 == z3) {
    std::cout << "same\n";
  }

  if (z1 != z7) {
    std::cout << "different\n";
  }

  z1 = "kapil dev singh";

  std::cout << "\n range for \n";

  for (const auto& it : z1) {
    std::cout << it;
  }

  std::cout << "\n iter loop\n";

  for (auto it = z1.begin(); it != z1.end(); ++it) {
    std::cout << *it;
  }


  std::cout << "\n rev iter loop\n";

  for (auto it = z1.crbegin(); it != z1.crend(); ++it) {
    std::cout << *it;
  }

  std::cout << std::endl;

  string z10 = 'k';

  string z11 = "kapil";
  string z12 = "kapil";
  z12 += '\0';
  z12 += 'k';
  z11 += '\0';
  z11 += 'a';

  string z14;
  z14 = z11 + z12;
  z11.append(string{"_appended"});
  z10.assign(string{"_assigned"});

  std::cout  << " z11 : " << z11 << " z12 : " << z12 << std::endl;
  string z13 = "kapil";
  z13 += string{" repeat kapil"};

  std::cout << "(z11 < z12)  : " << (z11 < z12) << "  z11 == z12 : " << (z11 == z12) << "  z11 != z12 : " << (z11 != z12) << "  (z11 < strin{arjun} : " << (z11 < string{"zrjun"}) << "  (z11 < x) : " << (z11 < 'x') << " z12 != string{kapila} : " << (z12 != string{"kapila"}) << " z12 > z11 : " << (z12 > z11) << " z12 > string{apple} : " << (z12 > string{"apple"})  <<  " z13 : " << z13 << std::endl;

  std::cout << " (z11 + z12 ) : " << z11 + z12 << " << z11 + string{kapil} : " << z11 + string{"kapil"} << " z10 : " << z10 <<std::endl;


  string x{"kapil"};
  std::cout << " size : " << x.size() << " length : " << x.length() << " is empty : " << x.empty() << " at 2 : " << x.at(2) << " back : " << 
    x.back() << " c_str : " << x.c_str() << " data : " << x.data() << std::endl;
  x.clear();
  x = "dev";
  string y{" singh"};
  x.append(y);
  x.append(" is");
  y.assign(" assigned");
  x += " operator +";
  x += y;

  std::cout << " x : " << x << "  x cap : " << x.capacity() << "\n y : " << y << "  y cap : " << y.capacity() << std::endl;
  string added = "i am binary + " + y + string{" ravl add "} + 'x';
  std::cout << " added : " << added << " added cap : " << added.capacity() << std::endl;
  added = "kapil";
  added.resize(100, 'k');
  std::cout << " added resize 100 : " << added << " added cap : " << added.capacity() << std::endl;
  added.resize(7, 'l');
  std::cout << " added resize 7 : " << added << " added cap : " << added.capacity() << std::endl;
  string s1234 = "kapil";
  s1234.swap(added);
  std::cout << " added : " << added << " s1 : " << s1234 << std::endl;

  for (auto it : s1234) {
    std::cout << it << " ";
  }



  std::cout << "\n";
  string x1{"hey man"};
  std::cout << x1;
  
  std::cout << " start : \n";
  //string s98 = string{"hello"} + string{" brother"};
  std::cout << " start : \n";
  string s132{"hello"};
  string s2;
  s2 = std::move(s1234);
  string s3 = string{"brother"};
  string s4{s3};
  string s5{""};
  s5 = "batloluaaa";
  s5 += s3;
  s3 += " i am added to s3 as const char*";
  s4 += string{" i am added as rval "};
  s4 = s3 + s5 + " s3 + s5";
  s3 = s5 + " i am s5 + const char*";
  s2 = " i am const char* + s5" + s5;
  string s1{'x'};
  s1 = s2 + 'a';
  s1 = "kapil";
  s1[0] = 's';
  s1.back() = '$';
  s1.at(3) = '*';
  s1.front() = '~';
  s1.append('f');
  s1.append("aswd");
  s1.assign("char* assigned");
  s3.assign(s2);
  std::cout << "\n should call move \n";
  s4.assign(string{"moved"});
  std::cout << "\n called move \n";

  if (s1 != s4) {
    std::cout << " s1 != s2 \n";
  }

  s2 = s4 = {"same"};

  if (s2 == s4) {
    std::cout <<" s2 == s4 and same \n";
  }

  auto it53 = s2.cbegin();
  auto it75 = s2.cbegin();
  it75 = it53;

  std::cout << "\n reverse loop start \n";
  for (auto it = s2.rbegin(); it != s2.rend(); ++it) {
    std::cout << *it;
  }
  std::cout << "\n reverse loop end \n";
  std::cout << "\n const reverse loop start \n";
  for (auto it = s2.crbegin(); it != s2.crend(); ++it) {
    std::cout << *it;
  }
  std::cout << "\n const reverse loop end \n";

  std::cout << " s1 : " << s1 << std::endl << " s2 : " << s2 << std::endl << " s3 : " << s3 << std::endl << " s4 : " << s4 << std::endl << " s5 : " << s5 << std::endl;

  s1 = s2;

  if (s1 == string{s2}) {
    std::cout << " s1 is same as temp s2 \n";
  }
  return 0;
}
