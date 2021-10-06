#include <stdio.h>
# define N 5
int a[N]; int ub,lb,mid;
void merge(int a[] , int lb,int mid,int ub)
{
    int i=lb; int j=mid+1; int k=lb;
    int b[N];
    while(i<=mid&&j<=ub)
    {
        if(a[i]<=a[j])
        {
            b[k]=a[i];
            i++; k++;
        }
        else
        {
            b[k]=a[j];
            j++; k++;
        }
       if(i>mid)
       {
           while(j<=ub)
           {
               b[k]=a[j];
               j++; k++;
           }
       }
       else
       {
           while(i<=mid)
           {
               b[k]=a[i];
               i++; k++;
               
           }
       }
        
    }
    for(k=lb;k<=ub;k++)
    b[k]=a[k];
    
}

void merge_sort( int a[],int lb,int ub)
{
    int mid;
    if(lb<ub)
    {
        mid=(lb+ub)/2;
        merge_sort( a[N], lb, mid);
        merge_sort( a[N], mid+1, ub);
        merge( a[N], lb, mid, ub);
        
    }
}
main()
{   
    int x;
    printf("\n Enter elements of array to be sorted\n");
    for(x=0;x<N;x++)
    scanf("%d",&a[x]);
    
    merge_sort( a[N], 0, N-1);
    printf("\n The sorted array is\n");
    for(x=0;x<N;x++)
    printf("%d\n",a[x]);
    
}


