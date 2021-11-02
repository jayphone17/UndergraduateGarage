package controller;

import org.apache.commons.fileupload.servlet.ServletFileUpload;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.net.URLEncoder;

public class DownLoadController extends HttpServlet {

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        //0.获取下载的文件名
        String filename = request.getParameter("filename");
        //1.让服务器找到下载的那个文件资源  文件中的内容
        FileInputStream fis = new FileInputStream("D://test//"+filename);
        //2.如果想要让下载的内容不直接显示在浏览器上
        //  而是一个弹出框  或者是进度条类似的方法
        //<%@ page contentType="text/html;chareset=utf-8" %>

        filename = URLEncoder.encode(filename,"UTF-8");
        response.setContentType("application/x-msdownload");//告知浏览器 回去的信息按照这种方式来处理
        response.setHeader("Content-disposition","attachment;filename="+filename);
        //ServletFileUpLoad  FileUpload  FileUploadBase
//        String x = ServletFileUpload.CONTENT_DISPOSITION;
//        String y = ServletFileUpload.ATTACHMENT;
        //3.response直接给浏览器响应
        OutputStream os = response.getOutputStream();
        byte[] b = new byte[1024];
        int len = fis.read(b);
        while(len!=-1){
            os.write(b,0,len);
            os.flush();
            len = fis.read(b);
        }
        os.close();
        fis.close();
    }
}
