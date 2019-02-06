class Array_ {
    // to distinguish array and array list.
    // 1. array is length fixed, arraylist is dynamic. 
    // 2.  arraylist support different types(generics).
    // 3. length for array, size() for arraylist.
    // 4. Obj[] objArray = new Obj[10]; objArray[1] = new Object();

    class MT extends Object {
        public int val; 
        MT(int v){
            val = v;
        }
    }
    private void s() {
        int[] arr1 = new int[2];
        for(int i : arr1){
            System.out.println(i);
        }
        for(int i = 0; i < arr1.length; i++){
            arr1[i] = i;
        }
        arr1[0] = 1;
        arr1[1] = 2; // not necessary to initial all items. 
        System.out.println(arr1);
    
        int[] arr2 = {1,2};
        System.out.println(arr2);
        int[] arr3 = new int[]{19,20};
        
        int[][] arr4 = {{1,2,3},{4,5,6}};

        int[][] multiArray = new int[2][3];

        MT[] e = new MT[2];
        e[0] = new MT(1);
        e[1] = new MT(4444);
        System.out.println(e[1].val);
        
        System.arraycopy(arr1,1,arr3,0,1); // not 2
        System.out.println(arr3[0]);

    }

    public static void main(String[] args) {
        Array_ a = new Array_();
        a.s();
    }
}