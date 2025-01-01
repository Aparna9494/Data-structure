#include<stdio.h>
#include<stdlib.h>
int main(){
int a1[100],a2[100];
int a1_size,a2_size;
int i,j;
int temp;
int total;
int size=0;
printf("enter the no of elements in the array");
scanf("%d",&a1_size);
printf("enter the  %d elements",a1_size);
for(i=0;i<a1_size;i++){
	printf("a1[%d]:",i+1);
	scanf("%d",&a1[i]);
}
printf("enter the no of elements in the array");
scanf("%d",&a2_size);
printf("enter the  %d elements",a2_size);
for(i=0;i<a2_size;i++){
	printf("a2[%d]:",i+1);
	scanf("%d",&a2[i]);
}
total=a1_size+a2_size;
for(i=a1_size;i<total;i++){
	a1[i]=a2[size];
	size=size+1;
}
for(i=total;i>0;i--){
	for (j=0;j<total-1;j++){
	if(a1[j]>a1[j+1]){
	temp=a1[j];
	a1[j]=a1[j+1];
	a1[j+1]=temp;
	}
}
}
printf("the sorted array is");
for(i=0;i<total;i++){
printf("array[%d] :%d",i,a1[i]);
}
return 0;
}

	


