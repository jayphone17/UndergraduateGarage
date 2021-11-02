package controler;

import com.alibaba.fastjson.JSONObject;
import domain.Need;
import service.NeedService;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.ArrayList;
@WebServlet("/selectNeed")
public class selectNeedControler extends HttpServlet {
    private  NeedService needService= new NeedService();
    public void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException {
        String Pjtid =request.getParameter("Pjtid");
       System.out.println(Pjtid);
        ArrayList<Need>NeedList =  needService.getNeedListByPjtid(Pjtid);
         JSONObject jsonObject=new JSONObject();
        jsonObject.put("NeedList",NeedList);
        System.out.println("nEELDF"+jsonObject);
        response.getWriter().write(jsonObject.toJSONString());
    }
    public void doGet(HttpServletRequest request,HttpServletResponse response) throws IOException {
        this.doPost(request,response);
    }

}

