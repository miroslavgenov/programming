package abstractexample;

import java.util.ArrayList;
import java.util.Arrays;

class Person{
	String name;
	Integer age;
	/**
	 * @param name
	 * @param age
	 */
	public Person(String name, Integer age) {
		
		this.name = name;
		this.age = age;
	}
	public Person() {
		this("ivan",13);
	}
	public String getName() {return this.name;}
	
	public Integer getAge() {
		return this.age;
	}
	
	public void showName() {
		System.out.println(this.getName());
	}
	public void showAge() {
		System.out.println(this.getAge());
	}
	@Override
	public String toString() {
		return "Person [name=" + name + ", age=" + age + "]";
	}
}

class Student extends Person{
	private Integer number;
public Student(String name,Integer age){
		super(name,age);
		
	}
public Student() {
	super();
	this.number=10;
	
}
@Override
public void showName() {
	System.out.println("Student name is "+super.getName());
}
public void aveGrade() {
	System.out.println("Avegrade grade");
}
	
}


public class Main {
	public static void main(String [] args) {
		Person p1 = new Student();
		p1.showName();
		((Student)p1).aveGrade();
		
		// polimorfizym
		Person[] list1 = {
			new Person(),
			new Person(),
			new Student(),
			new Student(),
			new Student(),
			new Person()
		};
		for(Person item:list1) {
			//System.out.println(item.getClass().getName());
			item.showName();
			if(item instanceof Student) {
				((Student)item).aveGrade();
				System.out.println();
			}
		}
		
	}
}





































































