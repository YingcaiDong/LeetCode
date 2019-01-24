class Solution {
    public boolean wordPattern(String pattern, String str) {
        // Split str to arr.
        String[] wordsArr = str.split(" ");
        
        // If Pattern&word arr length don't match, return.
        if (wordsArr.length != pattern.length()) return false;
        
        // Identify different pattern tamplate has different word elements under them.
        Set<String> uniquePatternSet = new HashSet<String>();
        
        // Key: pattern tamplate, value: list of index positions.
        Map<Character, List<Integer>> pMap = new HashMap<Character, List<Integer>>();
        
        for (int i = 0; i < pattern.length(); i++) {
            // Pattern key exist, only append index.
            if (pMap.containsKey(pattern.charAt(i))) {
                pMap.get(pattern.charAt(i)).add(i);
            } else {
                // Pattern key don't exit, create new list array.
                List<Integer> _t = new ArrayList<Integer>();
                _t.add(i);
                pMap.put(pattern.charAt(i), _t);
            }
        }
        
        boolean returnFlag = true;
        for (Map.Entry<Character, List<Integer>> keyValPair : pMap.entrySet()) {
            // Iterate thougth each different pattern tamplate.
            List<Integer> idxArr = keyValPair.getValue();
            
            Set<String> wordsEachPattern = new HashSet<String>();
            String theWord = "";
            
            for (int idx : idxArr) {
                wordsEachPattern.add(wordsArr[idx]);
                theWord = wordsArr[idx];
                if (wordsEachPattern.size() > 1) {
                    return false;
                }
            }
            
            // When word duplicate.
            if (!uniquePatternSet.add(theWord)) {
                returnFlag = false;
            } 
        }
        return returnFlag;
    }
}
