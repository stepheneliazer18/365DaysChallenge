class Solution {
    public int compareVersion(String v1, String v2) {
        String[] s1 = v1.split("\\.");
        String[] s2 = v2.split("\\.");
        
        int maxi = Math.max(s1.length,s2.length);
        for(int i=0;i<maxi;i++){
            Integer x1 = i<s1.length ? Integer.parseInt(s1[i]) : 0;
            Integer x2 = i<s2.length ? Integer.parseInt(s2[i]) : 0;
            
            if(x1 < x2) return -1;
            if(x1 > x2) return 1;
        }
        return 0;
    }
}