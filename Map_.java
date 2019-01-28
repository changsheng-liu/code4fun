import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

class Map_ {

    //remove pair
    //change key
    

    private void example(){
        HashMap<Integer, Integer> m = new HashMap<>();
        m.put(1, 1);
        //get key / value seperately
        System.out.println(m.get(1));
        m.put(1, 2);
        System.out.println(m.get(1));
// for loop for a hash map
//1
        // for(Entry<Integer, Integer> e : m.entrySet()) {
        //     e.getKey();
        //     e.getValue();
        // }
//2
        for(Integer key : m.keySet()){
            System.out.println(key);
        }
        for(Integer key : m.values()){
            System.out.println(key);
        }
//3 
        Iterator<Map.Entry<Integer, Integer>> entries = m.entrySet().iterator();
        while(entries.hasNext()) {
            Map.Entry<Integer, Integer> entry = entries.next();
            System.out.println("Key = " + entry.getKey() + ", Value = " + entry.getValue());
        }

//4 
        // Iterator entries = map.entrySet().iterator();
        
        // while (entries.hasNext()) {
        
        //     Map.Entry entry = (Map.Entry) entries.next();
        
        //     Integer key = (Integer)entry.getKey();
        
        //     Integer value = (Integer)entry.getValue();
        
        //     System.out.println("Key = " + key + ", Value = " + value);
        // }
// 5 same as 2 but get value by key in map


//remove entry 
        m.remove(1);
        System.out.println(m.get(1));

//replace / size()
// test key 
        m.containsKey(1);
    }

    public static void main(String[] args) {
        Map_ m = new Map_();
        m.example();
    }
}