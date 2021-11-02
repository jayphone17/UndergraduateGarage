package hao.dao;

import java.io.FileReader;
import java.io.InputStream;
import java.nio.file.Path;
import java.sql.Connection;  
import java.sql.DriverManager; 
import java.util.Properties;
  
public class DBConn {   
   
	private static String url;
	private static String driver;
	private static String user;
	private static String password;
    

    static{
    	try {
    		//Properties properties = new Properties();

    		//properties.load(new FileReader("D:/eclipse-oxygen-workspace/zuoYe/src/hao/config/dbConfig.properties"));
    		//properties.load(new FileReader("dbConfig.properties"));
    		
    		//properties.load(new FileReader("./src/hao/config/dbConfig.properties"));
    		
//    		url = properties.getProperty("url").trim();
//    		driver = properties.getProperty("driver").trim();
//    		user = properties.getProperty("user").trim();
//    		password = properties.getProperty("password").trim();
    		user="root";
    		password="root";
    		url="jdbc:mysql://localhost:3306/stu?useUnicode=true&characterEncoding=utf-8";
    		driver = "com.mysql.jdbc.Driver";
 
			Class.forName(driver);
			System.out.println("JDBC Driver Loaded!");
			
		} catch (Exception e) {
			
			System.out.println(url);
			System.out.println(driver);
			System.out.println(user);
			System.out.println("JDBC Driver Failed!");
			System.out.println(System.getProperty("user.dir"));
			e.printStackTrace();
		}
    }
    public Connection getConnection() {  
        try {  
            return DriverManager.getConnection(url, user, password);
        } catch (Exception e) {
        	System.out.println("MySQL Connection Failed!");
			System.out.println(driver);
			System.out.println(user);
			System.out.println(System.getProperty("user.dir"));
			
        	e.printStackTrace();
        	return null;  
        }
    }  
}  