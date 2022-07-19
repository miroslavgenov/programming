import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class DataBaseTest {
	public static final String CONNECTIONSTRING = "jdbc:sqlite:mydatabase.db";
	static String query;
	
	public static void setQuery(String value) {
		query=value;
	}
	public static String getQuery() {
		return query;
	}
	
	public static void createDataBase() {
		String ConnectionString ="jdbc:sqlite:mydatabase.db";
		
		
		try {
			Connection conn = DriverManager.getConnection(ConnectionString);
			
			Statement state = conn.createStatement();
			state.execute(getQuery());
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	public static void insertData() {
		String connectionString="jdbc:sqlite:mydatabase.db";
		
		try {
			Connection connect = DriverManager.getConnection(connectionString);
			
			
			Statement state = connect.createStatement();
			state.execute(getQuery());
		}
		catch(SQLException e) {e.printStackTrace();}
	}
	
	public static void getSelection() {
		try {
		Connection conn = DriverManager.getConnection(CONNECTIONSTRING);
	
		Statement state = conn.createStatement();
		
		ResultSet result = state.executeQuery(getQuery());
		while(result.next()) {
			Integer id=result.getInt("id");
			String name=result.getString("name");
			System.out.println(id+ " "+ name);
		}
		
		}catch(SQLException e) {e.printStackTrace();}
	}
	public static void main(String[] args) {
		DataBaseTest.setQuery("select * from client;");
		DataBaseTest.getSelection();
		
	}
}










































