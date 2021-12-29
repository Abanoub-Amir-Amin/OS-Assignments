//Preemptive algorithm.

#include<stdio.h>
 
struct process
{
      char processName;
      int AT, BT, ct, WT, TAT, priority;
      int status;
}process_queue[10];
 
int limit;
 
void AT_Sorting()
{
      struct process temp;
      int i, j;
      for(i = 0; i < limit - 1; i++)
      {
            for(j = i + 1; j < limit; j++)
            {
                  if(process_queue[i].AT > process_queue[j].AT)
                  {
                        temp = process_queue[i];
                        process_queue[i] = process_queue[j];
                        process_queue[j] = temp;
                  }
            }
      }
}
 
void main()
{
      int i, time = 0, BT = 0, largest;
      char c;
      float wait_time = 0, TAT = 0, average_WT, average_TAT;
      printf("\nEnter Total Number of Processes:\t");
      scanf("%d", &limit);
      for(i = 0, c = 'A'; i < limit; i++, c++)
      {
            process_queue[i].processName = c;
            printf("\nEnter Details For Process[%C]:\n", process_queue[i].processName);
            printf("Enter Arrival Time:\t");
            scanf("%d", &process_queue[i].AT );
            printf("Enter Burst Time:\t");
            scanf("%d", &process_queue[i].BT);
            printf("Enter Priority:\t");
            scanf("%d", &process_queue[i].priority);
            process_queue[i].status = 0;
            BT = BT + process_queue[i].BT;
      }
      AT_Sorting();
      process_queue[9].priority = -9999;
      printf("\nProcess Name\tArrival Time\tBurst Time\tPriority\tWaiting Time");
      for(time = process_queue[0].AT; time < BT;)
      {
            largest = 9;
            for(i = 0; i < limit; i++)
            {
                  if(process_queue[i].AT <= time && process_queue[i].status != 1 && process_queue[i].priority > process_queue[largest].priority)
                  {
                        largest = i;
                  }
            }
            time = time + process_queue[largest].BT;
            process_queue[largest].ct = time;
            process_queue[largest].WT = process_queue[largest].ct - process_queue[largest].AT - process_queue[largest].BT;
            process_queue[largest].TAT = process_queue[largest].ct - process_queue[largest].AT;
            process_queue[largest].status = 1;
            wait_time = wait_time + process_queue[largest].WT;
            TAT = TAT + process_queue[largest].TAT;
            printf("\n%c\t\t%d\t\t%d\t\t%d\t\t%d", process_queue[largest].processName, process_queue[largest].AT, process_queue[largest].BT, process_queue[largest].priority, process_queue[largest].WT);
      }
      average_WT = wait_time / limit;
      average_TAT = TAT / limit;
      printf("\n\nAverage waiting time:\t%f\n", average_WT);
      printf("Average Turnaround Time:\t%f\n", average_TAT);
}