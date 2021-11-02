package hao.dao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.LinkedList;
import java.util.List;

import hao.vo.Student;

public class StudentDaoImpl implements StudentDao{

	@Override
	public boolean upload(Student student) {
		DBConn dbCon = new DBConn();
		Connection conn = dbCon.getConnection();
		String sql = "insert into student values(?,?,?,?,?,?,?,?,?)";
        try {
        	PreparedStatement pst = conn.prepareStatement(sql); 
        	pst.setInt(1,student.getStuId());
			pst.setString(2, student.getName());
			pst.setString(3, student.getPassword());
			pst.setString(4, student.getSex());
			pst.setInt(5,student.getAge());
			pst.setInt(6,student.getHeight());
			pst.setString(7, student.getCollege());
			pst.setString(8, student.getPhoto());
			pst.setString(9, student.getResume());
			pst.execute();
		    pst.close();
		    conn.close();
		    return true;
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			try {
				conn.close();
			} catch (SQLException ee) {
				ee.printStackTrace();
			}
			return false;
		} 
	}
	
	@Override
	public boolean delete(int stuId) {
		DBConn dbCon = new DBConn();
		Connection conn = dbCon.getConnection();
		String sql = "delete from  student where stuId = ?";
        try {
        	PreparedStatement pst = conn.prepareStatement(sql);
        	pst.setInt(1,stuId);
        	pst.execute();
		    pst.close();
		    conn.close();
		    return true;
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			try {
				conn.close();
			} catch (SQLException ee) {
				ee.printStackTrace();
			}
			return false;
		} 
	}

	@Override
	public String findResumeById(int stuId) {
		DBConn dbCon = new DBConn();
		Connection conn = dbCon.getConnection();
		String sql = "select resume from student where stuId=?";
        String path = null;
        try {
			PreparedStatement pst = conn.prepareStatement(sql);
			pst.setInt(1, stuId);
			ResultSet res = pst.executeQuery();
			if(res.next()){
		       	path = res.getString("resume");
			}
			res.close();
        } catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} 
        try {
			conn.close();
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return path;
	}

	@Override
	public List<Student> findStuByAge(int min, int max) {
		List<Student> studentList = new LinkedList<Student>();
		DBConn dbCon = new DBConn();
		Connection conn = dbCon.getConnection();
		String sql = "select * from student where age between ? and ?";
		try {
			PreparedStatement pst = conn.prepareStatement(sql);
			pst.setInt(1, min);
			pst.setInt(2, max);
			ResultSet res = pst.executeQuery();
			while(res.next()){
				Student student = new Student();
				student.setStuId(res.getInt("stuId"));
				student.setName(res.getString("name"));
				student.setSex(res.getString("sex"));
				student.setAge(res.getInt("age"));
				student.setHeight(res.getInt("height"));
				student.setCollege(res.getString("college"));
				studentList.add(student);
			}
			res.close();
		} catch (SQLException e) {
			e.printStackTrace();
		}
		try {
			conn.close();
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return studentList;
	}
	@Override
	public List<Student> findAllStu() {
		List<Student> studentList = new LinkedList<Student>();
		DBConn dbCon = new DBConn();
		Connection conn = dbCon.getConnection();
		String sql = "select * from student";
		try {
			PreparedStatement pst = conn.prepareStatement(sql);
			ResultSet res = pst.executeQuery();
			System.out.println("Find all Student");
			while(res.next()){
				Student student = new Student();
				student.setStuId(res.getInt("stuId"));
				student.setName(res.getString("name"));
				student.setSex(res.getString("sex"));
				student.setAge(res.getInt("age"));
				student.setHeight(res.getInt("height"));
				student.setCollege(res.getString("college"));
				studentList.add(student);
			}
			res.close();
		} catch (SQLException e) {
			e.printStackTrace();
		}
		try {
			conn.close();
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return studentList;
	}

	@Override
	public Student login(int stuId, String password) {
		DBConn dbCon = new DBConn();
		Connection conn = dbCon.getConnection();
		String sql = "select * from student where stuId=? and password=?";
		Student stu = null;
		try {
			PreparedStatement pst = conn.prepareStatement(sql);
			pst.setInt(1 , stuId);
			pst.setString(2 , password);
			ResultSet res = pst.executeQuery();
			if(res.next()){
				stu = new Student();
				stu.setStuId(res.getInt("stuId"));
				stu.setName(res.getString("name"));
				stu.setPassword(res.getString("password"));
				stu.setSex(res.getString("sex"));
				stu.setAge(res.getInt("age"));
				stu.setHeight(res.getInt("height"));
				stu.setCollege(res.getString("college"));
			}
			res.close();
		} catch (SQLException e) {
			e.printStackTrace();
		}
		try {
			conn.close();
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return stu;
	}

	@Override
	public boolean update(Student student,int stuId) {
		DBConn dbCon = new DBConn();
		Connection conn = dbCon.getConnection();
		String sql = "update student set stuId=?,name=?,password=?,age=?,height=?,college=? where stuId=?";
		try {
			PreparedStatement pst = conn.prepareStatement(sql);
			pst.setInt(1, student.getStuId());
			pst.setString(2, student.getName());
			pst.setString(3, student.getPassword());		
			pst.setInt(4, student.getAge());
			pst.setInt(5, student.getHeight());
			pst.setString(6, student.getCollege());	
			pst.setInt(7, stuId);
			pst.execute();
		    pst.close();
		    conn.close();
		    return true;
		} catch (SQLException e) {
			e.printStackTrace();
			try {
				conn.close();
			} catch (SQLException ee) {
				ee.printStackTrace();
			}
			return false;
		}
	}

	@Override
	public Student findStuById(int stuId) {
		DBConn dbCon = new DBConn();
		Connection conn = dbCon.getConnection();
		String sql = "select * from student where stuId=?";
		Student student = null;
		boolean result = false;
		try {
			PreparedStatement pst = conn.prepareStatement(sql);
			pst.setInt(1, stuId);
			ResultSet res = pst.executeQuery();

			if(res.next()){
				student = new Student();
				student.setStuId(res.getInt("stuId"));
				student.setName(res.getString("name"));
				student.setSex(res.getString("sex"));
				student.setAge(res.getInt("age"));
				student.setHeight(res.getInt("height"));
				student.setCollege(res.getString("college"));
				//result = true;
			}
			res.close();
		} catch (SQLException e) {
			e.printStackTrace();
		}
		try {
			conn.close();
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return student;
	}

}

