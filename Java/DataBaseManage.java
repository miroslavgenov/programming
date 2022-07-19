package mainpack;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

class DataBaseManage{
	String connectionString;
	String databaseName;
	String dataBaseQueryString;
	Connection dataBaseConnection;
	Statement dataBaseState;
	ResultSet queryResult;
	
	public DataBaseManage(String dataBaseName) {
		this.setDatabaseName(dataBaseName);
		this.setConnectionString(this.getDatabaseName());
		this.connectToDataBase();
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
	
	
}



public class MainTest {
	public static void main (String []args) {
		DataBaseManage dbm=new DataBaseManage("mydb.db");
		System.out.println(dbm.getDataBaseConnection());
	}
}









































































