package customException;

public class Person {
	String name;

	public String getName() throws MyException {
		if(name==null) {
			throw new MyException("Person.getName() is null");
		}else
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public Person() {
		super();
	}
	
}






































