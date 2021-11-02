package com.orm;

import java.util.List;

/**
 * @author Administrator
 *
 */
public class Tcatelog             //新闻类别实体类
{
	private String id;
	private String name1;
	private String del;
	
	private List newsList;
	
	public String getId()
	{
		return id;
	}
	public void setId(String id)
	{
		this.id = id;
	}
	public String getName1()
	{
		return name1;
	}
	
	public List getNewsList()
	{
		return newsList;
	}
	public void setNewsList(List newsList)
	{
		this.newsList = newsList;
	}
	public void setName1(String name1)
	{
		this.name1 = name1;
	}
	public String getDel()
	{
		return del;
	}
	public void setDel(String del)
	{
		this.del = del;
	}
	
	
}
