<%@ page language="java" contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<title>myInfo</title>
</head>
<body>
	<form name="update" method="post" action="Update">
	
		学号: <input type="text" name="stuId" value = "${student.stuId}" style="width: 200px"><br><br> 
		姓名: <input type="text" name="name" value = "${student.name}" style="width: 200px"><br><br> 
		密码: <input type="password" name="password" value = "${student.password}" style="width: 200px"><br><br> 
		年龄: <input type="text" name="age" value = "${student.age}" style="width: 200px"><br><br> 
		身高: <input type="text" name="height" value = "${student.height}" style="width: 200px"><br><br> 
		学院: 
		<select name="college" style="text-align: center;">
			<option value="A">软件学院</option>
			<option value="B">自动化学院</option>
			<option value="C">法学院</option>
			<option value="D">外国语学院</option>
			<option value="E">电气与电子工程学院</option>
			<option value="F">计算机科学与技术学院</option>
			<option value="G">应用科学学院</option>
		</select><br><br>
		
		<script>
			var college = "${student.college}";
			document.getElementsByName("college")[0].value=college;
		</script>
		
		<button type="submit">提 交</button>	
	</form>
</body>

</html>