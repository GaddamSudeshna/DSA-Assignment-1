/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize) {
     int c[101]={0};
     int * r=(int*)malloc(numsSize * sizeof(int));
     for(int i=0;i<numsSize;i++)
     {
        c[nums[i]]++;
     }
     for(int i=1;i<101;i++)
     {
        c[i]+=c[i-1];
     }
     for(int i=0;i<numsSize;i++)
     {
        if(nums[i]==0)
        {
            r[i]=0;
        }
        else
        {
            r[i]=c[nums[i]-1];
        }
     }
     *returnSize=numsSize;
     return r;
}