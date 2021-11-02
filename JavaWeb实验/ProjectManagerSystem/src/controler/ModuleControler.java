package controler;

import service.ModuleService;

import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class ModuleControler extends HttpServlet {
       private static ModuleService moduleService =new ModuleService();

    public void doPost(HttpServletRequest request, HttpServletResponse response){

    }

}
