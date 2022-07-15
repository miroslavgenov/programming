package finalclass;

class Person{
	private String name;
	private Integer age;
	public String getName() {		return name;	}
	public void setName(String name) {		this.name = name;	}
	public Integer getAge() {		return age;	}
	public void setAge(Integer age) {		this.age = age;	}
	
	public Person(String name, Integer age) {
		super();
		this.name = name;
		this.age = age;	}
	
	public final String myShow() { return "This";}}


final class Student extends Person{
	public Student(String name, Integer age) {	super(name, age);	}}


public class TestMain {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}















































