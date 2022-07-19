package mainpack;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

// TODO nqkyde sum dopusnal greshka i ne mi raboti dobavqneto na elementi


final class CardContract{
	
}

final class ClientContract{
	
	
	public static class ClientEntry{
		public static final String TABLE_NAME="client"; 
		public static final String COLUMN_NAME_ID="id";
		public static final String COLUMN_NAME_NAME="name";
		public static final String COLUMN_NAME_CARD_ID="card_id";
	}
	public static final String SQL_CREATE_ENTRY ="create table client("
	+ ClientEntry.COLUMN_NAME_ID
	+ " integer not null primary key autoincrement,"
	+ ClientEntry.COLUMN_NAME_NAME
	+ " nvarchar(50) not null,"
	+ ClientEntry.COLUMN_NAME_CARD_ID
	+ " integer" 
	+");";

	
	
	public static final String DELETE_ENTRY="drop table if exitst "+ClientEntry.TABLE_NAME+";";
	
	
	
}

class DataBaseHelper{
	
	String connectionString;
	String databaseName;
	String dataBaseQueryString;
	Connection dataBaseConnection;
	public Statement dataBaseState;
	public ResultSet queryResult;
	public static final String SQL_INSERT_CLIENT_ENRY="insert into "
			+ ClientContract.ClientEntry.TABLE_NAME
			+ "("
			+ ClientContract.ClientEntry.COLUMN_NAME_NAME
			+ ") values('%s')";
	
	
	public DataBaseHelper(String dataBaseName) {
		this.setDatabaseName(dataBaseName);
		this.setConnectionString(this.getDatabaseName());
		this.connectToDataBase();
	}
	
	public void createDataBaseTableClient() {
		try {
			this.dataBaseState = this.getDataBaseConnection().createStatement();
			this.dataBaseState.execute(ClientContract.SQL_CREATE_ENTRY);
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}
	
	public String getConnectionString() {
		return connectionString;
	}

	public void setConnectionString(String dataBaseName) {
		String connectionString="jdbc:sqlite:%s";
		this.connectionString = String.format(connectionString, dataBaseName);
	}


	public String getDatabaseName() {
		return databaseName;
	}

	public void setDatabaseName(String databaseName) {
		this.databaseName = databaseName;
	}

	public Connection getDataBaseConnection() {
		return dataBaseConnection;
	}

	public void setDataBaseConnection(Connection dataBaseConnection) {
		if(dataBaseConnection!=null) {
			this.dataBaseConnection = dataBaseConnection;
		}
	}

	private void connectToDataBase() {
		this.setDataBaseConnection(this.getConnectionFromDriverManager());
	}
	
	private Connection getConnectionFromDriverManager() {
		// TODO Auto-generated method stub
		
		try {
			return DriverManager.getConnection(this.getConnectionString());
		}catch(SQLException e) {e.printStackTrace();}
		return null;
	}

	public String getDataBaseQueryString() {
		return dataBaseQueryString;
	}

	public void setDataBaseQueryString(String dataBaseQueryString) {
		this.dataBaseQueryString = dataBaseQueryString;
	}
	
	// TODO make receiving select and user delete update etc table
	void insertClient(String clientName) {
		try {
			this.dataBaseState = this.getDataBaseConnection().createStatement();
			this.setDataBaseQueryString(String.format("insert into client(name) values('%s')", clientName));
			
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}



public class MainTest {
	public static void main (String []args) {
		DataBaseHelper dbm=new DataBaseHelper("mydb.db");
		//dbm.createDataBaseTableClient();
		dbm.insertClient("NewClient");
		
		
	}
}









































































