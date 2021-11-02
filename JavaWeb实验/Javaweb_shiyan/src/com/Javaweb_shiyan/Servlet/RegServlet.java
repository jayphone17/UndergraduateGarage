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
import com.Javaweb_shiyan.Dao.UserDao;
import com.Javaweb_shiyan.VO.UserVO;
/**
 * Servlet implementation class LoginServlet
 */
@WebServlet("/RegServlet")
public class RegServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
	protected void service(HttpServletRequest request,HttpServletResponse response) throws ServletException, IOException{
		request.setCharacterEncoding("utf-8");
		UserVO user=new UserVO();
		UserDao dao=new UserDao();
		user.setSid(request.getParameter("sid"));
		user.setSname(request.getParameter("sname"));
		user.setPassword(request.getParameter("password"));
		user.setSex(request.getParameter("sex"));
		user.setAge(Integer.parseInt(request.getParameter("age")));
		user.setHeight(request.getParameter("height"));
		user.setCollege(request.getParameter("college"));
		
		try {
			dao.insert(user);
		} catch (SQLException e) {
			e.printStackTrace();
		}	
		request.getRequestDispatcher("/Find").forward(request,response);
	}

}
