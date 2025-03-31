#include<stdio.h>
#include<conio.h>
int main(){
	int a[2][2],b[2][2],sum[2][2];
	
	printf("=> Enter Elements OF A : \n");
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			printf("Enter Elements A[%d] : ",i);
			scanf("%d",&a[i][j]);
		}	
	}
	
	printf("=> Enter Elements B : \n");
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			printf("Enter Elements B[%d] : ",i);
			scanf("%d",&b[i][j]);
		}	
	}
	
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			sum[i][j]=a[i][j]+b[i][j];
		}	
	}
	
	printf("Sum Of Elements :\n");
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			printf("%d ",sum[i][j]);
		}
		printf("\n");	
	}
	
	return 0;
}
