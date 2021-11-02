package hao.servlet;

import java.io.IOException;
import java.io.OutputStream;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.apache.poi.hssf.usermodel.HSSFWorkbook;

import hao.service.StudentService;
import hao.service.StudentServiceImpl;

@WebServlet("/ToExcel")
public class ToExcelServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
	private StudentService studentService = new StudentServiceImpl();
	
    @Override
    protected void service(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException { 
    	//request.setCharacterEncoding("utf-8");
		String min = request.getParameter("min");
		String max = request.getParameter("max");
		HSSFWorkbook workbook = studentService.getWorkbook(min, max);
		if(workbook!=null){
			String fileName = new String("学生信息.xls".getBytes("utf-8"), "ISO8859-1");
			//String fileName = new String("学生信息.xls");
			
			response.setContentType(getServletContext().getMimeType(fileName));
			response.setHeader("Content-Disposition", "attachment;filename=" +fileName);
			OutputStream out = response.getOutputStream();
			workbook.write(out);
			out.close();
			workbook.close();
		}else{
			response.setHeader("Content-type", "text/html;charset=UTF-8");
	    	PrintWriter out = response.getWriter();
	    	out.write("无符合条件的学生!\n");
		}
    }
   

}
