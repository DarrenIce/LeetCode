class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        result=[]
        candidates.sort()
        if target<candidates[0]:
            return result
        for i in range(len(candidates)):
            res=self.combinationSum(candidates[i:],target-candidates[i])
            if target-candidates[i]==0:
                result.append([candidates[i]])
            if res!=[]:
                for item in res:
                    if ([candidates[i]]+item) not in result:
                        result.append([candidates[i]]+item)
        return result