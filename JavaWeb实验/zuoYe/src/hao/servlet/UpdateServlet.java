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
import hao.vo.CollegeMap;
import hao.vo.Student;

@WebServlet("/Update")
public class UpdateServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
	private StudentService studentService = new StudentServiceImpl();
	
	@Override
	protected void service(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		request.setCharacterEncoding("utf-8");
		HttpSession session = request.getSession();
		Student stu = (Student) session.getAttribute("student");
		int stuId = stu.getStuId();
		Student student = new Student();
		student.setStuId(Integer.valueOf(request.getParameter("stuId")));
		student.setName(request.getParameter("name"));
		student.setPassword(request.getParameter("password"));
		student.setAge(Integer.valueOf(request.getParameter("age")));
		student.setHeight(Integer.valueOf(request.getParameter("height")));
		student.setCollege(request.getParameter("college"));
		if(studentService.update(student, stuId)){
			student.setCollege(CollegeMap.getCollegeKey(student.getCollege()));
			session.setAttribute("student", student);
			request.getRequestDispatcher("Boundary").forward(request,response);
		}else{
			response.setHeader("Content-type", "text/html;charset=UTF-8");
			PrintWriter out = response.getWriter();
			out.write("修改失败!\n");
			out.flush();
		}
	}
}
