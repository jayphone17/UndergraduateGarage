<%@ page language="java" import="java.util.*" pageEncoding="utf-8"%>
<%@ taglib uri="/struts-tags" prefix="s" %>
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
	<!--
	<link rel="stylesheet" type="text/css" href="styles.css">
	-->

  <link rel="stylesheet" href="./css/andreas08(blue).css" type="text/css" media="screen,projection" />
<style type="text/css">
<!--
.STYLE1 {color: #FF0000}
-->
</style>
<!--
<script type="text/javascript" src="./js/acesys.js"></script> 
 -->
<script type="text/javascript" src="./js/doublePassword.js" language="javascript"></script>
</head>

<body>
<div id="container" >

<div id="header";>
</div>

<div id="navigation">
<ul>
<li class="selected"></li>
<li><a href="./index.jsp">首页</a></li>
<li><a href="./jieshao.jsp">系统介绍</a></li>
<li><a href="./zhinan.jsp">审报指南</a></li>
<li><a href="./login.jsp">项目申报</a></li>
<li><a href="./lianxi.jsp">联系我们</a></li>
<li></li>
</ul>
</div>

</div>
<div id="container" ><div id="content2"><table width="100%" height="41"  border="0" align="center" cellpadding="0" cellspacing="0"><tr><td width="15" height="18" align="left" valign="top"><div align="left"></div></td>
      <td width="385" align="left" valign="bottom" class="12">&nbsp;</td>
    </tr><tr><td height="4" colspan="2" align="left" valign="bottom"></td>
    </tr><tr><td height="15" align="left" valign="top">&nbsp;</td>
      <td height="15" align="left" valign="top" class="12"><table width="100%" height="20" border="0" cellpadding="0" cellspacing="0"><tr><td height="20" align="center"><div class="right_proaducts">
        <div align="left">我的位置&gt;&gt;科技项目申报&gt;修改本帐户密码</div>
      </div>
      <form namespace="/unit" action="./unit/UpdatePassword.action?id=<s:property value="#session.unit.unit.unitid"/>" method="post" id="form" repeat>
	  <DIV class=padding><DIV id=middlebody>
	   <table cellspacing="0" cellpadding="0" width="100%" border="0"><tbody>
	               <tr>
				   <td><div align="left">|&nbsp;&nbsp;欢迎,单位用户<font color="red"><s:property value="#session.unit.username"/></font>&nbsp;&nbsp;|&nbsp;&nbsp;
	  <a  class="table_t"  href="../index.jsp">注销</a>&nbsp;&nbsp;|&nbsp;&nbsp;<a href="javascript:history.go(-1)">后退</a>&nbsp;&nbsp;|</div></td>
                      <td><div align="center"><a href="./unit/informationAction.action?id=<s:property value="#session.unit.unit.unitid"/>">单位信息</a></div></td>
                      <td><div align="center"><a href="./unit/reworkpassword.jsp">修改密码</a></div></td>
                      <td><div align="center"><a href="./unit/showprojectCategorysAction.action">项目申报管理</a></div></td>
                      <td height="50"><div align="center"><a href="./unit/simpleSearchjsp.action">信息查询</a></div></td>
                      </tr></tbody></table>
<s:fielderror></s:fielderror>
                <table width="50%" border="0" cellpadding="0" cellspacing="1">
                  <tr>
                    <td width="25%" height="20" align="right" bgcolor="#f3f3f3">用户名</td>
                    <td width="2%" align="right" bgcolor="#f3f3f3">&nbsp;</td>
                    <td width="73%" height="20" align="left" bgcolor="#f3f3f3"><div align="left"><s:property value="#session.unit.username"/></div></td>
                  </tr>
                  
                    
                  <tr>
                    <td height="20" align="right" bgcolor="#f3f3f3">原始密码</td>
                    <td align="right" bgcolor="#f3f3f3">&nbsp;</td>
                    <td height="20" align="left" bgcolor="#f3f3f3"><div align="left">
                      <input id="temp1" type="password" value="" id="temp1" name="oldpassword"/>
                        
                    </div></td>
                  </tr>
                  <tr>
                    <td height="20" align="right" bgcolor="#f3f3f3">新密码</td>
                    <td align="right" bgcolor="#f3f3f3">&nbsp;</td>
                    <td height="20" align="left" bgcolor="#f3f3f3"><div align="left">
                      <input id="temp2" type="password" value="" id="temp2" name="newpassword" />
                    </div></td>
                  </tr>
                  <tr>
                    <td height="20" align="right" bgcolor="#f3f3f3">重复新密码</td>
                    <td align="right" bgcolor="#f3f3f3">&nbsp;</td>
                    <td height="20" align="left" bgcolor="#f3f3f3"><div align="left">
                      <input id="temp3" type="password" value=""id="temp3" name="repeatpassword" />
                    </div></td>
                  </tr>
                  <tr>
                    <td height="20" colspan="2" align="middle" bgcolor="#f3f3f3">&nbsp;</td>
                    <td height="20" align="middle" bgcolor="#f3f3f3"><div align="left">
                      <input name="submit" type="submit" value="确认更改"  onclick="return check(form)"/>
                    </div></td>
                  </tr>
                </table>
                <div></div>
              </form></td>
        </tr></table>
        <br/><div class="table_wz"></div></td>
    </tr></table>
</div>
</div>
<div id="container" >
  <div id="footer">
<p><a href="http://www.ascenttech.com.cn/" target="_blank">版权所有：北京亚思晟商务科技有限公司 &copy;2004-2008|京ICP备05005681</a></p>
</div>

</div>
</body>
</html>