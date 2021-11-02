package controler;

import com.alibaba.fastjson.JSONObject;
import domain.Module;
import service.ModuleService;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.ArrayList;

@WebServlet("/selectModule")
public class SelectModuleControler extends HttpServlet  {
    private ModuleService moduleService =new ModuleService();
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException {
        String Pjtid=request.getParameter("Pjtid");
        ArrayList<Module> ModuleList= moduleService.getModuleListbyPjtid(Pjtid);
        JSONObject jsonObject=new JSONObject();
        jsonObject.put("ModuleList",ModuleList);
        response.getWriter().write(jsonObject.toJSONString());
    }


}
