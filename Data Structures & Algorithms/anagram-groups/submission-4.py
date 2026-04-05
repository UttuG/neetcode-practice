class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        dict_s = {}
        if s == "" and t == "":
            return True
            
        for i in s:
            if i in dict_s:
                dict_s[i] += 1
            else:
                dict_s[i] = 1

        for j in t:
            if j not in dict_s:
                return False
            else:
                dict_s[j] -= 1
                if dict_s[j] < 0:
                    return False

        for i in dict_s:
            if dict_s[i] != 0:
                return False
        return True
    
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        str_set = []

        if len(strs) == 1:
            return [strs]
        if len(strs) == 2:
            if self.isAnagram(strs[0], strs[1]) == True:
                return [strs]
            else:
                return [[strs[0]], [strs[1]]]
        else:
            # Fixing initialization for str_set based on whether the first two strings are anagrams
            if self.isAnagram(strs[0], strs[1]) == True:
                str_set = [[strs[0],strs[1]]]  # Grouping both if they're anagrams
            else:
                str_set = [[strs[0]], [strs[1]]]  # Otherwise, separate them into two lists

            # Iterate through the rest of the strings
            for i in strs[2:]:
                flag_match = False
                for k, j in enumerate(str_set):
                    if self.isAnagram(i, j[0]) == True:
                        str_set[k].append(i)
                        flag_match = True
                        break
                if not flag_match:
                    str_set.append([i])
            
            return str_set
