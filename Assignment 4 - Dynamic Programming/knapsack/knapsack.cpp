#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int optimal_weight(int W, int w[], int n) {
  int ncol=n+1;
  int nrow=W+1;
  int** vtable=(int**)malloc(ncol*sizeof(int*));
  for(int i=0; i<ncol;i++)
     vtable[i]=(int*)malloc(nrow*sizeof(int));
  int flag[W+1];
  for (int i=0;i<=n;i++){
  	for (int j=0;j<=W;j++){
  		flag[j]=0;
  		if(i==0||j==0)
  		    vtable[i][j]=0;
  		else{
  			if(w[i]<=j){
			  if (vtable[i][j-w[i]]+w[i]>vtable[i-1][j]){
			  	flag[j]=1;
			         if(flag[j-w[i]]==0){
				         vtable[i][j]=vtable[i][j-w[i]]+w[i];
				     }
				     else
					     vtable[i][j]=vtable[i][j-1]; 
			     }
			  else
			     vtable[i][j]=vtable[i-1][j];
  			}
  			else
  			  vtable[i][j]=vtable[i-1][j];
		  }
		//cout<<vtable[i][j]<<" ";
	  }
	  //cout<<endl;
  }
  return vtable[n][W];
}

int main() {
  int n, W;
  cin >> W >> n;
  int w[n+1];
  w[0]=-1;
  for (int i = 1; i <= n; i++) {
    cin >> w[i];
  }
  cout << optimal_weight(W, w,n) << '\n';
}
