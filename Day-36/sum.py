from pprint import pprint

def helper(arr1:list[int],arr2:list[int],nodes:list[int],mini:int,max_len:int):
    if len(nodes)==0:
        return min(mini,abs(sum(arr1)-sum(arr2)))
    if len(arr1)==max_len and len(arr2)==max_len:
        return min(mini,abs(sum(arr1)-sum(arr2)))
    if len(arr1)==max_len:
        arr2.extend(nodes)
        mini_temp = min(mini,abs(sum(arr1)-sum(arr2)))
        return helper(arr1,arr2,[],mini_temp,max_len)
    if len(arr2)==max_len:
        arr1.extend(nodes)
        mini_temp = min(mini,abs(sum(arr1)-sum(arr2)))
        return helper(arr1,arr2,[],mini_temp,max_len)
    else:
        temp = nodes.pop()
        temp_arr1 = arr1.copy()
        temp_arr1.append(temp)
        ans1 = helper(temp_arr1,arr2.copy(),nodes.copy(),mini,max_len)
        temp_arr2 = arr2.copy()
        temp_arr2.append(temp)
        ans2 = helper(arr1.copy(),temp_arr2,nodes.copy(),mini,max_len)
        return min(ans1,ans2)

class Solution:
    def minimumDifference(self, nums: list[int]) -> int:
        ans = helper([],[],nums,float('inf'),len(nums)//2)
        return ans
    

test = [3,9,7,3]
# s = Solution().minimumDifference(test)
# print(s)