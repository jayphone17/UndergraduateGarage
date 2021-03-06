<%@ page language="java" import="java.util.*" pageEncoding="utf-8"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">

    <title>科技项目申报系统</title>

	<meta http-equiv="pragma" content="no-cache">
	<meta http-equiv="cache-control" content="no-cache">
	<meta http-equiv="expires" content="0">
	<meta http-equiv="keywords" content="keyword1,keyword2,keyword3">
	<meta http-equiv="description" content="This is my page">
<link rel="stylesheet"  id="styles" href="./css/andreas08(blue).css" type="text/css" media="screen,projection" />
<script type="text/javascript" src="./js/acesys.js"></script>

	<!--
	<link rel="stylesheet" type="text/css" href="styles.css">
	-->

  </head>

  <body>
  <div id="container" >

<div id="header";>
</div>

<div id="navigation">
<ul>
<li class="selected"></li>
<li><a href="index.jsp">首页</a></li>
<li><a href="jieshao.jsp">系统介绍</a></li>
<li><a href="zhinan.jsp">审报指南</a></li>
<li><a href="login.jsp">项目申报</a></li>
<li><a href="lianxi.html">联系我们</a></li>
<li></li>
</ul>
</div>

</div>
<div id="container" >
  <div id="content11">
<h2><strong>欢迎使用项目申报系统</strong></h2>

<table cellspacing="0" cellpadding="0" width="95%">
  <tbody>
    <tr>
      <td><br />
        1．申报单位登录页<br />
        申报单位从<a href="./login.jsp">这里</a>登录。在系统的首页上点击&quot;项目管理&quot;栏后屏幕显示出登录界面，按要求输入用户名、密码。
        <p><br />
          图4-1<br />
          2．单位信息管理页<br />
          <br />
          图4-2<br />
          登录成功之后，系统显示出如图4-2所示的功能界面。点击&quot;单位信息&quot;按钮您就可以进行单位信息查询与修改的工作了。建议每年在进行项目申报时对本单位信息进行更新。<br />
          3．项目申报/项目管理<br />
          在图4-2所示的功能界面中，点击&quot;项目申报&quot;后进入如图4-3所示界面。<br />
          <br />
          图4-3<br />
          该页面显示本单位已申报项目目录。点击项目名称可显示项目信息。在项目申报期间可对已申报项目内容进行修改，不在项目申报期间只可查阅不能修改。<br />
          如果要申报新项目可以点击图4-3中&quot;申报新项目&quot;按钮，页面将会转为项目申报书页面。在申报书页面添入项目申报的相应信息，最后点击&quot;提交&quot;则新项目申报完成。<br />
          该页面显示本单位已推荐专家目录。点击专家姓名可显示专家信息。<br />
          <br />
          2．信息查询页<br />
          <br />
          在单位页面点击信息查询，可以进行项目查询，查看工作状态及修改事项．可以依据申请日期、标题进行匹配查询。<br />
<br />
        </p>
        </td>
    </tr>
  </tbody>
</table>
</div>

</div>
<div id="container">
  <div id="footer">
    <p></p>
  </div>

</div>
</body>
</html>
