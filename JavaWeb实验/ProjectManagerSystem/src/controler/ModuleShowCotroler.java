package controler;

import domain.Module;
import domain.Project;
import service.ModuleService;
import service.ProjectService;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.ArrayList;

@WebServlet("/ModuleShow")
public class ModuleShowCotroler extends HttpServlet {
    ModuleService moduleService =new ModuleService();
    public void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("UTF-8");
        String ControlerDirection = request.getParameter("ControlerDirection");
        if (ControlerDirection.equals("search")) {
            String ModuleMoid = request.getParameter("ModuleMoid");
            Module module = moduleService.getModulebyMoid(Integer.parseInt(ModuleMoid));
            request.setAttribute("Module", module);
            request.getRequestDispatcher("files/listmokuaimingxi.jsp").forward(request, response);
        } else if (ControlerDirection.equals("edit")) {
            ArrayList<Project>ProjectList =ProjectService.getProjectList();
            String ModuleMoid = request.getParameter("ModuleMoid");
            Module module = moduleService.getModulebyMoid(Integer.parseInt(ModuleMoid));
            request.setAttribute("Module", module);//
            request.setAttribute("ProjectList",ProjectList);
            request.getRequestDispatcher("files/editmokuai.jsp").forward(request, response);
        }else if(ControlerDirection.equals("editNeed")){
            String ModuleMoid= request.getParameter("ModuleMoid");
            Module module = moduleService.getModulebyMoid(Integer.parseInt(ModuleMoid));
            request.setAttribute("Module",module);
            request.getRequestDispatcher("files/mokuaixuqiu.jsp").forward(request,response);
        }else if(ControlerDirection.equals("addModule")){
            ProjectService projectService=new ProjectService();
            ArrayList<Project> ProjectList =projectService.getProjectList();
            request.setAttribute("ProjectList",ProjectList);
            request.getRequestDispatcher("files/addmokuai.jsp").forward(request,response);
        }
    }
    public void doGet(HttpServletRequest request,HttpServletResponse response) throws ServletException, IOException {
        this.doPost(request,response);
    }

}
