package hao.servlet;

import java.io.FileInputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import hao.service.StudentService;
import hao.service.StudentServiceImpl;


@WebServlet("/Download")
public class DownLoadServlet extends HttpServlet{

	
	private static final long serialVersionUID = 1L;
	
	private StudentService studentService = new StudentServiceImpl();

	@Override
	protected void service(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		request.setCharacterEncoding("utf-8");
		String stuId = request.getParameter("stuId");
		String filePath = studentService.FindResumePath(stuId);
		if (filePath != null && !filePath.trim().equals("")) {
			response.setContentType(getServletContext().getMimeType(filePath));
			String extension = filePath.substring(filePath.lastIndexOf('.'));
			response.setHeader("Content-Disposition", "attachment;filename=" + stuId + extension);
			FileInputStream fis = new FileInputStream(filePath);
			OutputStream fout = response.getOutputStream();
			byte[] bytes = new byte[1024];
			int size = -1;
			while ((size = fis.read(bytes)) > 0) {
				fout.write(bytes, 0, size);
			}
			fis.close();
			fout.close();
		} else if (filePath == null) {
			response.setHeader("Content-type", "text/html;charset=UTF-8");
			PrintWriter out = response.getWriter();
			out.write("无此学生!\n");
			out.flush();
		} else {
			response.setHeader("Content-type", "text/html;charset=UTF-8");
			PrintWriter out = response.getWriter();
			out.write("此学生无简历文件!\n");
		}
	}
}
