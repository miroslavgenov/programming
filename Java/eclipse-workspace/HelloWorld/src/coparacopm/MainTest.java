package coparacopm;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;

class Student implements Comparable<Student>{
	private String name;
	private Integer age;
	private Integer fn;
	public String getName() {return name;}
	public void setName(String name) {this.name = name;}
	public Integer getAge() {return age;}
	public void setAge(Integer age) {this.age = age;}
	public Integer getFn() {return fn;}
	public void setFn(Integer fn) {this.fn = fn;}	
	public Student(String name, Integer age, Integer fn) {
		this.name = name;this.age = age;this.fn = fn;	}
	public Student() {}
	@Override
	public String toString() {return this.getName()+ " "+this.getAge()+" "+this.getFn();}
	@Override
	public int compareTo(Student o) {return Integer.compare(this.fn, o.fn);}
}

public class MainTest {
	public static void show(ArrayList<Student> list) {
		for(Student item:list) {System.out.println(item);}}
	public static void main(String[] args) {
		ArrayList<Student> list= new ArrayList<>(Arrays.asList(
				new Student("Ivan",33,233),new Student("Alex",10,313),
				new Student("Coco",15,3),new Student("Boko",23,111),
				new Student("Koko",23,34))); 
		MainTest.show(list);
		Collections.sort(list);System.out.println();MainTest.show(list);
		
		list.sort(new Comparator<Student>(){
			@Override
			public int compare(Student o1, Student o2) {
				return Integer.compare(o1.getAge(), o2.getAge());
			}});
		
		MainTest.show(list);}}


















































