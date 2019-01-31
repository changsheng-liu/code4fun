import java.util.ArrayDeque;
import java.util.Deque;

class Array_ {
    void forstack(){
        Deque<Integer> s = new ArrayDeque<Integer>();
        s.push(1);
    }

    public static void main(String[] args) {
        Array_ a = new Array_();
        a.forstack();
    }
}