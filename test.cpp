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

  std::cout << " x : " << x << "  x cap : " << x.capacity() << "\n y : " << y << "  y cap : " << y.capacity() << std::endl;
  string added = "i am binary + " + y + string{" ravl add "} + 'x';
  std::cout << " added : " << added << " added cap : " << added.capacity() << std::endl;
  added = "kapil";
  added.resize(10, 'k');
  std::cout << " added resize 10 : " << added << " added cap : " << added.capacity() << std::endl;
  added.resize(78, 'l');
  std::cout << " added resize 78 : " << added << " added cap : " << added.capacity() << std::endl;
  string s1 = "kapil";
  s1.swap(added);
  std::cout << " added : " << added << " s1 : " << s1 << std::endl;

  for (auto it : s1) {
    std::cout << it << " ";
  }

  std::cout << "\n";
  return 0;
}
