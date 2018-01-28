#include <iostream>

using namespace std;

int min(int a, int b, int c){
	if(a<=b&&a<=c)
	   return a;
	if(b<a&&b<=c)
	   return b;
	if(c<a&&c<b)
	   return c;
}

int min_mod(int a, int b, int c){
	if(a<=b&&a<=c)
	   return 1;
	if(b<a&&b<=c)
	   return 2;
	if(c<a&&c<b)
	   return 3;
}

int calculate_steps(int steps[],int i){
	int temp1,temp2,temp3;
	if(i%3==0)
  	  temp3=i/3;
  	else temp3=0;
  	if(i%2==0)
  	temp2=i/2;
  	else
  	temp2=0;
  	temp1=i-1;
  	int ans;
	ans=min(steps[temp3],steps[temp2],steps[temp1])+1;
	return ans;
}

int calculate_steps_mod(int steps[],int i){
	int temp1,temp2,temp3;
	if(i%3==0)
  	  temp3=i/3;
  	else temp3=0;
  	if(i%2==0)
  	temp2=i/2;
  	else
  	temp2=0;
  	temp1=i-1;
  	int ans;
	ans=min_mod(steps[temp3],steps[temp2],steps[temp1]);
	if(ans==1)
	return temp3;
	if(ans==2)
	return temp2;
	if(ans==3)
	return temp1;
	}

void flashback(int steps[],int n){
   	int values[steps[n]+1];
   	values[0]=n;
   	for(int i=1;i<steps[n]+1;i++){
   		values[i]=calculate_steps_mod(steps,values[i-1]);
	   }
	for(int i=steps[n];i>=0;i--){
		cout<<values[i]<<" ";
	}
}

int main() {
  int n;
  cin >> n;
  int steps[n+1];
  steps[0]=99999;
  steps[1]=0;
  for (int i=2;i<n+1;i++){
	  steps[i]=calculate_steps(steps,i);
  }
  cout<<steps[n]<<endl;
  flashback(steps,n);
}
