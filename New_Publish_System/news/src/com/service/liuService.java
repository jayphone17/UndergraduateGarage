package com.service;
import java.sql.ResultSet;
import java.util.ArrayList;
import java.util.List;
import com.dao.DB;
import com.orm.Tnews;

public class liuService
{
	public static String getCatelogName(String id)
	{
		String name="";
		
		String sql="select * from t_catelog where id=?";
		Object[] params={id};
		DB mydb=new DB();
		try
		{
			mydb.doPstm(sql, params);
			ResultSet rs=mydb.getRs();
			rs.next();
			name=rs.getString("name1");
			rs.close();
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
		mydb.closed();
		return name;
	}
	
	public static List getNewsList(String catelog_id)
	{
		List newsList=new ArrayList();
		
		String sql="select * from t_news where del='no' and catelog_id=?";
		Object[] params={catelog_id};
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
		return newsList;
	}
	public static String getUserName(String id)
	{
		String loginname="";
		
		String sql="select * from t_user where id=?";
		Object[] params={id};
		DB mydb=new DB();
		try
		{
			mydb.doPstm(sql, params);
			ResultSet rs=mydb.getRs();
			rs.next();
			loginname=rs.getString("loginname");
			rs.close();
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
		mydb.closed();
		return loginname;
	}
	

}
