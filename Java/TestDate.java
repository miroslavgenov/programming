package datetime;

import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;

public class TestDate {
	public static void main(String []args) {
		Date d = new Date();
		System.out.println(d.toString());
		SimpleDateFormat df = new SimpleDateFormat("EEE MMM dd HH:mm:ss z yyyy");
		
		String date = df.format(d);
		System.out.println(date);
		
		SimpleDateFormat df2 = new SimpleDateFormat("yyyy MM dd HH mm");
		String date1 = df2.format(d);
		System.out.println(date1);
		
		
		String [] date_split = date1.split(" ");
		Date ndate = new Date(Integer.parseInt(date_split[0])-1900,Integer.parseInt(date_split[1]),Integer.parseInt(date_split[2]),Integer.parseInt(date_split[3]),Integer.parseInt(date_split[4]));
		System.out.println(ndate);
		
		
		
		
//		System.out.println(d);
		//String date= DateFormat.getDateInstance().format(d);
		//System.out.println(date);
	}
}
































