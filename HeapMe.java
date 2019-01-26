import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Comparator;
import java.util.Random;

class HeapMe {
	void init_heap(){
		//
		// Queue<Integer> q = new PriorityQueue<>(); // is work, ascending small2big
		///
		// Queue<Integer> q = new PriorityQueue<>(10, new Comparator<Integer>(){
		// 	public int compare(Integer i1, Integer i2){
		// 		return -(i1-i2);
		// 	}
		// });
		//
		Queue<Integer> q = new PriorityQueue<>((a, b)->{return b-a;});

		Random r = new Random();
		for(int i = 0; i < 11; i++){
			int e = r.nextInt(100);
			q.add(new Integer(e));
			System.out.print(e);
			System.out.print(" ");
		}
		System.out.println("");
		for (int i = 0; i < 11 ; i++) {
			Integer t = q.poll();
			System.out.print(t.intValue());
			System.out.print(" ");
		}
	}
	public static void main(String[] args) {
		HeapMe t = new HeapMe();
		t.init_heap();
		
	}
}