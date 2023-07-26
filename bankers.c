#include<stdio.h>
void main()
{
    int m,n,i,j,k,y;
    m=3;
    n=5;
    int alloc[n][m],max[n][m],avail[m];
    for(i=0;i<n;i++)
    {
        printf("Enter the allocation for process %d: ",i);
        for(j=0;j<m;j++)
        {
            scanf("%d",&alloc[i][j]);
        }
        printf("Enter the max for process %d: ",i);
        for(k=0;k<m;k++)
        {
            scanf("%d",&max[i][k]);
        }
    }
    printf("Enter the available: ");
    for(i=0;i<m;i++)
    {
        scanf("%d",&avail[i]);
    }
    int f[n],ans[n],ind=0,need[n][m];
    for(i=0;i<n;i++)
    {
        f[i]=0;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            need[i][j]=max[i][j]-alloc[i][j];
    }
    for(k=0;k<5;k++)
    {
        for(i=0;i<n;i++)
        {
            if(f[i]==0)
            {
                int flag=0;
                for(j=0;j<m;j++)
                {
                    if(need[i][j]>avail[j]){
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    for(y=0;y<m;y++)
                        avail[y]+=alloc[i][y];
                    ans[ind++]=i;
                    f[i]=1;
                }
            }
        }
    }
    int flag=1;
    for(i=0;i<n;i++){
        if(f[i]==0){
            printf("Unsafe state\n");
            flag=0;
            break;
        }
    }
    if(flag==1){
        printf("System is in safe state\n ");
        for(i=0;i<n;i++)
            printf("P%d\t",ans[i]);
    }
}
