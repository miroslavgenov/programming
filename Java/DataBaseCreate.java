import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class DataBaseCreate {
	public static final String path="jdbc:sqlite:data.db";
	
	public static void exequte(String query) {
		try {
			Connection conn = DriverManager.getConnection(path);
			Statement stm = conn.createStatement();
			stm.execute(query);
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	
	
	
	public static void printClients() {
		try {
			Connection conn = DriverManager.getConnection(path);
			Statement stm = conn.createStatement();
			ResultSet rst= stm.executeQuery("select * from client;");
			while(rst.next()) {
				
				System.out.println(rst.getInt(1)+" "+rst.getString(2)+" "+rst.getInt(3));
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
//		DataBaseCreate.exequte("create table client("
//				+ "id integer not null primary key autoincrement,"
//				+"name nvarchar(50) not null,"
//				+ "card_id integer" 
//				+");");

		
		
		//DataBaseCreate.exequte("create table card("
//				+ "id integer not null primary key autoincrement,"
//				+ "client_id not null,"
//				+ "price integer default 30 not null,"
//				+ "days integer default 31 not null,"
//				+ "card_start datime not null,"
//				+ "card_end datime not null,"
//				+ "foreign key (client_id) "
//				+ "references client(id) "
//				+ "on update set null "
//				+ "on delete set null"
//				+ ");");
		
//		DataBaseCreate.exequte("insert into client(name) values('ivan')");
//		DataBaseCreate.exequte("insert into client(name) values('alex')");
//		DataBaseCreate.exequte("insert into client(name) values('boris')");
		
		DataBaseCreate.printClients();
		
	}

}







































