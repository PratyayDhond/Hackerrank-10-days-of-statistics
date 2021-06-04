	#include <cmath>
	#include <cstdio>
	#include <vector>
	#include <iostream>
	#include <algorithm>
	using namespace std;
	
	
	int main() {
	    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
		int n;
		cin>>n;
		double median;
		double mean;
		long long int mode;
		int x[n];
		
		int sum = 0;
		for(int i =0;i<n;i++){
			cin>>x[i];
			sum += x[i];
		}
		
		mean = sum/float(n);
		cout<<mean;
		
		
		for(int i=1;i<n;i++){
			int j = i-1;
			int key = x[i];
			while(j>=0 && x[j] > key){
				x[j+1] = x[j];
				j--;
			}
			x[j+1]=key;
		}
		if(n%2==0){
			median = (x[n/2] + x[n/2-1])/float(2);
			cout<<endl<<median;
		}else{
			median = (x[n/2]);
			cout<<endl<<median;
		}

		int countMax = 0;
		int countMaxNo = x[0];
		int count = 0;
		for(int i=0;i<n;i++){
			
			count = 0;
			for(int j=i+1;j<n;j++){
				if(x[i] == x[j]){
					count++;
				}else{
					i = j-1;
					break;				//why break? as array is sorted if the number isn't equal to the ith element, no later no. will be so thus breaking the loop. 
				}
			}
			if(count == countMax && x[i] < countMaxNo){
					
					countMaxNo = x[i];
					
			}
			if(count>countMax){
				countMaxNo = x[i];
				countMax = count;
			}
		
	}
	cout<<endl<<countMaxNo;
		
		
	return 0;
	}
