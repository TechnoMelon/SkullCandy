#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
void getarr(){
int arr[25],n;
printf("\nHow many element you want to insert in Array:- ");
scanf("%d",&n);
for(int i=0;i<n;i++){
printf("\nEnter the elements %d to insert:- ",i);
scanf("%d",&arr[i]);
}

}
void bubblesort(int arr[25],int n)
{
int i,j,temp;
for(i=0;i<n;i++)
{
for(j=0;j<n-1;j++)
{
if(arr[j]>arr[j+1])
{
temp=arr[j];
arr[j]=arr[j+1];
arr[j+1]=temp;
}
}
}
}
void insertionSort(int arr[25],int n)
{
int i, key, j;
for (i = 1; i < n; i++)
{
key = arr[i];
j = i - 1;
while (j >= 0 && arr[j] > key)
{
arr[j + 1] = arr[j];
j = j - 1;
}
arr[j + 1] = key;
}

}
void orph()
{
int arr[25],n,status;
int pid=fork();
if(pid==0)
{
sleep(10);
printf("\nchild process\n");
printf("child process id=%d\n",getpid());
insertionSort(arr,n);
printf("\nElements Sorted Using Insertion Sort");
printf("\n");
for(int i=0;i<n;i++)
printf("%d,",arr[i]);
printf("\b");
printf("\nparent process id=%d\n",getppid());
system("ps -x");
}
else
{
//sleep(10);
printf("\nparent process\n");
printf("\nparent process id=%d\n",getppid());
bubblesort(arr,n);
printf("Elements Sorted Using Bubble Sort");
printf("\n");
for(int i=0;i<n;i++)
printf("%d,",arr[i]);
printf("\n\n\n");

}
}
int main()
{
getarr();
orph();
return 0;
}
