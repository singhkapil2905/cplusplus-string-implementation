#include "my_string.h"

using namespace kapil;

int main() {
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

  std::cout << " x : " << x << "  \n y : " << y << std::endl;
  string added = "i am binary + " + y + string{" ravl add "} + 'x';
  std::cout << " added : " << added << std::endl;
/*  string x1{"hey man"};
  std::cout << x1;
  
  std::cout << " start : \n";
  //string s98 = string{"hello"} + string{" brother"};
  std::cout << " start : \n";
  string s1{"hello"};
  string s2;
  s2 = std::move(s1);
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
  s4.swap(s1);
  std::cout << "\n start of loop \n";
  for (auto it : s1) {
    std::cout << it;
  }
  std::cout << "\n end of loop \n";

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
  }*/
  return 0;
}
