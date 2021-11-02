package com.Javaweb_shiyan.Dao;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;

import com.Javaweb_shiyan.VO.UserVO;

public class UserDao {
	public void insert(UserVO user) throws SQLException {	
		Connection conn=null;
		PreparedStatement prst=null;
		try { 
			Class.forName("com.mysql.jdbc.Driver");
			String url="jdbc:mysql://localhost:3306/studentsql?useUnicode=true&characterEncoding=UTF-8";
			String username="root";
			String password="ww@12300";
			
			conn=DriverManager.getConnection(url, username, password);
			if(conn!=null) {
				System.out.println("数据库连接成功");
				
			}else {
				System.out.println("数据库连接失败");
			}
			String sql="insert into studentinfo(sid,sname,password,sex,age,height,college)values(?,?,?,?,?,?,?)";
			prst=conn.prepareStatement(sql);
			prst.setString(1,user.getSid());
			prst.setString(2,user.getSname());
			prst.setString(3,user.getPassword());
			prst.setString(4,user.getSex());
			prst.setInt(5,user.getAge());
			prst.setString(6,user.getHeight());
			prst.setString(7,user.getCollege());
			prst.executeUpdate();
		}catch(Exception ex) {
			ex.printStackTrace();
		}finally {
			conn.close();
		}
	
	}
}
