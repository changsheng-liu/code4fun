
class UnionFindSet {
    private int[] _parents;
    private int[] _rank;

    public UnionFindSet(int n) {
        _parents = new int[n];
        _rank = new int[n];
        for(int i  = 0; i < _parents.length; i++) {
            _parents[i] = i;
            _rank[i] = 1;
        }
    }

    public int find(int i) {
        while(_parents[i] != i){
            _parents[i] = _parents[_parents[i]];
            i = _parents[i];
        }
        return i;
    }

    public boolean union(int i, int j){
        int p1 = find(i);
        int p2 = find(j);
        if(p1 == p2) {
            return false;
        }

        if(p1 > p2) {
            _parents[p2] = p1;
        }else if(p2 > p1) {
            _parents[p1] = p2;
        }else {
            _parents[p1] = p2;
            _rank[p2]++;
        }

        return true;
    }
}