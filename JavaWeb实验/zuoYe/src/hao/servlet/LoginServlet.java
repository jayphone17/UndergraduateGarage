package hao.servlet;
import java.io.DataOutput;
import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import hao.dao.StudentDao;
import hao.dao.StudentDaoImpl;
import hao.service.StudentService;
import hao.service.StudentServiceImpl;
import hao.vo.Student;

@WebServlet("/Login")
public class LoginServlet extends HttpServlet {
	
	private static final long serialVersionUID = 1L;
	private StudentService studentService = new StudentServiceImpl();
	
	@Override
	protected void service(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		request.setCharacterEncoding("utf-8");
		String stuId = request.getParameter("stuId");
		String password = request.getParameter("password");
			
		Student stu = studentService.login(stuId, password);
		if(stu != null){
			HttpSession session = request.getSession();
			session.setAttribute("student", stu);
			request.getRequestDispatcher("Boundary").forward(request,response);
		}else{
			StudentDao dao = new StudentDaoImpl();
			if(dao.findStuById(Integer.valueOf(stuId))==null)
				response.sendRedirect("upload.html");
			else
				response.sendRedirect("login.html");
			
			//response.setHeader("Content-type", "text/html;charset=UTF-8");
			//PrintWriter out = response.getWriter();
			//out.write("账号或密码错误\n");
			//out.flush();
		}
	}

}
