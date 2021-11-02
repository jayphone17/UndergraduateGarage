<%@ page language="java" contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>

<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>修改个人信息</title>
</head>
<body>
	
	<form action="Update" method="post">
		学号<input type="text" name="sid" value=""><br><br>
		姓名<input type="text" name="sname" value=""><br><br>
		密码<input type="password" name="password"value=""><br><br>
		年龄<input type="text" name="age" value=""><br><br>
		身高<input type="text" name="height" value=""><br><br>
		学院
			<select name="college">
				<option value="软件学院">软件学院</option>
				<option value="电气学院">电气学院</option>
				<option value="机械学院">机械学院</option>
				<option value="测通学院">测通学院</option>
			</select><br><br>
		<input type="submit" value="提交">
	</form>
	
</body>
</html>