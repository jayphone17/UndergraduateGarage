<%@ page language="java" import="java.util.*" pageEncoding="gb2312"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
<title>科技项目申报系统</title>
<meta http-equiv="content-type" content="text/html; charset=GB2312" />
<meta name="description" content="Your website description goes here" />
<meta name="keywords" content="your,keywords,goes,here" />
<link rel="stylesheet" href="../css/andreas08(blue).css" type="text/css" media="screen,projection" />
<style type="text/css">
<!--
.STYLE1 {color: #FF0000}
-->
</style>
<script language="JavaScript" src="../js/acesys.js"></script>
</head>

<body>
<div id="container" >

<div id="header";>
</div>

<div id="navigation">
<ul>
<li class="selected"></li>
<li><a href="../index.html">首页</a></li>
<li><a href="../jieshao.html">系统介绍</a></li>
<li><a href="../zhinan.html">审报指南</a></li>
<li><a href="../login.html">项目申报</a></li>
<li><a href="../lianxi.html">联系我们</a></li>
<li></li>
</ul>
</div>

</div>
<div id="container" ><div id="content2"><table width="100%" height="41"  border="0" align="center" cellpadding="0" cellspacing="0"><tr><td width="15" height="18" align="left" valign="top"><div align="left"></div></td>
      <td width="385" align="left" valign="bottom" class="12">&nbsp;</td>
    </tr><tr><td height="4" colspan="2" align="left" valign="bottom"></td>
    </tr><tr><td height="15" align="left" valign="top">&nbsp;</td>
      <td height="15" align="left" valign="top" class="12"><table width="100%" height="20" border="0" cellpadding="0" cellspacing="0"><tr><td height="20" align="center"><div class="right_proaducts">
        <div align="left">我的位置&gt;&gt;科技项目申报&gt;项目查询</div>
      </div>
      <form action="" method="post" id="form"><DIV class=padding><DIV id=middlebody>
	 <table cellspacing="0" cellpadding="0" width="100%" border="0">
	  <tbody>
	  <tr><td><div align="left">|&nbsp;&nbsp;欢迎,单位用户&nbsp;&nbsp;|&nbsp;&nbsp;
	  <a class="table_t"  href="../index.html">注销</a>&nbsp;&nbsp;|&nbsp;&nbsp;<a href="javascript:history.go(-1)">后退</a>&nbsp;&nbsp;|</div></td>
         <td><div align="center"><a href="../unit/viewunitinfo.html">单位信息</a></div></td>
         <td><div align="center"><a href="../unit/reworkpassword.html">修改密码</a></div></td>
         <td><div align="center"><a href="../unit/showprojectCategorys.html">项目申报管理</a></div></td>
         <td height="50"><div align="center"><a href="../unit/simpleSearch.html">信息查询</a></div></td>
       </tr>
	   </tbody>
	   </table>
                <table width="100%" height="50" border="0" cellpadding="0" cellspacing="1" bgcolor="#f3f3f3">
                  <tbody>
                    <tr>
                      <td valign="center" align="left" width="20%"><div align="right">项目内容:</div></td>
                      <td width="40%"><input size="40" name="sercontext" />
                      </td>
                      <td width="40%"><div align="left">
                        <input name="submit4" type="submit" value="查询" />
                        
                        <input name="button" type="submit" onclick="return AddNew(form);" value="高级查询" />
                      </div></td>
                    </tr>
                  </tbody>
                </table>
                <table width="100%" border="0" cellpadding="0" cellspacing="1">
                  <tbody>
                    <tr>
                      <td align="center" bgcolor="#fba661">主项目</td>
                      <td align="center" bgcolor="#fba661">分项目</td>
                      <td width="208" align="center" bgcolor="#fba661">操作</td>
                    </tr>
                    <tr>
                      <td width="150" align="center" bgcolor="#f3f3f3">科技研发</td>
                      <td width="342" align="center" bgcolor="#f3f3f3"><a href="../unit/viewprojectinfo1.html">软件研发</a></td>
                      <td align="center" bgcolor="#f3f3f3"><a href="../unit/viewprojectinfo.html">没有评审</a></td>
                    </tr>
                    <tr>
                      <td width="150" align="center" bgcolor="#f3f3f3">工程建设</td>
                      <td width="342" align="center" bgcolor="#f3f3f3"><a href="../unit/viewprojectinfo1.html">地铁工程建设</a></td>
                      <td align="center" bgcolor="#f3f3f3"><a href="../unit/viewprojectinfo.html">没有评审</a></td>
                    </tr>
                    <tr>
                      <td width="150" align="center" bgcolor="#f3f3f3">金融工程</td>
                      <td width="342" align="center" bgcolor="#f3f3f3"><a href="../unit/viewprojectinfo1.html">金融投资项目</a></td>
                      <td align="center" bgcolor="#f3f3f3"><a href="../unit/viewprojectinfo.html">没有评审</a></td>
                    </tr>
                    <tr>
                      <td width="150" align="center" bgcolor="#f3f3f3">航空建设</td>
                      <td width="342" align="center" bgcolor="#f3f3f3"><a href="../unit/viewprojectinfo1.html">航空公司建设项目</a></td>
                      <td align="center" bgcolor="#f3f3f3">专家已评审，不能修改</td>
                    </tr>
                    <tr>
                      <td width="150" align="center" bgcolor="#f3f3f3">奥运工程</td>
                      <td width="342" align="center" bgcolor="#f3f3f3"><a href="../unit/viewprojectinfo1.html">奥运管理系统</a></td>
                      <td align="center" bgcolor="#f3f3f3">专家已评审，不能修改</td>
                    </tr>
                  </tbody>
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