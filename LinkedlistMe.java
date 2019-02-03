import java.util.List;
import java.util.ArrayList;

class LinkedlistMe {
    private void train() {
        List<Integer> t = new ArrayList<>();
        t.add(1);
        t.add(2);
        t.add(3);
        for(int i = 0; i < t.size(); i++){
            int temp = t.get(i);
            System.out.print("--------");
            System.out.println(temp);
        }
        t.remove(1);
        System.out.println(t);
    }

    public static void main(String[] args) {
        LinkedlistMe m = new LinkedlistMe();
        m.train();
    }
}