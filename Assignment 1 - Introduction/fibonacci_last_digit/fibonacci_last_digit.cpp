#include <iostream>

int get_fibonacci_last_digit(int n) {
    int a[n];
    a[0]=1;
    a[1]=1;
	for(int i=2;i<n;i++)
    	a[i]=(a[i-2]+a[i-1])%10;
    return a[n-1];
}

int main() {
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit(n);
    std::cout << c << '\n';
    }
