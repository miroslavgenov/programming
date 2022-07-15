package abstractexample;

abstract class Animal{
	private	String animalType;
	private Integer age;


	public Animal(String animalType,Integer age) {	
		this.animalType = animalType;
		this.age=age;
	}
	public Animal() {this.animalType = "null";}
	public String getAnimalType() {	return animalType;	}
	public Integer getAge() {return age;}
	public void setAnimalType(String animalType) {	this.animalType = animalType;	}
	public void setAge(Integer age) {this.age=age;	}
	
	public abstract void showAnimalType();
	
}

class Dog extends Animal{

	public Dog(Integer age) {super("dog",age);	}
	
	@Override
	public void showAnimalType() {System.out.println(super.getAnimalType());}
	
}

public class UseAbstract {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//Animal a = new Animal("xx");
		Animal[] list = {
			new Dog(13),new Dog(1),
			new Dog(4),new Dog(3),
		};
		for(Animal item:list) {
			item.showAnimalType();
		}
	}

}


















































