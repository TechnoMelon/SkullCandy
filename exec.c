#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void quicksort(int [10],int,int);
void main()
{
int pid, ppid, a[10], size, i;
char *argv[12];
for(i=0; i<12; i++)
{
argv[i] = (char *) malloc(20);
}
printf("\n In the main of parent process.My process-id is %d ",getpid());
printf("\n Enter the number of elements in the array: ");
scanf("%d", &size);
printf("Enter %d elements: ",size);
for(i=0;i<size;i++)
scanf("%d",&a[i]);
quicksort(a, 0, size-1);
printf("Sorted elements: ");
for(i=0;i<size;i++)
printf(" %d",a[i]);
printf("\n PARENT: I am calling my child for searching now!");
printf("\n -------------------");
pid = fork(); //Here, the child process is created and both child & parent run//simultaneously. fork() returns 0 to child process and pid of
//child to parent process. So, if intpid here is 0, it means we are in child process and if any +ve no., then in parent process where
//the +ve no. is the child's pid.
if(pid==0)
{
printf("CHILD: In child process. My process-id is %d \n",getpid());
printf("CHILD: My parent's process-id is %d \n",getppid());
printf("\n CHILD: Calling searching program using execv now. I will be overlayed!");
for(i=0; i<size; i++)
{
sprintf(argv[i+1], "%d", a[i]);
}
argv[0] = "./bsearch";
argv[size+2] = NULL;
execv("./bsearch", argv);//int execv(const char *path, char *const argv[]);
printf("Error");
printf("\n CHILD: I am dying now\n");
printf("------------------\n\n");
}
else if (pid>0)
{
system("wait");
printf("\nPARENT: I am dying now\n");
printf("-----------------------");
printf("\n\n.");
}
}

void quicksort(int a[10],int first,int last)
{
int pivot,j,temp,i;
if(first<last)
{
pivot=first;
i=first;
j=last;
while(i<j){
while(a[i]<=a[pivot]&&i<last)
i++; while(a[j]>a[pivot]) j--;
if(i<j){
temp=a[i];
a[i]=a[j];
a[j]=temp;
}
}
temp=a[pivot];
a[pivot]=a[j];
a[j]=temp;
quicksort(a,first,j-1);
quicksort(a,j+1,last);
}
}



