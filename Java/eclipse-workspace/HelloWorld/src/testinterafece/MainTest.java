package testinterafece;

interface Speakable{
	abstract void speak();
	abstract void show();
	// podrazbirashta se inicializaciq
	default void showHello() {	System.out.println("Hello");}}

abstract class Animal implements Speakable{
	private String name;
	private Integer age;
	public Animal(String name, Integer age) {this.name = name;this.age = age;}
	public String getName() {	return name;	}
	public void setName(String name) {		this.name = name;	}
	public Integer getAge() {		return age;	}
	public void setAge(Integer age) {		this.age = age;	}
	@Override
	public void show() {System.out.println("Animal: "+ this.getName());	}}

class Dog extends Animal{
	public Dog(String name, Integer age) {super(name, age);	}
	public Dog() {super("dog",13);}
	@Override
	public void speak() {	System.out.println("Uouf");	}}

class Cat implements Speakable{
	Cat(){}
	@Override
	public void speak() {System.out.println("Mew");	}
	@Override
	public void show() {System.out.println("Cat");}}

public class MainTest {
	public static void main(String[] args) {
		Speakable[] list = {new Dog(),new Cat(),new Dog(),new Cat(),new Cat(),new Cat()	};
		for(Speakable item :list) {item.showHello();item.speak();item.show();
			System.out.println();}}}





















































