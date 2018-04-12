#include<stdio.h>
#include<unistd.h>
int empty ;

struct process {
	int req ;
	int allo;
	int need;//need=req-allo;
} z[20];

void intake(int p,int c);
void checker(int e,int f);
void safecheck(int d);

int main()
{	int q,i,p;

	printf("Welcome user please enter the number of processes");
	scanf("%d",&q);
	printf("Please enter the number of resources");
	scanf("%d",&p);
	empty=p;
	printf("For each process please define the following :-\n");
	for(i=0;i<q;i++)
	{
		intake(i,p);
	}
	checker(q,p);
	
}

void intake(int p,int c)
{	int a1,a2;
	printf("Max requirement of process %d ",p+1);
	
	scanf("%d",&a1);
	
	if(a1>c)
	{
		printf("Sorry but requirement cannot be greater than resources - enter again\n\n");
		scanf("%d",&a1);
		
	}
	printf("Pre-Allocation of process %d ",p+1);
	scanf("%d",&a2);
	if(a2>a1)
	{
		printf("No need to allocate more than requirement -> making allocation = requirement\n\n");
		a2=a1;
	}

	z[p].req=a1;
	z[p].allo=a2;
	z[p].need=z[p].req-z[p].allo;
	empty=empty-a2;
	printf("%d",empty);
}

void safecheck(int d)
{
	int safeSeq[d];
	int count = 0,i; 
	int fin[d];
	fin[0]=0;
	while(count<d)
	{
		int find = 0;
		for (i = 0; i < d; i++)
        {
        	if (fin[i] == 0)
        	{
			
        		if (z[i].need > empty)
        			break;
        		else
					{empty=empty+z[i].allo;
					z[i].allo=0;
					fin[i]=1;
					safeSeq[count++] = i;
					find=1;
					}
			}
		}
		if (find == 0)
        {
            printf("System not in safe state");
      
        }
	}
  printf("System is in safe state");
  
}

void checker(int e,int f)
{
	int q=0,i;
	for(i=0;i<e;i++)
	{
		q=q+z[i].req;
	}
	if(q<e+f)
	{
		safecheck(e);
	}
	else
	{
		printf("System is in unsafe state");
	}
}