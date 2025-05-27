#include<stdio.h>
#define MAX 100

int subset[MAX];
int found=0;

void findsubset(int arr[],int n,int index,int sum,int target,int subsetsize){
    if (index==n||sum>target)
      return;
    if (sum==target){
        found=1;
        printf("subset found :{");
        for(int i=0;i<subsetsize;i++){
            printf("%d",subset[i]);
        }
            printf("}\n");
    }

   subset[subsetsize]=arr[index];
   findsubset(arr,n,index+1,sum+arr[index],target,subsetsize+1);
   findsubset(arr,n,index+1,sum,target,subsetsize);
    }

int main() {
    int n, target;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter the target sum: ");
    scanf("%d", &target);

    printf("Subsets that sum to %d:\n", target);
    findsubset(arr, n, 0, 0, target, 0);

    if (!found)
        printf("No subset found.\n");

    return 0;
}

