<%@ page import="hao.vo.Student" %>
<%@ page import="java.util.List" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
<meta charset="UTF-8">
<title>table</title>
</head>
<body>
	<table border="1">
    <tr>
        <th>学号</th>
        <th>姓名</th>
        <th>性别</th>
        <th>年龄</th>
        <th>身高</th>
        <th>学院</th>
        <th>操作</th>
    </tr>
    <%--List<Student> stuList = (List<Student>)request.getAttribute("stuList"); --%>
    <c:forEach items="${stuList}" var="student"> 
    	<tr>
    		<td>${student.stuId}</td>
    		<td>${student.name}</td>
    		<td>${student.sex}</td>
    		<td>${student.age}</td>
    		<td>${student.height}</td>
    		<td>${student.college}</td>
    		<td><a href="modify?stuId=${student.stuId}">修改</a></td>
    	</tr>
    </c:forEach> 
	</table>
</body>
</html>