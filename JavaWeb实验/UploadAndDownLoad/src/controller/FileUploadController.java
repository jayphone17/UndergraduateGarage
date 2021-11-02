package controller;

import org.apache.commons.fileupload.FileItem;
import org.apache.commons.fileupload.FileUploadException;
import org.apache.commons.fileupload.ProgressListener;
import org.apache.commons.fileupload.disk.DiskFileItemFactory;
import org.apache.commons.fileupload.servlet.ServletFileUpload;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.List;

public class FileUploadController extends HttpServlet {

    protected void doPost(HttpServletRequest request, HttpServletResponse resp) throws ServletException, IOException {
        try {
            //倒入两个jar文件   commons-io.jar    commons-fileupload.jar
            //创建一个  磁盘文件选项的工厂对象
            DiskFileItemFactory factory = new DiskFileItemFactory();
            //factory.setRepository(new File("缓冲区的位置"));//Repository
            factory.setSizeThreshold(1024*1024*3000);// 3G

            //创建一个  Servlet文件上传对象
            ServletFileUpload upload = new ServletFileUpload(factory);
            upload.setSizeMax(1024*1024*100);//100M 设置单个文件的最大字节数  long参数
            upload.setFileSizeMax(1024*1024*300);// 300M 设置单次上传文件的总大小  几个文件一起的总大小
            upload.setProgressListener(new ProgressListener() {
                public void update(long l, long l1, int i) {
                    //第一个long参数表示  已经上传的字节数
                    //第二个long参数表示  文件的总字节数
                    //第三个int参数表示   现在正在上传的组件是第几个
                    //AJAX
                    //4096
                    System.out.println("正在上传第"+i+"个资源"+((double)l/(double)l1)*100+"%");
                }
            });

            //request.setCharacterEncoding("UTF-8");
            //upload.setHeaderEncoding("UTF-8");//处理接受文件字符集
            //文件名字可能重复
            //  用户名 用户浏览器文件名 随机生成一个新的文件名 文件路径
            //  对应关系存在数据库里  随机的新名字当作文件名
            //  用户名 用户浏览器文件名 随机生成一个新的名字  路径
            //  用新名字当作文件夹名 创建一个文件夹

            //upload对象解析request(获取请求传递过来的所有信息)
            List<FileItem> itemList = upload.parseRequest(request);
            //遍历集合
            for(FileItem item:itemList){
                if(item.isFormField()) {//是否是表单的普通组件
                    String key = item.getFieldName();//获取表单组件的name属性
                    String value = item.getString("UTF-8");//获取表单组件的value属性
                    System.out.println(key+"--"+value);
                }else{//表示一个file组件
                    String key = item.getFieldName();//获取表单组件中的name属性
                    String fileName = item.getName();//获取上传文件的文件名
                    System.out.println(key+"---"+fileName);
                    item.write(new File("D://test//"+fileName));

//                    InputStream inputStream = item.getInputStream();
//                    //服务器创建一个文件输出流  将读到的内容存入服务器内部
//                    FileOutputStream fos = new FileOutputStream("D://test//"+fileName);
//                    byte[] b = new byte[1024];
//                    int len = inputStream.read(b);
//                    while(len!=-1){
//                        fos.write(b,0,len);
//                        fos.flush();
//                        len = inputStream.read(b);
//                    }
//                    inputStream.close();
//                    fos.close();
                    //192.168.3.9:8080/UploadAndDownLoad/index.jsp
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
