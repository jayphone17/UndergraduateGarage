<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
  <body>
    <form action="fileUpload" method="post" enctype="multipart/form-data">
      账号:<input type="text" name="uname" value=""><br>
      密码:<input type="password" name="upass" value=""><br>
      文件1:<input type="file" name="file1"><br>
      文件2:<input type="file" name="file2"><br>
      文件3:<input type="file" name="file3"><br>
      <input type="submit" value="提交">
    </form>
  </body>
</html>
