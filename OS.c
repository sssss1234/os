#include<stdio.h>
int main()
{
  int time,bt[10],at[10],sum_bt=0,smallest,n,i;
  int sumt=0,sumw=0;
  printf("no of processes : ");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    printf("arrival time for process P%d : ",i+1);
    scanf("%d",&at[i]);
    printf("burst time for process P%d : ",i+1);
    scanf("%d",&bt[i]);
    sum_bt+=bt[i];
  }
  bt[9]=9999;
  for(time=0;time<sum_bt;)
  {
    smallest=9;
    for(i=0;i<n;i++)
    {
      if(at[i]<=time && bt[i]>0 && bt[i]<bt[smallest])
        smallest=i;
    }
    printf("P[%d]\t|\t%d\t|\t%d\n",smallest+1,time+bt[smallest]-at[smallest],time-at[smallest]);
    sumt+=time+bt[smallest]-at[smallest];
    sumw+=time-at[smallest];
    time+=bt[smallest];
    bt[smallest]=0;
  }
  printf("\n\n average waiting time = %f",sumw*1.0/n);
  printf("\n\n average turnaround time = %f",sumt*1.0/n);
  return 0;
}
