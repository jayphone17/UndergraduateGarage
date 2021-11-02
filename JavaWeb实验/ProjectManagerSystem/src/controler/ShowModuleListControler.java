package controler;

import domain.Module;
import service.ModuleService;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.ArrayList;

@WebServlet("/showModuleList")
public class ShowModuleListControler extends HttpServlet {
    private ModuleService moduleService =new ModuleService();
    public void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("UTF-8");
        ArrayList<Module> ModuleList =moduleService.getModuleList();
        //转发数据
        System.out.println("Controler"+ModuleList);
        request.setAttribute("ModuleList",ModuleList);
        request.getRequestDispatcher("files/listmokuai.jsp").forward(request,response);
    }
    public void doGet(HttpServletRequest request,HttpServletResponse response) throws ServletException, IOException {
        this.doPost(request,response);
    }
//    public static void main (String []args){
//        ModuleService moduleService =new ModuleService();
//
//        System.out.println(moduleService.getModuleList());
//    }

}
