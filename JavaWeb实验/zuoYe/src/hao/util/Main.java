package hao.util;

import java.sql.Connection;
import java.sql.SQLException;
import java.util.List;

import hao.dao.DBConn;

//import com.sun.corba.se.pept.transport.Connection;

//import hao.dao.DBConn;
import hao.dao.StudentDao;
import hao.dao.StudentDaoImpl;
import hao.service.StudentService;
import hao.service.StudentServiceImpl;
//import hao.dao.StudentDao;
//import hao.dao.StudentDaoImpl;
//import hao.service.StudentService;
//import hao.service.StudentServiceImpl;
import hao.vo.Student;
//import java.sql.Connection;
//import java.sql.SQLException;

//测试代码
public class Main {
	//private static StudentDao stuDao = new StudentDaoImpl();
//	private static StudentService stuService = new StudentServiceImpl();
	
	public static void main(String[] args) {
//		Student stu = new Student();
//		stu.setStuId(1111111113);
//		stu.setName("new");
//		stu.setPassword("new");
//		stu.setAge(111);
//		stu.setHeight(11111);
//		stu.setCollege("E");
//		StudentDao stuDao = new StudentDaoImpl();
//		stuDao.upload(stu);
		//System.out.println(stuService.update(stu,1111111113));
		DBConn dbconn = new DBConn();
		Connection conn = dbconn.getConnection();
		StudentService stuService = new StudentServiceImpl() ;
		
		if (conn!=null)
			System.out.println("Connected");
		try {
		//	conn.close();
			Student stu = stuService.login("1234567890", "alex");
			stu.getAge();
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
