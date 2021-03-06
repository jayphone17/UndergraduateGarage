package com.action;
import java.io.IOException;
import java.sql.ResultSet;
import java.util.ArrayList;
import java.util.List;
import javax.servlet.RequestDispatcher;
import javax.servlet.ServletConfig;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import com.dao.DB;
import com.orm.Tcatelog;
import com.orm.Tgonggao;
import com.service.liuService;

public class index_servlet extends HttpServlet
{
	public void service(HttpServletRequest req,HttpServletResponse res)throws ServletException, IOException 
	{
		
		List gonggaoList=new ArrayList();
		String sql="select * from t_gonggao order by id desc";
		Object[] params={};
		DB mydb=new DB();
		try
		{
			mydb.doPstm(sql, params);
			ResultSet rs=mydb.getRs();
			while(rs.next())
			{
				Tgonggao gonggao=new Tgonggao();
				
				gonggao.setId(rs.getString("id"));
				gonggao.setTitle(rs.getString("title"));
				gonggao.setContent(rs.getString("content"));
				gonggao.setShijian(rs.getString("shijian"));
				
				gonggaoList.add(gonggao);
		    }
			rs.close();
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
		mydb.closed();
		if(gonggaoList.size()>5)
		{
			gonggaoList=gonggaoList.subList(0, 5);
		}
		req.getSession().setAttribute("gonggaoList", gonggaoList);
		List catelogList=new ArrayList();
		String sqlOOOO="select * from t_catelog where del='no' order by id desc";
		Object[] paramsOOOO={};
		DB mydbOOOO=new DB();
		try
		{
			mydbOOOO.doPstm(sqlOOOO, paramsOOOO);
			ResultSet rsOOOO=mydbOOOO.getRs();
			while(rsOOOO.next())
			{
					Tcatelog catelog=new Tcatelog();
					
					catelog.setId(rsOOOO.getString("id"));
					catelog.setName1(rsOOOO.getString("name1"));
					catelog.setDel(rsOOOO.getString("del"));
					catelog.setNewsList(liuService.getNewsList(rsOOOO.getString("id")));
					
					catelogList.add(catelog);
		    }
			rsOOOO.close();
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
		mydb.closed();
		req.setAttribute("catelogList", catelogList);
		req.getRequestDispatcher("qiantai/index.jsp").forward(req, res);
	}
	public void dispatch(String targetURI,HttpServletRequest request,HttpServletResponse response) 
	{
		RequestDispatcher dispatch = getServletContext().getRequestDispatcher(targetURI);
		try 
		{
		    dispatch.forward(request, response);
		    return;
		} 
		catch (ServletException e) 
		{
                    e.printStackTrace();
		} 
		catch (IOException e) 
		{
			
		    e.printStackTrace();
		}
	}
	public void init(ServletConfig config) throws ServletException 
	{
		super.init(config);
	}
	public void destroy() 
	{
		
	}
}
