class Solution {
    public int appendCharacters(String s, String t) {
        int idx = 0;
        int sizes = s.length();
        int size = t.length();
        for(int i=0;i<sizes;i++){
            if(idx>=size) break;
            if(s.charAt(i)==t.charAt(idx)) idx++;
        }
        return t.length()-idx;
    }
}