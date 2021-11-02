package controler;

import domain.Module;
import service.ModuleService;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.time.LocalDate;
import java.util.UUID;

@WebServlet("/UpdateModule")
public class UpdateModuleControler extends HttpServlet {
    ModuleService moduleService =new ModuleService();
    public void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException {
        request.setCharacterEncoding("UTF-8");
        String ControlerDirection=request.getParameter("ControlerDirection");
        if(ControlerDirection.equals("update")){
            this.UpdateModule(request,response);
        }else if(ControlerDirection.equals("editModuleNeed")){
            this.UpdateMoneed(request,response);
        }else if(ControlerDirection.equals("insert")){
            this.InsertModule(request,response);
        }else if(ControlerDirection.equals("remove")){
            this.deleteModule(request,response);
        }

    }
    public void doGet(HttpServletRequest request,HttpServletResponse response) throws IOException, ServletException {
        this.doPost(request,response);
    }
    public void UpdateModule(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String Moname =request.getParameter("Moname");
        String Monick =request.getParameter("Monick");
        String Moupdate =LocalDate.now().toString();
        String Nid =request.getParameter("Nid");
        String Mopriority =request.getParameter("Mpriority");
        String Mocontent =request.getParameter("Mocontent");
        String Moneed =request.getParameter("Moneed");
        String Moid =request.getParameter("Moid");
        System.out.println(Moid);
        int result =moduleService.updateModule(Moname,Monick,Moupdate,Nid,Mopriority,Mocontent,Moneed,Moid);
        request.getRequestDispatcher("showModuleList").forward(request,response);
    }
    public void UpdateMoneed(HttpServletRequest request,HttpServletResponse response) throws ServletException, IOException {
        String Moid =request.getParameter("Moid");
        String Moneed=request.getParameter("Moneed");
        System.out.println("update"+Moneed);
        int result= moduleService.updateMoneed(Moneed,Moid);
        request.getRequestDispatcher("showModuleList").forward(request,response);
    }
    public void InsertModule(HttpServletRequest request,HttpServletResponse response) throws ServletException, IOException {
        String Moid= UUID.randomUUID().toString().replaceAll("-","");
        Moid =Moid.replaceAll("[a-zA-Z]","");
        Moid=Moid.substring(Moid.length()-4);
        String Moname =request.getParameter("Moname");
        String Monick =request.getParameter("Monick");
        String Mocreatedate = LocalDate.now().toString();
        String Moupdate ="111";
        String Nid =request.getParameter("Nid");
        String Mopriority =request.getParameter("Mopriority");
        String Mocontent =request.getParameter("Mocontent");
        String Moneed =request.getParameter("Moneed");
        moduleService.InsertModule(new Module(Integer.parseInt(Moid),Moname,Monick,Mocreatedate,Moupdate,Integer.parseInt(Nid),Integer.parseInt(Mopriority),Mocontent,Moneed));
        request.getRequestDispatcher("showModuleList").forward(request,response);
    }
    public void deleteModule(HttpServletRequest request,HttpServletResponse response) throws ServletException, IOException {
        String [] Moids=request.getParameterValues("selectFunction");

        for(int i=0;i<Moids.length;i++){
            moduleService.deleteModuleByMoid(Moids[i]);
        }
        request.getRequestDispatcher("showModuleList").forward(request,response);
    }
}
