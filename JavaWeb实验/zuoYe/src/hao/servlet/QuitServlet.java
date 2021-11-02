package hao.servlet;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

@WebServlet("/Quit")
public class QuitServlet extends HttpServlet {
		
	private static final long serialVersionUID = 1L;
		
	@Override
	protected void service(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		request.setCharacterEncoding("utf-8");
		HttpSession session = request.getSession();
		session.invalidate();
		//request.getRequestDispatcher("/login.html").forward(request,response);
		System.out.println("Exit");
		response.sendRedirect("/zuoYe/login.html");
	}
			
}
