package programmer;

public class Test {
	public static void main(String [] args) {
		Programmer p = new Programmer("Ivan",13,"Java");
		p.printProgrammingLang(p.getLang());
		System.out.println(Programmer.MyNumber);
		System.out.println(p.Number);
		System.out.println(Programmer.NUMBER1);
		Programmer.showNumber();
	
	}
}
