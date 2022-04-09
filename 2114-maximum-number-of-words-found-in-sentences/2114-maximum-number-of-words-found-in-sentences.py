class Solution:
    def mostWordsFound(self, sentences: List[str]) -> int:
        maxi=0
        for i in range(len(sentences)):
            maxi=max(sentences[i].count(" "),maxi)
        return maxi+1
            
        