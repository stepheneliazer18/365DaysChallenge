class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int time = releaseTimes[0];
        char c = keysPressed[0];
        int temp = 0;
        
        for (int i = 1; i < releaseTimes.size(); i++) {
            temp = releaseTimes[i] - releaseTimes[i - 1];
            if (temp > time) {
                time = temp;
                c = keysPressed[i];   
            }
            
            if (temp == time && keysPressed[i] > c) {
                c = keysPressed[i];
            }
        }
        
        return c;
    }
};