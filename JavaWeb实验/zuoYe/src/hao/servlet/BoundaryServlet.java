package hao.servlet;

import java.io.IOException;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import hao.service.StudentService;
import hao.service.StudentServiceImpl;
import hao.vo.Student;

@WebServlet("/Boundary")
public class BoundaryServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
	private StudentService studentService = new StudentServiceImpl();
	
	@Override
	protected void service(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		request.setCharacterEncoding("utf-8");
        List<Student> stuList = studentService.findAllStudent();
		request.getSession().setAttribute("stuList", stuList);
		request.getRequestDispatcher("/boundary.jsp").forward(request,response);
	}
}
