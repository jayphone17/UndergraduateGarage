package hao.servlet;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import hao.dao.StudentDao;
import hao.dao.StudentDaoImpl;
import hao.vo.CollegeMap;
import hao.vo.Student;

/**
 * Servlet implementation class updateById
 */
@WebServlet("/updateById")
public class updateById extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public updateById() {
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
		// TODO Auto-generated method stub
		//doGet(request, response);
		
		Student student = new Student();
		StudentDao dao = new StudentDaoImpl();
		student.setStuId(Integer.valueOf(request.getParameter("stuId")));
		student.setName(request.getParameter("name"));
		student.setPassword(request.getParameter("password"));
		student.setAge(Integer.valueOf(request.getParameter("age")));
		student.setHeight(Integer.valueOf(request.getParameter("height")));
		student.setCollege(request.getParameter("college"));
		if(dao.update(student, student.getStuId())){
			//student.setCollege(CollegeMap.getCollegeKey(student.getCollege()));
			//session.setAttribute("student", student);
			//request.getRequestDispatcher("Boundary").forward(request,response);
			response.setHeader("Content-type", "text/html;charset=UTF-8");
			PrintWriter out = response.getWriter();
			out.write("修改成功!\n");
		}else{
			response.setHeader("Content-type", "text/html;charset=UTF-8");
			PrintWriter out = response.getWriter();
			out.write("修改失败!\n");
			out.flush();
		}
		
		
		
		
	}

}
