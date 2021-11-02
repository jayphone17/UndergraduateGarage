package controler;

import service.FunctionService;


import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.time.LocalDate;
import java.util.HashMap;
import java.util.UUID;

import static javafx.scene.input.KeyCode.Z;

@WebServlet("/UpdateFunction")
public class UpdateFunctionControler extends HttpServlet {
    FunctionService functionService=new FunctionService();
    public void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String ControlerDirection  =request.getParameter("ControlerDirection");
        request.setCharacterEncoding("UTF-8");
        if(ControlerDirection.equals("update")){
            this.UpdateFunction(request,response);
        }else if (ControlerDirection.equals("insert")){
            this.InsertFunction(request,response);
        }else if(ControlerDirection.equals("remove")){
            this.delectFucntion(request,response);
        }



    }


    public void doGet(HttpServletRequest request,HttpServletResponse response) throws ServletException, IOException {
        this.doPost(request,response);
    }

    private void UpdateFunction(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String Fid =request.getParameter("Fid");
        String Fname =request.getParameter("Fname");//功能名称
        String Fversion =request.getParameter("Fversion");
        String ProjectName=request.getParameter("ProjectName");
        String ModuleName =request.getParameter("ModuleName");
        String Fpriority=request.getParameter("Fpriority");
        String Fcontent=request.getParameter("Fcontent");
        int result =functionService.updateFunction(Fname,Fversion,ProjectName,ModuleName,Fpriority,Fcontent,Fid);
        request.getRequestDispatcher("showFunctionList").forward(request,response);
    }
    private  void InsertFunction(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        String Functioncreate= LocalDate.now().toString();
        String ProjectPjtid =request.getParameter("selectProject");
        String FunctionName =request.getParameter("FunctionName");
        String Functionversion =request.getParameter("Functionversion");
        String Functionpriority=request.getParameter("Functionpriority");
        String ModuleMoid=request.getParameter("Moid");
        String FunctionContent=request.getParameter("FunctionContent");
        String FID= UUID.randomUUID().toString().replaceAll("-","");
        FID =FID.replaceAll("[a-zA-Z]","");
        FID=FID.substring(FID.length()-4);
        int result=functionService.insertFunction(FID,FunctionName,Functioncreate,"0",ModuleMoid,Functionpriority,FunctionContent,"无功能需求",Functionversion);
        request.getRequestDispatcher("showFunctionList").forward(request,response);
    }
    public  void delectFucntion(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        String [] Fids=request.getParameterValues("selectFunction");
        System.out.println(Fids);
            for(int i=0;i<Fids.length;i++){
                functionService.deleteFunctionByFid(Fids[i]);
            }
            request.getRequestDispatcher("showFunctionList").forward(request,response);
    }


}
