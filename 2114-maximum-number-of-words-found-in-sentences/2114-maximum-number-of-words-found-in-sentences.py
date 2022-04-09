class Solution:
    def mostWordsFound(self, sentences: List[str]) -> int:
        maxi=0
        for i in range(len(sentences)):
            maxi=max(len(sentences[i].split(" ")),maxi)
        return maxi
            
        