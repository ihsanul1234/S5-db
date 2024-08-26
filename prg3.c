#include<stdio.h>
void main()
{
	int burst_time[20],process[20],waiting_time[20],turnaround_time[20],priority[20];
	int i,j,limit,position,temp,sum=0;
	float average_wait_time=0,average_turnaround_time;
	printf("Enter the total no. of process:");
	scanf("%d",&limit);
	printf("\nEnter burst time and priority for %d process\n",limit);
	for(i=0;i<limit;i++)
	{
		printf("\nprocess ID : %d\n",i+1);
		printf("process burst time :\t");
		scanf("%d",&burst_time[i]);
		printf("Process priority :\t");
		scanf("%d",&priority[i]);
	}
	for(i=0;i<limit;i++)
	{
		position=i;
		for(j=i+1;j<limit;j++)
		{
			if(priority[j]<priority[position])
			{
				position=j;
			}
		}
		temp=priority[i];
		priority[i]=priority[position];
		priority[position]=temp;
		temp=burst_time[i];
		burst_time[i]=burst_time[position];
		burst_time[position]=temp;
		temp=process[i];
		process[i]=process[position];
		process[position]=temp;
	}
	waiting_time[0]=0;
	for(i=1;i<limit;i++)
	{
		waiting_time[i]=0;
		for(j=0;j<i;j++)
		{
			waiting_time[i]=waiting_time[i]+burst_time[j];
		}
		sum=sum+waiting_time;
	}
	average_wait_time=sum/limit;
	sum=0;
	printf("\nProcess ID\t\tBurst Time\tWaiting Time\tTurnaround Time\n");
	for(i=0;i<limit;i++)
	{
		turnaround_time[i]=burst_time[i]+waiting_time[i];
		sum=sum+turnaround_time[i];
		printf("\n%d\t\t\t%d\t\t%d\t\t%d\n",process[i],burst_time[i],waiting_time[i],turnaround_time[i]);
	}
	average_turnaround_time=sum/limit;
	printf("\nAverage waiting time : %f",average_wait_time);
	printf("\nAverage Turnaround Time : %f\n",average_turnaround_time);
}
