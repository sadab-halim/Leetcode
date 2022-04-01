public int majorityElement(int[] nums) {
    int majEle=0;
    int count=0;
    for (int num:nums){
       if(count==0)
           majEle=num;
       if(majEle==num)
           count++;
       else
           count--;
    }
    return majEle;
}