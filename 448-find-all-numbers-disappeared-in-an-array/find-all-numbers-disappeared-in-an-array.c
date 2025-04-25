/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    for(int i=0;i<numsSize;i++)
    {
        int k=abs(nums[i])-1;
        if(nums[k]>0)
        {
            nums[k]=-nums[k];
        }
    }
    int *r=(int*)malloc (numsSize * sizeof(int));
    *returnSize=0;
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i]>0)
        {
            r[(*returnSize)++]=i+1;
        }
    }
    return r;
}