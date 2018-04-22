// typeid, typeinfo

#include <iostream>
using std::cout;


#include <typeinfo>

class CDummy { };

 

int main () {

  CDummy* a;
  CDummy b;

  if (typeid(*a) != typeid(b))

  {

    cout << "a e b sao de tipos diferentes:\n";
    cout << "a e: " << typeid(a).name() << '\n';
    cout << "b e: " << typeid(b).name() << '\n';

  }
  else
  {
    cout<< "São iguais\n";
  }

  return 0;

}
