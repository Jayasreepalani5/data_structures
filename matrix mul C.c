#include<stdio.h>
int main()
{
	int mat1[2][2]={{1,2},{3,4}};
	int mat2[2][2]={{5,6},{7,8}};
	int result[2][2]={0};
	int i;
	for(i=0;i<2;i++){
		for(int j=0;j<2;j++){
			for(int k=0;k<2;k++){
				result[i][j]+=mat1[i][k]*mat2[k][j];
			}
		}
	}
	printf("matrix 1:\n");
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			printf("%d",mat[i][j]);
		}
		printf("\n");
	}
	printf("matrix 2:\n");
	for(int i=0;i<2;i++){-
		for(int j=0;j<2;j++){
			printf("%d",mat2[i][j]);
		}
		printf("\n");
	}
	printf("result matrix:\n");
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			printf("%d",result[i][j]);
		}
		printf("\n");
	}
	return 0;
}
