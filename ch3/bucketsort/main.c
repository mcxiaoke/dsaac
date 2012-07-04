
#include <stdio.h>
#include <stdlib.h>

static int nums[10];

static int bucket[100];

void printArray(int array[], int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    int i;
    for(i=0;i<10;i++){
        nums[i]=rand()%100;
    }
    
    int j;
    for(j=0;j<10;j++){
        bucket[nums[j]]++;
    }
    
    printArray(nums,10);
    int k;
    for(k=0;k<100;k++){
        if(bucket[k]==1){
            printf("%d ",k);
        }
    }
    
	return 0;
}
