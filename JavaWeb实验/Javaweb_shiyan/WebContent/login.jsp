<%@ page language="java" contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>注册</title>
</head>
<body>
<form action="Reg" method="post">
学号<input type="text" name="sid"><br><br>
姓名<input type="text" name="sname"><br><br>
密码<input type="password" name="password"><br><br>
性别
<input type="radio" name="sex" value="男" checked>男
<input type="radio" name="sex" value="女">女<br><br>
年龄<input type="text" name="age"><br><br>
身高<input type="text" name="height"><br><br>
学院
<select name="college">
<option value="软件学院">软件学院</option>
<option value="电气学院">电气学院</option>
<option value="机械学院">机械学院</option>
<option value="测通学院">测通学院</option>
</select><br><br>
照片<input type="file" name="spicture"><br><br>
简历<input type="file" name="sword"><br><br>
<input type="submit" value="提交">
</form>
</body>
</html>