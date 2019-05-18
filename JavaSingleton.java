class JavaSingleton {
		
	public static void main(String[] args) {
		Singleton u = Singleton.getInstance();
		System.out.print(u.p());
	}
}

final class Singleton {
	
	private Singleton() {}
	
	private volatile  static  Singleton instance;
	
	public static Singleton getInstance() {
		if(instance == null) {
			synchronized (Singleton.class) {
				if(instance == null) {
					instance = new Singleton();
				}
			}
		}
		return instance;
	}

	public String p() {
		return "Hello World";
	}
}