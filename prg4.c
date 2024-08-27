/*round robin scheduling*/
#include<stdio.h>
void main()
{
	int i,limit,total=0,x,counter=0,time_quantum;
	int wait_time=0,turnaround_time=0,arrival_time[10],burst_time[10],temp[10];
	float average_wait_time,average_turnaround_time;
	
	printf("\nEnter total number of process : ");
	scanf("%d",&limit);
	x=limit;
	for(i=0;i<limit;i++)
	{
		printf("Enter details of the process[%d]\n",i+1);
		printf("Arrival time :");
		scanf("%d",&arrival_time[i]);
		printf("Burst time :");
		scanf("%d",&burst_time[i]);
		temp[i]=burst_time[i];
	}
	printf("\nEnter time quantum :\t");
	scanf("%d",&time_quantum);
	printf("\nprocess ID\t\tBurst Time\tTurnaround time\tWaiting time\n");
	for(i=0;x!=0;i)
	{
		if(temp[i]<=time_quantum&&temp[i]>0)
		{
			total=total+temp[i];
			temp[i]=0;
			counter=1;
		}
		else if(temp[i]>0)
		{
			temp[i]=temp[i]-time_quantum;
			total=total+time_quantum;
		}
		if(temp[i]==0&&counter==1)
		{
			x--;
			printf("\nprocess[%d]\t\t%d\t\t%d\t\t%d",i+1,burst_time[i],total-arrival_time[i],total-arrival_time[i]-burst_time[i]);
			wait_time=wait_time+total-arrival_time[i]-burst_time[i];
			turnaround_time=turnaround_time+total-arrival_time[i];
			counter=0;
		}
		if(i==limit-1)
		{
			i=0;
		}
		else if(arrival_time[i+1]<=total)
		{
			i++;
		}
		else
		{
			i=0;
		}
	}
	average_wait_time=wait_time*1.0/limit;
	average_turnaround_time=turnaround_time*1.0/limit;
	printf("\nAverage waiting time : %f  ",average_wait_time);
	printf("\nAverage Turnaround time : %f\n",average_turnaround_time);
}
