import java.util.ArrayDeque;
import java.util.Deque;

class StackQ {
    void forstack(){
        Deque<Integer> s = new ArrayDeque<Integer>();
        // for stack 
        s.push(1);
        s.push(2);
        System.out.println(s);
        System.out.println(s.peek());
        s.pop();
        System.out.println(s.peek());
    }

    void forqueue(){
        Deque<Integer> s = new ArrayDeque<Integer>();
        s.offer(1);
        s.offer(2);
        System.out.println(s);
        System.out.println(s.peek());
        s.poll();
        System.out.println(s.peek());
    }

    void forgeneral() {
        Deque<Integer> s = new ArrayDeque<Integer>();
        s.add(1);
        s.add(2);
        s.add(3);
        System.out.println(s);
        s.remove();
        System.out.println(s);
        s.removeLast();
        System.out.println(s);
    }

    public static void main(String[] args) {
        StackQ a = new StackQ();
        System.out.println("stack:");
        a.forstack();
        System.out.println("queue:");
        a.forqueue();
        System.out.println("general:");
        a.forgeneral();
    }
}