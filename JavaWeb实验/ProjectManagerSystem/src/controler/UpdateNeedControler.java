package controler;

import service.NeedService;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet("/UpdateNeed")//用来改功能模块 里的功能需求
public class UpdateNeedControler extends HttpServlet {

    NeedService needService =new NeedService();
    public void doPost(HttpServletRequest request, HttpServletResponse response){
        String action =request.getParameter("action");
        if(action.equals("editNeed")){

            this.edit(request,response);
        }

    }
    public void doGet(HttpServletRequest request,HttpServletResponse response){
        this.doPost(request,response);
    }
    public void edit(HttpServletRequest request, HttpServletResponse response){
        String Nid =request.getParameter("Nid");
        String NeedContent =request.getParameter("NeedContent");
        needService.editNeedContent(NeedContent,Nid);
    }
}
