package testinterface;

import java.util.ArrayList;


interface MySpeackable{
	public abstract void show();
}

class Dog implements Speakable {

	@Override
	public void speak() {
		// TODO Auto-generated method stub
		System.out.println("Yaf");
	}
	
	
}

public class Cat implements Speakable {

	@Override
	public void speak() {
		// TODO Auto-generated method stub
		System.out.println("Mew");
	}
	public static void main(String [] args) {
		Speakable[] list = {
			new Cat(),new Dog(),new Cat(),new Dog()	
		};
	}

}


















































