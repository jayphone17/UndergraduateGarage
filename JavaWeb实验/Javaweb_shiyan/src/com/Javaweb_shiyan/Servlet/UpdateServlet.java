package com.Javaweb_shiyan.Servlet;
import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
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

import com.Javaweb_shiyan.Dao.UserDao;
import com.Javaweb_shiyan.VO.UserVO;

/**
 * Servlet implementation class UpdateServlet
 */
@WebServlet("/UpdateServlet")
public class UpdateServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public UpdateServlet() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		response.getWriter().append("Served at: ").append(request.getContextPath());
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		request.setCharacterEncoding("utf-8");
		UserVO user=new UserVO();
		user.setSid(request.getParameter("sid"));
		user.setSname(request.getParameter("sname"));
		user.setPassword(request.getParameter("password"));
		
		user.setAge(Integer.parseInt(request.getParameter("age")));
		user.setHeight(request.getParameter("height"));
		user.setCollege(request.getParameter("college"));
		try {
			Class.forName("com.mysql.jdbc.Driver");
			String url="jdbc:mysql://localhost:3306/studentsql?useUnicode=true&characterEncoding=UTF-8";
			String username="root";
			String password="ww@12300";
			Connection conn=DriverManager.getConnection(url, username, password);
			String sql="update studentinfo set sname=?,password=?,age=?,height=?,college=? where sid=?";
			PreparedStatement ps=conn.prepareStatement(sql);
			System.out.println("更新成功");
			ps.setString(1,user.getSname());
			ps.setString(2, user.getPassword());
			ps.setInt(3, user.getAge());
			ps.setString(4, user.getHeight());
			ps.setString(5,user.getCollege());
			ps.setString(6, user.getSid());
			ps.executeUpdate();
			ps.close();
			conn.close();
		}catch(Exception e) {
			e.printStackTrace();
		}
		response.sendRedirect("FindServlet");
	}

}
