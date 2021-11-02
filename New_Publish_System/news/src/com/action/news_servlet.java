package com.action;
import java.io.IOException;
import java.sql.ResultSet;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import javax.servlet.RequestDispatcher;
import javax.servlet.ServletConfig;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import com.dao.DB;
import com.orm.Tnews;
import com.service.liuService;

public class news_servlet extends HttpServlet
{
	public void service(HttpServletRequest req,HttpServletResponse res)throws ServletException, IOException 
	{
        String type=req.getParameter("type");
		if(type.endsWith("newsAdd"))
		{
			newsAdd(req, res);
		}
		if(type.endsWith("newsMana"))
		{
			newsMana(req, res);
		}
		if(type.endsWith("newsDel"))
		{
			newsDel(req, res);
		}
		if(type.endsWith("newsDetail"))
		{
			newsDetail(req, res);
		}
		if(type.endsWith("newsDetailQian"))
		{
			newsDetailQian(req, res);
		}
	}
	public void newsAdd(HttpServletRequest req,HttpServletResponse res)
	{
		//String id=String.valueOf(new Date().getTime());
		String catelog_id=req.getParameter("catelog_id");
		String title=req.getParameter("title");
		String content=req.getParameter("content");
		String shijian=new Date().toLocaleString();
		String del="no";
		String sql="insert into t_news(catelog_id,title,content,shijian,del) values(?,?,?,?,?)";
		Object[] params={catelog_id,title,content,shijian,del};
		DB mydb=new DB();
		mydb.doPstm(sql, params);
		mydb.closed();
		
		req.setAttribute("message", "操作成功");
		req.setAttribute("path", "news?type=newsMana");
		
        String targetURL = "/common/success.jsp";
		dispatch(targetURL, req, res);
        
	}
	public void newsDel(HttpServletRequest req,HttpServletResponse res)
	{
		String id=req.getParameter("id");
		
		String sql="update t_news set del='yes' where id=?";
		Object[] params={id};
		DB mydb=new DB();
		mydb.doPstm(sql, params);
		mydb.closed();
		
		req.setAttribute("message", "操作成功");
		req.setAttribute("path", "news?type=newsMana");
		
        String targetURL = "/common/success.jsp";
		dispatch(targetURL, req, res);
	}
	public void newsMana(HttpServletRequest req,HttpServletResponse res) throws ServletException, IOException
	{
		List newsList=new ArrayList();
		String sql="select * from t_news where del='no'";
		Object[] params={};
		DB mydb=new DB();
		try
		{
			mydb.doPstm(sql, params);
			ResultSet rs=mydb.getRs();
			while(rs.next())
			{
				Tnews news=new Tnews();
				news.setId(rs.getString("id"));
				news.setCatelog_id(rs.getString("catelog_id"));
				news.setTitle(rs.getString("title"));
				news.setContent(rs.getString("content"));
				news.setShijian(rs.getString("shijian"));
				news.setDel(rs.getString("del"));
				news.setCatelog_name(liuService.getCatelogName(rs.getString("catelog_id")));
				
				newsList.add(news);
		    }
			rs.close();
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
		mydb.closed();
		req.setAttribute("newsList", newsList);
		req.getRequestDispatcher("admin/news/newsMana.jsp").forward(req, res);
	}
	public void newsDetail(HttpServletRequest req,HttpServletResponse res) throws ServletException, IOException
	{
		String id=req.getParameter("id");
		Tnews news=new Tnews();
		
		String sql="select * from t_news where id=?";
		Object[] params={id};
		DB mydb=new DB();
		try
		{
			mydb.doPstm(sql, params);
			ResultSet rs=mydb.getRs();
			rs.next();
			
			news.setId(rs.getString("id"));
			news.setTitle(rs.getString("title"));
			news.setContent(rs.getString("content"));
			news.setShijian(rs.getString("shijian"));
			
			rs.close();
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
		mydb.closed();
		
		req.setAttribute("news", news);
		req.getRequestDispatcher("admin/news/newsDetail.jsp").forward(req, res);
	}
	
	public void newsDetailQian(HttpServletRequest req,HttpServletResponse res) throws ServletException, IOException
	{
		String id=req.getParameter("id");
		Tnews news=new Tnews();
		String sql="select * from t_news where id=? order by catelog_id";
		Object[] params={id};
		DB mydb=new DB();
		try
		{
			mydb.doPstm(sql, params);
			ResultSet rs=mydb.getRs();
			rs.next();
			news.setId(rs.getString("id"));
			news.setTitle(rs.getString("title"));
			news.setContent(rs.getString("content"));
			news.setShijian(rs.getString("shijian"));
			
			rs.close();
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
		mydb.closed();
		
		req.setAttribute("news", news);
		req.getRequestDispatcher("qiantai/news/newsDetailQian.jsp").forward(req, res);
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
