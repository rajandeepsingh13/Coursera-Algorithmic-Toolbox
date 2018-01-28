#include <iostream>
using namespace std;

int binary_search(long long a[], int x,int start, int end) {
  int mid=(start+end)/2;
  if(start>=end)
    return -1;
  else if (x==a[mid]){
  	return mid;
  }
  else if(x<a[mid]){
  	end= mid;
  	return binary_search(a,x,start,end);
  }
  else {
  	start=mid+1;
  	return binary_search(a,x,start,end);
  }
  
}

int linear_search(int a[], int x,int end) {
  for (size_t i = 0; i < end; ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  cin >> n;
  long long a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int m;
  cin >> m;
  long long b[m];
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  for (int i = 0; i < m; i++) {
    cout << binary_search(a, b[i],0,n) << ' ';
  }
}
