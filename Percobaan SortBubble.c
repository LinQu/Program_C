#include<stdio.h>

typedef int larikInt[6];

void BubbleSort(larikInt L, int n){
	// n adalah kapasitas array = 6
	int pass;
	int k;
	int temp;
	
	for(pass = 0; pass<= n-2; pass++){
		for(k = n-1; k >= pass+1; k--){
			if (L[k] > L[k-1]){
				temp = L[k];
				L[k] = L[k-1];
				L[k-1] = temp;
			}
		}
	}
}

void cetakArray(larikInt A, int n){
	int i;
	printf("\njml : %d\n", n);
	for(i=0; i < n; i++){
		printf("isi index %d : %d\n",i,A[i]);
	}
}

void inputArray(larikInt Y, int n){
	int i;
	for(i=0;1 < n; i++){
		printf("Index ke - %d : ",i);
		scanf("%d",&Y[i]);
	}
}

void main(){
	larikInt LArray = {25,27,10,8,76,21};
	int jml;
	jml = 6;
	cetakArray(LArray, jml);
	
	BubbleSort(LArray, jml);
	
	cetakArray(LArray,jml);
}
