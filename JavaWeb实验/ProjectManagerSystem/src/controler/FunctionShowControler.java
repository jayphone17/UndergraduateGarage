package controler;

import com.sun.scenario.effect.impl.sw.sse.SSEBlend_SRC_OUTPeer;
import domain.Function;
import domain.Project;
import service.FunctionService;
import service.ProjectService;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;

@WebServlet("/FunctionShow")
public class FunctionShowControler extends HttpServlet {
    private FunctionService functionService=new FunctionService();
    public void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("UTF-8");//FunctionFid
        String ControlerDirection =request.getParameter("ControlerDirection");
        if(ControlerDirection.equals("edit")){ String  FunctionFid =request.getParameter("FunctionFid");
            Function function= functionService.getFunction(FunctionFid);
            request.setAttribute("Function",function);
            request.getRequestDispatcher("files/editgongnen.jsp").forward(request,response);
        }else if(ControlerDirection.equals("search")){
            String  FunctionFid =request.getParameter("FunctionFid");
            Function function= functionService.getFunction(FunctionFid);
            request.setAttribute("Function",function);
             request.getRequestDispatcher("files/listgongnenmingxi.jsp").forward(request,response);
        }else if(ControlerDirection.equals("editNeed")){
            String  FunctionFid =request.getParameter("FunctionFid");
            Function function= functionService.getFunction(FunctionFid);
            request.setAttribute("Function",function);
            request.getRequestDispatcher("files/gongnengxuqiu.jsp").forward(request,response);
        }else if(ControlerDirection.equals("addFunction")){
            ProjectService projectService=new ProjectService();
            ArrayList<Project> ProjectList =projectService.getProjectList();
            request.setAttribute("ProjectList",ProjectList);
            request.getRequestDispatcher("files/addgongnen.jsp").forward(request,response);
        }
    }
    public void doGet(HttpServletRequest request ,HttpServletResponse response) throws ServletException, IOException {
        this.doPost(request,response);
    }
}
