package programmer;

public class Programmer extends Person implements Printable {
	public static Integer MyNumber=10;
	public final Integer Number=10;
	public static final Integer NUMBER1=10;
	
	private String plang;
	public Programmer(String name,Integer age,String plang) {
		super(name,age);
		this.plang=plang;
	}
	
	public static void showNumber() {
		System.out.println(NUMBER1);
	}
	public String getLang() {return this.plang;}
	
	@Override
	public void printProgrammingLang(String name_of_langueage) {
		// TODO Auto-generated method stub
		System.out.println(name_of_langueage);
		
	}

}
















































