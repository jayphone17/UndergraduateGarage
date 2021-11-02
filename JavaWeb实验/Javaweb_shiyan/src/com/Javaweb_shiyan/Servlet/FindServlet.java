package com.Javaweb_shiyan.Servlet;

import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.Javaweb_shiyan.VO.UserVO;

/**
 * Servlet implementation class FindServlet
 */
@WebServlet("/FindServlet")
public class FindServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public FindServlet() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request,HttpServletResponse response) throws ServletException, IOException{
		try {
			Class.forName("com.mysql.jdbc.Driver");
			String url="jdbc:mysql://localhost:3306/studentsql?useUnicode=true&characterEncoding=UTF-8";
			String username="root";
			String password="ww@12300";
			Connection conn=DriverManager.getConnection(url, username, password);
			Statement stmt=conn.createStatement();
			String sql="select * from studentinfo";
			ResultSet rs=stmt.executeQuery(sql);
			List<UserVO> list=new ArrayList<UserVO>();
			while(rs.next()) {
				UserVO user=new UserVO();
				user.setSid(rs.getString("sid"));
				user.setSname(rs.getString("sname"));
				user.setAge(rs.getInt("age"));
				user.setHeight(rs.getString("height"));
				user.setCollege(rs.getString("college"));
				list.add(user);
			}
			request.setAttribute("list",list);
			rs.close();
			stmt.close();
			conn.close();
		}catch(ClassNotFoundException e) {
			e.printStackTrace();
		}catch(SQLException e) {
			e.printStackTrace();
		}
		request.getRequestDispatcher("show.jsp").forward(request,response);
}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
