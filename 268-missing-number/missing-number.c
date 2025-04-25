int missingNumber(int* a, int n) {
   int i,j;
    for(i=0;i<=n;i++)
   {
    int f=0;
    for(j=0;j<n;j++)
    {
        if(i==a[j])
        {   f=1;
            break;
        }
    }  
    if(f==0)
    {
        return i;
    }
   } 
   return -1;
}