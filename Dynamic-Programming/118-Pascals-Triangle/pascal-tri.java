class Solution {
    public List<List<Integer>> generate(int numRows) {
        
        List<List<Integer>> result = new ArrayList<>(numRows);

        for (int i = 0; i < numRows; i++) {
            List<Integer> row = new ArrayList<>(i+1);             
            List<Integer> prevRow = (i > 0) ? result.get(i - 1) : null;
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) {
                    row.add(1);
                } else {
                    row.add(prevRow.get(j - 1) + prevRow.get(j));
                }
            }
            result.add(row);
        }
        return result;
    }
}