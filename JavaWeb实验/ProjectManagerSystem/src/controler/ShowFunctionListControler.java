package controler;

import domain.Function;
import service.FunctionService;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.ArrayList;
@WebServlet("/showFunctionList")
public class ShowFunctionListControler extends HttpServlet {
    //此controler展示功能详细列表
    private FunctionService functionService =new FunctionService();
    public void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
            request.setCharacterEncoding("UTF-8");
            ArrayList<Function> FunctionList =functionService.getFunctionList();
            //转发数据
            request.setAttribute("FunctionList",FunctionList);
            request.getRequestDispatcher("files/listgongneng.jsp").forward(request,response);
    }
    public void doGet(HttpServletRequest request,HttpServletResponse response) throws ServletException, IOException {
        this.doPost(request,response);
    }
}


