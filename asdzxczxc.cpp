def isPal(arr):
    size=len(arr)
    total_sum, part_sum=0, 0
    # 짝수 펠린드롬 판단
    for i in range(size):
        total_sum+=arr[i]
    for i in range(size):
        part_sum+=arr[i]
        if part_sum==total_sum/2:
            return True
        if part_sum>total_sum/2:
            break
    # 홀수 펠린드롬 판단
    left_sum, right_sum=0, 0
    i, j=0, size-1
    while left_sum==0 or left_sum!=right_sum:
        # print(left_sum)
        # print(right_sum)
        if i>=j:
            return False
            break
        while (left_sum==0 or left_sum<right_sum) and i<j:
            left_sum+=arr[i]
            i+=1
        while (right_sum==0 or left_sum>right_sum) and j>i:
            right_sum+=arr[j]
            j-=1
        
    return True

def solution(arr):
    ans=0
    size=len(arr)
    # slice로 각 부분 받기
    for i in range(size-1):
        for j in range(i+2, size+1):
            part_arr=arr[i:j]
            # if part_arr!=[1, 2, 4, 8]:
            #     continue
            if isPal(part_arr):
                # print(part_arr)
                ans+=1            

    return ans
