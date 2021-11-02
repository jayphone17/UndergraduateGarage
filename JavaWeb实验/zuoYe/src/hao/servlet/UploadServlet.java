package hao.servlet;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.annotation.MultipartConfig;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.Part;

import hao.service.StudentService;
import hao.service.StudentServiceImpl;

import hao.vo.Student;

@WebServlet(urlPatterns="/Upload")
@MultipartConfig(location = "D:/tmp/", maxFileSize = 1024 * 1024 * 10, maxRequestSize = 1024 * 1024 * 20)
public class UploadServlet extends HttpServlet {

	private static final long serialVersionUID = 1L;
	private StudentService studentService = new StudentServiceImpl();

	@Override
	protected void service(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		request.setCharacterEncoding("utf-8");
		response.setHeader("Content-type", "text/html;charset=UTF-8");
		
		Student student = new Student();
		student.setStuId(Integer.valueOf(request.getParameter("stuId")));
		student.setName(request.getParameter("name"));
		student.setPassword(request.getParameter("password"));
		student.setSex(request.getParameter("sex"));
		student.setAge(Integer.valueOf(request.getParameter("age")));
		student.setHeight(Integer.valueOf(request.getParameter("height")));
		student.setCollege(request.getParameter("college"));
		Part part1 = request.getPart("file1");
		Part part2 = request.getPart("file2");
		String filename1 = part1.getSubmittedFileName();
		String filename2 = part2.getSubmittedFileName();
		System.out.println(filename1);
		System.out.println(filename2);
		String destfilename1 = "";
		String destfilename2 = "";
		if (filename1 != null && !filename1.equals("")) {
			String extension = filename1.substring(filename1.lastIndexOf('.'));
			destfilename1 = System.currentTimeMillis() + extension;
		}
		if (filename2 != null && !filename2.equals("")) {
			String extension = filename2.substring(filename2.lastIndexOf('.'));
			destfilename2 = System.currentTimeMillis() + extension;
		}
		student.setPhoto(destfilename1);
		student.setResume(destfilename2);
		if (studentService.upload(student)) {
			if (!destfilename1.equals("")) {
				part1.write(destfilename1);
				part1.delete();
			}
			if (!destfilename2.equals("")) {
				part2.write(destfilename2);
				part2.delete();
			}
			
			request.getRequestDispatcher("/table").forward(request, response);
		} else {
			PrintWriter out = response.getWriter();
			out.write("失败\n");
			out.flush();
		}

	}
}
