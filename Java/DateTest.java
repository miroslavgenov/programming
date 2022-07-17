package firsttest;

import java.util.Date;
class Client{
	String client_name;
	Date card_from;
	Date card_to;
	final Integer DAY_MEMBER=31;
	
	
	public Client(String client_name) {
		this.client_name=client_name;
		this.card_from=new Date(new Date().getYear(),6,1);
		this.card_to= new Date(122,6,0);
		this.set_card_to();
	}
	
	public int get_card_from_day() {
		return this.card_from.getDate();
	}
	
	public Date get_card_from() {
		return this.card_from;
	}
	
	public Date get_card_to() {
		return this.card_to;
	}
	
	public Integer getDayMember() {
		return this.DAY_MEMBER;
	}
	
	
	public void set_card_to() {
		this.get_card_to().setDate(this.get_card_to().getDate()+this.getDayMember());
	}
	
	public void clear_date_from_and_date_to() {
		this.card_from=null;
		this.card_to=null;
	}
	
	public String getName() {
		return this.client_name;
	}
	
	@Override
	public String toString() {
		if(this.get_card_from()!=null && this.get_card_to()!=null) {
			return this.getName()+"\nCard from: "+this.get_card_from()+"\nCard end: "+this.get_card_to();
		}
		return this.getName();
		 
	}
	
	public Boolean is_active() {
		Date current_date = new Date();
//		System.out.println("Current date: "+current_date);
		if(current_date.getMonth()<=this.get_card_to().getMonth() || current_date.getMonth()<= this.get_card_to().getMonth()) {
			return true;
		}
		
		this.clear_date_from_and_date_to();
		return false;
	}
	
}

public class DateTest {
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Client []list= {
				new Client("Alex"),
				new Client("Ivan"),
				new Client("Boris")
		};
		list[1].get_card_from().setMonth(4);
		list[1].get_card_to().setMonth(4);
		
		
		for (Client client : list) {
			System.out.println(client+"\n");
		}
		
		
		

		
		
		
		
	}

}









































