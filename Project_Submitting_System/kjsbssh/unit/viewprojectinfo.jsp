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
      <td height="15" align="left" valign="top" class="12">
	  <table width="100%" height="20" border="0" cellpadding="0" cellspacing="0"><tr><td height="20" align="center"><div class="right_proaducts">
        <div align="left">我的位置&gt;&gt;科技项目申报&gt;项目详细信息</div>
      </div>
      <form action="../unit/unit_index.html" method="post" id="form"><DIV class=padding><DIV id=middlebody>
	   <table cellspacing="0" cellpadding="0" width="100%" border="0">
	  <tbody>
	  <tr><td><div align="left">|&nbsp;&nbsp;欢迎,单位用户&nbsp;&nbsp;|&nbsp;&nbsp;
	  <a class="table_t"  href="../index.html">注销</a>&nbsp;&nbsp;|&nbsp;&nbsp;
	  <a href="javascript:history.go(-1)">后退</a>&nbsp;&nbsp;|</div></td>
         <td><div align="center"><a href="../unit/viewunitinfo.html">单位信息</a></div></td>
         <td><div align="center"><a href="../unit/reworkpassword.html">修改密码</a></div></td>
         <td><div align="center"><a href="../unit/showprojectCategorys.html">项目申报管理</a></div></td>
         <td height="50"><div align="center"><a href="../unit/simpleSearch.html">信息查询</a></div></td>
       </tr>
	   </tbody>
	   </table>
                <table width="60%" border="0" cellpadding="0" cellspacing="1">
                  <tbody>
                    <tr>
                      <td width="22%" bgcolor="#f3f3f3"><div align="right">项目名称</div></td>
                      <td width="2%" bgcolor="#f3f3f3">&nbsp;</td>
                      <td width="76%" bgcolor="#f3f3f3"><div align="left">
                          <input size="40" value="科技研发" name="editProject.projectname" />
                      </div></td>
                    </tr>
                    <tr>
                      <td bgcolor="#f3f3f3"><div align="right">申请单位</div></td>
                      <td bgcolor="#f3f3f3">&nbsp;</td>
                      <td bgcolor="#f3f3f3"><div align="left">util <font color="#FF0000">如需修改，请点击单位信息处更改</font></div></td>
                    </tr>
                    <tr>
                      <td bgcolor="#f3f3f3"><div align="right">申请人</div></td>
                      <td bgcolor="#f3f3f3">&nbsp;</td>
                      <td bgcolor="#f3f3f3"><div align="left">
                          <input size="40" value="henry" name="editProject.applicant" />
                      </div></td>
                    </tr>
                    <tr>
                      <td bgcolor="#f3f3f3"><div align="right">职称</div></td>
                      <td bgcolor="#f3f3f3">&nbsp;</td>
                      <td bgcolor="#f3f3f3"><div align="left">
                          <input size="40" value="项目经理" name="editProject.grade" />
                      </div></td>
                    </tr>
                    <tr>
                      <td bgcolor="#f3f3f3"><div align="right">学历</div></td>
                      <td bgcolor="#f3f3f3">&nbsp;</td>
                      <td bgcolor="#f3f3f3"><div align="left">
                          <input size="40" value="研究生" name="editProject.education" />
                      </div></td>
                    </tr>
                    <tr>
                      <td bgcolor="#f3f3f3"><div align="right">填报时间</div></td>
                      <td bgcolor="#f3f3f3">&nbsp;</td>
                      <td bgcolor="#f3f3f3"><div align="left">2008-12-26 <font color="#FF0000">此项如需修改，请联系管理员</font></div></td>
                    </tr>
                    <tr>
                      <td bgcolor="#f3f3f3"><div align="right">项目现状</div></td>
                      <td bgcolor="#f3f3f3">&nbsp;</td>
                      <td bgcolor="#f3f3f3"><div align="left">
                          <input size="40" value="研发中" name="editProject.status" />
                      </div></td>
                    </tr>
                    <tr>
                      <td bgcolor="#f3f3f3"><div align="right">项目前景</div></td>
                      <td bgcolor="#f3f3f3">&nbsp;</td>
                      <td bgcolor="#f3f3f3"><div align="left">
                          <input size="40" value="良好" name="editProject.future" />
                      </div></td>
                    </tr>
                    <tr>
                      <td bgcolor="#f3f3f3"><div align="right">重难点分析</div></td>
                      <td bgcolor="#f3f3f3">&nbsp;</td>
                      <td bgcolor="#f3f3f3"><div align="left">
                          <input size="40" value="研发精度" name="editProject.analysis" />
                      </div></td>
                    </tr>
                    <tr>
                      <td bgcolor="#f3f3f3"><div align="right">研究方法</div></td>
                      <td bgcolor="#f3f3f3">&nbsp;</td>
                      <td bgcolor="#f3f3f3"><div align="left">
                          <input size="40" value="科学计算方法" name="editProject.way" />
                      </div></td>
                    </tr>
                    <tr>
                      <td bgcolor="#f3f3f3"><div align="right">预计研究成果</div></td>
                      <td bgcolor="#f3f3f3">&nbsp;</td>
                      <td bgcolor="#f3f3f3"><div align="left">
                          <input size="40" value="初步成效" name="editProject.result" />
                      </div></td>
                    </tr>
                    <tr>
                      <td bgcolor="#f3f3f3"><div align="right">申请资金</div></td>
                      <td bgcolor="#f3f3f3">&nbsp;</td>
                      <td bgcolor="#f3f3f3"><div align="left">
                          <input size="40" value="100万" name="editProject.capital" />
                      </div></td>
                    </tr>
                    <tr>
                      <td colspan="3" align="middle" bgcolor="#f3f3f3"><div align="center">
                          <input name="submit5" type="submit" value="修改" />
                      </div></td>
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