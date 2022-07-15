package inheritance;

class Person{
	Integer age;
	String name;
	
	public Person(String name, Integer age) {
		this.name = name;
		this.age = age;
	}

	public Integer getAge() {
		return age;
	}

	public void setAge(Integer age) {
		this.age = age;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	@Override
	public String toString() {
		return this.getName()+" "+ this.getAge();
	}
	
}


class Student extends Person{

	public Student(String name, Integer age) {
		super(name, age);
	}
	
	
	
}
















































