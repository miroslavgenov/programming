package example;

import programmer.Programmer;

class Person{
	private Integer age;
	public void show_person() {System.out.println("Person: ");}
	public Integer get_age() {return 44;}
	public Person() {}
	public Person(Integer _age) {
		this.age=_age;
	}
}
public class ExampleTest {
	
	//public final Integer a3=333; // error
	public static final Integer NUMBER=333;
	public void ShowName() {System.out.println("Hello");}
	public static void main(String[] args) {
		Person ivan = new Person();
		ivan.show_person();
		Integer age = new Person().get_age();
		System.out.println(age);
		
			
			
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		

	}
}























