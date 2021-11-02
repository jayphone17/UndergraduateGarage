<%@ page language="java" contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%@ page import="java.util.ArrayList"%>
<%@ page import="java.util.List"%>
<%@ page import="java.sql.*"%>
<%@ page import="com.Javaweb_shiyan.VO.UserVO"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>show information</title>
</head>
<body>
<table align="center" width="800" border="1">
	<tr>
		<td align="center" colspan="6">
			<h2>所有学生信息</h2>
		</td>
	</tr>
	<tr align="center">
		<td><b>学号</b></td>
		<td><b>姓名</b></td>
		<td><b>年龄</b></td>
		<td><b>身高</b></td>
		<td><b>学院</b></td>
		<td><b>操作</b></td>
	</tr>
	<% List<UserVO> list=(List<UserVO>)request.getAttribute("list");
		if(list==null||list.size()<1){
			out.print("没有数据");
		}else{
			for(UserVO user:list){
		
	
	%>
			<tr align="center">
				<td><%=user.getSid()%></td>
				<td><%=user.getSname()%></td>
				<td><%=user.getAge()%></td>
				<td><%=user.getHeight()%></td>
				<td><%=user.getCollege()%></td>
				<td><a href="update.jsp">修改</a></td>
			</tr>
	<%
			}
		}
		
	%>
</table>
</body>
</html>