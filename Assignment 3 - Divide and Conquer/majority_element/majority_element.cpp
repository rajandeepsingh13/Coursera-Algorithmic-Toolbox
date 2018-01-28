#include <iostream>
using namespace std;

int poop(long long a[], int left, int right, int m){
   int lol=0;
   for(int i=left;i<=right;i++){
   	  if (a[i]==m){
		   lol++;
   	}
   }
   //cout<<m<<" "<<lol<<endl;
   return lol;
}


int get_majority_element(long long a[], int left, int right) {
  //cout<<left<<" "<<right<<endl;
  if (left > right) 
     return -1;
  if (left == right) 
     return -1;
  if (left + 1 == right) 
     return a[left];
  int majorL= get_majority_element(a,left,(right+left)/2);
  int majorR= get_majority_element(a,(right+left)/2+1,right);
  if(majorL==majorR)
     return majorL;
  if(poop(a,left,right,majorL)>int((right-left)/2)){
  	 //cout<<majorL<<endl;
  	 return majorL;
  }
  if(poop(a,left,right,majorR)>int((right-left)/2)){
  	 //cout<<majorL<<endl;
	   return majorR;
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
  if (get_majority_element(a,0,n)>0)
  cout << 1 << endl;
  else
  cout << 0 << endl;
}
