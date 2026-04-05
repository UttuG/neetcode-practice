class Solution:

    def encode(self, strs: List[str]) -> str:
        e_str=""
        for i in strs:
            e_str+="#"+str(len(i))+"!"+i
        return e_str

    def decode(self, s: str) -> List[str]:
        i=0
        str_num=""
        res_list=[]
        while i<len(s):
            str_num=""
            if s[i]=="#":
                i+=1
                while s[i]!="!":
                    str_num+= s[i]
                    i+=1
                s_num=int(str_num)
                res_list.append(s[i+1:i+1+s_num])
                i=i+1+s_num
            else:
                print("logic error")

        return res_list