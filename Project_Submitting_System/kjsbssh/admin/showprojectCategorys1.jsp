<%@ page language="java" import="java.util.*" pageEncoding="utf-8"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
<title>科技项目申报系统</title>
<meta http-equiv="content-type" content="text/html; charset=utf-8" />
<meta name="description" content="Your website description goes here" />
<meta name="keywords" content="your,keywords,goes,here" />
<link rel="stylesheet" href="../css/andreas08(blue).css" type="text/css" media="screen,projection" />
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
<div id="container" >
  <div id="content2">
    <table width="100%" height="41"  border="0" align="center" cellpadding="0" cellspacing="0">
    <tr>
      <td width="15" height="18" align="left" valign="top"><div align="left"></div></td>
      <td width="385" align="left" valign="bottom" class="12">&nbsp;</td>
    </tr>
    <tr>
      <td height="4" colspan="2" align="left" valign="bottom"></td>
    </tr>
    <tr>
      <td height="15" align="left" valign="top">&nbsp;</td>
      <td height="15" align="left" valign="top" class="12"><table width="100%" height="20" border="0" cellpadding="0" cellspacing="0">
        <tr>
          <td height="20"><div class="right_proaducts">我的位置&gt;&gt;科技项目申报&gt;项目分类列表<br />
                  <br />
            </div>
              <form action="" method="post" id="form">
                <DIV class=padding>
                <DIV id=middlebody>
                <table cellspacing="0" cellpadding="0" width="100%" border="0">
                  <tbody>
                    <tr>
	                <td><div align="left">|&nbsp;&nbsp;欢迎,admin&nbsp;&nbsp;|&nbsp;&nbsp;
	                   <a  class="table_t"  href="../index.html">注销</a>&nbsp;&nbsp;|&nbsp;&nbsp;
	                   <a href="javascript:history.go(-1)">后退</a>&nbsp;&nbsp;|</div></td>
                      <td><div align="center"><a 
      href="../admin/showusers.html">登录用户管理</a></div></td>
                      <td><div align="center"><a 
      href="../admin/showexperts.html">专家信息管理</a></div></td>
                      <td height="50"><div align="center"><a 
      href="../admin/showunits.html">单位信息管理</a></div></td>
                      <td><div align="center"><a 
      href="../admin/showprojectCategorys.html">项目管理</a></div></td>
                    </tr>
                  </tbody>
                </table>
                <table class="mars" cellspacing="1" cellpadding="0" width="100%" border="0">
                  <tbody>
                    <tr bgcolor="#fba661" height="30">
                      <td width="7%"><div align="center">编号ID</div></td>
                      <td width="15%"><div align="center">分类名称</div></td>
                      <td width="18%"><div align="center">申报开始时间</div></td>
                      <td width="14%"><div align="center">申报结束时间</div></td>
                      <td width="20%"><div align="center">评审专家</div></td>
                      <td width="13%"><div align="center">修改</div></td>
                      <td width="13%"><div align="center">删除</div></td>
                    </tr>
                    <tr bgcolor="#e4f1fe">
                      <td bgcolor="#f3f3f3"><div align="center">1</div></td>
                      <td bgcolor="#f3f3f3"><div align="center">java培养研究</div></td>
                      <td bgcolor="#f3f3f3"><div align="center">2008-11-14</div></td>
                      <td bgcolor="#f3f3f3"><div align="center">2008-12-19</div></td>
                      <td bgcolor="#f3f3f3"><div align="center">AA</div></td>
                      <td bgcolor="#f3f3f3"><div align="center"><a href="../admin/adminupdateshowprojects.html">修改</a></div></td>
                      <td bgcolor="#f3f3f3"><div align="center"><a href="../admin/showprojectCategorys1.html">删除</a></div></td>
                    </tr>
                    <tr bgcolor="#e4f1fe">
                      <td bgcolor="#f3f3f3"><div align="center">2</div></td>
                      <td bgcolor="#f3f3f3"><div align="center">绿色环保课题</div></td>
                      <td bgcolor="#f3f3f3"><div align="center">2008-11-15</div></td>
                      <td bgcolor="#f3f3f3"><div align="center">2008-12-18</div></td>
                      <td bgcolor="#f3f3f3"><div align="center">AA</div></td>
                      <td bgcolor="#f3f3f3"><div align="center"><a href="../admin/adminupdateshowprojects.html">修改</a></div></td>
                      <td bgcolor="#f3f3f3"><div align="center"><a href="../admin/showprojectCategorys1.html">删除</a></div></td>
                    </tr>
                    <tr bgcolor="#e4f1fe">
                      <td bgcolor="#f3f3f3"><div align="center">3</div></td>
                      <td bgcolor="#f3f3f3"><div align="center">新添加类别测试1</div></td>
                      <td bgcolor="#f3f3f3"><div align="center">2008-11-16</div></td>
                      <td bgcolor="#f3f3f3"><div align="center">2008-12-19</div></td>
                      <td bgcolor="#f3f3f3"><div align="center">AA</div></td>
                      <td bgcolor="#f3f3f3"><div align="center"><a href="../admin/adminupdateshowprojects.html">修改</a></div></td>
                      <td bgcolor="#f3f3f3"><div align="center"><a href="../admin/showprojectCategorys1.html">删除</a></div></td>
                    </tr>
                    <tr bgcolor="#e4f1fe">
                      <td bgcolor="#f3f3f3"><div align="center">4</div></td>
                      <td bgcolor="#f3f3f3"><div align="center">SSHB</div></td>
                      <td bgcolor="#f3f3f3"><div align="center">2008-11-17</div></td>
                      <td bgcolor="#f3f3f3"><div align="center">2009-01-15</div></td>
                      <td bgcolor="#f3f3f3"><div align="center">null</div></td>
                      <td bgcolor="#f3f3f3"><div align="center"><a href="/admin/adminupdateshowprojects.html">修改</a></div></td>
                      <td bgcolor="#f3f3f3"><div align="center"><a href="../admin/showprojectCategorys1.html">删除</a></div></td>
                    </tr>
                    <tr bgcolor="#e4f1fe">
                      <td height="20" colspan="7" valign="bottom" bgcolor="#FFFFFF"><div align="center"><a 
      href="../admin/addprojectcategory.html">新增加类别</a></div></td>
                    </tr>
                  </tbody>
                </table>
                <div></div>
              </form></td>
        </tr>
      </table>
        <br/>
          <div class="table_wz"></div></td>
    </tr>
  </table>
</div>
</div>
<div id="container" >
  <div id="footer">
<p><a href="http://www.ascenttech.com.cn/" target="_blank">版权所有：北京亚思晟商务科技有限公司 &copy;2004-2008|京ICP备05005681</a></p>
</div>

</div>
</body>
</html>