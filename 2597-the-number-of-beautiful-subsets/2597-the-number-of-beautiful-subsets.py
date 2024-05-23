class Solution:
    def __dfs(self, nums, idx, k, mp):
        if idx == len(nums): return 1
        take = 0
        if mp[nums[idx]-k] == 0 and mp[nums[idx]+k] == 0:
            mp[nums[idx]] += 1
            take = self.__dfs(nums, idx+1, k, mp)
            mp[nums[idx]] -= 1
        
        notTake = self.__dfs(nums, idx+1, k, mp)

        return take+notTake

    def beautifulSubsets(self, nums: List[int], k: int) -> int:
        mp = defaultdict(int)
        return self.__dfs(nums, 0, k, mp)-1