package hao.servlet;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import hao.service.StudentService;
import hao.service.StudentServiceImpl;
import hao.vo.Student;

@WebServlet("/Delete")
public class DeleteMyInfoServlet extends HttpServlet{
	
	private static final long serialVersionUID = 1L;
	private StudentService studentService = new StudentServiceImpl();

	@Override
	protected void service(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		//request.setCharacterEncoding("utf-8");
		//response.setCharacterEncoding("utf-8");
		response.setHeader("Content-type", "text/html;charset=UTF-8");
		PrintWriter out = response.getWriter();
		HttpSession session = request.getSession();
		Student stu = (Student) session.getAttribute("student");
		if(stu != null){
			if(studentService.delete(stu)){
				session.invalidate();
			//	request.getRequestDispatcher("/login.html").forward(request,response);
				response.sendRedirect("/login.html");
			}else{
				out.write("删除失败!\n");
				out.flush();
			}
		}else{
			out.write("尚未登录!\n");
			out.flush();
		}
		
	}
}

