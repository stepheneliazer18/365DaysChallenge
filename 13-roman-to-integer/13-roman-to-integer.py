class Solution(object):
    def romanToInt(self, s):
        s = s + "0"
        t = 0
        for i in range(len(s)-1):
            if(s[i] == "I" and s[i+1] == "V"):
                t += 4
                t -= 5
            elif(s[i] == "I" and s[i+1] == "X"):
                t += 9
                t -= 10
            elif(s[i] == "X" and s[i+1] == "L"):
                t += 40
                t -= 50
            elif(s[i] == "X" and s[i+1] == "C"):
                t += 90
                t -= 100
            elif(s[i] == "C" and s[i+1] == "D"):
                t += 400
                t -= 500
            elif(s[i] == "C"and s[i+1] == "M"):
                t += 900
                t -= 1000
            else:
                if(s[i] == "I"):
                    t += 1
                elif(s[i] == "V"):
                    t += 5
                elif(s[i] == "X"):
                    t += 10
                elif(s[i] == "L"):
                    t += 50
                elif(s[i] == "C"):
                    t += 100
                elif(s[i] == "D"):
                    t += 500
                elif(s[i] == "M"):
                    t += 1000
                elif(s[i] == "0"):
                    break
            print(t)
        return t