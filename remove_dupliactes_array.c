//remove duplicates in array
#include<stdio.h>
void remove_dup(int *a,int *s)
{
    int i,j,k,size=*s;
    for(i=0;i<size;i++)
    {
        for(j=i+1;j<size;j++)
        {
            if(a[i]==a[j])
            {
                for(k=j;k<size-1;k++)
                {
                    a[k]=a[k+1];
                }
                size--;
                j--;
            }
        }
    }
    *s=size;
}
int main(){
    int arr[10];
    int size=sizeof(arr)/sizeof(arr[0]),i;
    
    printf("enter the arr ele...\n");
    for(i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("before ....\n");
    printf("the arr ele are :");
    for(i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    
    remove_dup(arr,&size);
    
    printf("after...\n");
    printf("the arr ele are :");
    for(i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}