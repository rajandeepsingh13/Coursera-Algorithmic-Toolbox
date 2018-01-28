#include <iostream>

int get_change(int m) {
  int n,c10=0,c5=0,c1=0;
  c10=m/10;
  m=m%10;
  if(m>=5){
  	c5=1;
  	m=m-5;
  }
  c1=m;
  n=c10+c5+c1;
  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
