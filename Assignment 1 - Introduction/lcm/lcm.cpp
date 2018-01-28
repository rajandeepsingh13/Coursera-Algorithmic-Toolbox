#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

int gcd_fast(int a, int b){
	if(a==0)
	  return b;
    if(b==0)
	  return a;
	a=a%b;
	return gcd_fast(b,a);
}

int main() {
  int a, b;
  std::cin >> a >> b;
  //std::cout << lcm_naive(a, b) << std::endl;
  long long gcd=gcd_fast(a, b);
  long long a1=a;
  long long b1=b;
  std::cout << a1*b1/gcd<< std::endl;
  return 0;
}
