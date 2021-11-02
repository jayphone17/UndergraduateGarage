  package com.Javaweb_shiyan.VO;

public class UserVO {
	private String sId;
	private String sName;
	private String passWord;
	private String sex;
	private int age;
	private String height;
	private String college;
	public String getSid() {
		return sId;
	}
	public void setSid(String sid) {
		this.sId=sid;
	}
	public String getSname() {
		return sName;
	}
	public void setSname(String sname) {
		this.sName=sname;
	}
	public String getPassword() {
		return passWord;
	}
	public void setPassword(String password) {
		this.passWord=password;
	}
	public String getSex() {
		return sex;
	}
	public void setSex(String Sex) {
		this.sex=Sex;
	}
	public int getAge() {
		return age;
	}
	public void setAge(int Age) {
		age=Age;
	}
	public String getHeight() {
		return height;
	}
	public void setHeight(String Height) {
		this.height=Height;
	}
	public String getCollege() {
		return college;
	}
	public void setCollege(String College) {
		this.college=College;
	}
	
}
