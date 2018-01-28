#include <iostream>
#include <iomanip>
using namespace std;
/*
double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;

  // write your code here

  return value;
}

void Merge(int *a, int low, int high, int mid)
{
	int i, j, k, temp[high-low+1];
	i = low;
	k = 0;
	j = mid + 1;	
	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}
	while (i <= mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	}
	while (j <= high)
	{
		temp[k] = a[j];
		k++;
		j++;
	}
	for (i = low; i <= high; i++)
	{
		a[i] = temp[i-low];
	}
}
 
void MergeSort(int *a, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid=(low+high)/2;
		MergeSort(a, low, mid);
		MergeSort(a, mid+1, high);
		Merge(a, low, high, mid);
	}
}
*/ 
void swap(int *a, int *b){
	int temp;
	temp=*a;
	a=b;
	*b=temp;
}
int main() {
  int n;
  int max_mass;
  double max_val=0;
  cin >> n >> max_mass;
  int value[n], mass[n],index[n];
  double rate [n];
  for (int i = 0; i < n; i++) {
    cin >> value[i] >> mass[i];
    rate[i]=double (value[i])/mass[i];
    index[i]=i;
  }
//  MergeSort(rate,0,n-1);
  for  (int i=0;i<n;i++){
  	for(int j=i+1;j<n;j++){
  		if(rate[i]<rate[j]){
		    swap(rate[i],rate[j]);
		    swap(index[i],index[j]);
		  }
	  }
  }
  for(int i=0;max_mass>0&&i<n;i++){
  	 if (mass[index[i]]<=max_mass){
  		max_val=max_val+value[index[i]];
  		max_mass=max_mass-mass[index[i]];
	  }
	  else{
	  	max_val+=rate[i]*max_mass;
	  	max_mass=0;
	  	break;
	  }
  }
  //double optimal_value = get_optimal_value(capacity, weights, values);

  cout<<fixed;
  cout.precision(4);
  cout << max_val << endl;
  return 0;
}
