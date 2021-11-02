package com.orm;

public class Tnews     //新闻信息实体类
{
	private String id;
	private String catelog_id;
	private String title;
	private String content;
	
	private String shijian;
	private String del;
	
	private String catelog_name;
	
	public String getContent()
	{
		return content;
	}
	public void setContent(String content)
	{
		this.content = content;
	}
	public String getId()
	{
		return id;
	}
	public void setId(String id)
	{
		this.id = id;
	}
	public String getShijian()
	{
		return shijian;
	}
	public void setShijian(String shijian)
	{
		this.shijian = shijian;
	}
	
	public String getCatelog_name()
	{
		return catelog_name;
	}
	public void setCatelog_name(String catelog_name)
	{
		this.catelog_name = catelog_name;
	}
	public String getTitle()
	{
		return title;
	}
	public void setTitle(String title)
	{
		this.title = title;
	}
	public String getCatelog_id()
	{
		return catelog_id;
	}
	public void setCatelog_id(String catelog_id)
	{
		this.catelog_id = catelog_id;
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
