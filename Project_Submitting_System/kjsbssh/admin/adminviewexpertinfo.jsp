<%@ page language="java" import="java.util.*" pageEncoding="utf-8"%>
<%@ taglib uri="/struts-tags" prefix="s"%>
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
<li><a href="./index.jsp">首页</a></li>
<li><a href="./jieshao.jsp">系统介绍</a></li>
<li><a href="./zhinan.jsp">审报指南</a></li>
<li><a href="./login.jsp">项目申报</a></li>
<li><a href="./lianxi.jsp">联系我们</a></li>
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
          <td height="20" align="center"><div class="right_proaducts">
            <div align="left">我的位置&gt;&gt;科技项目申报&gt;专家信息<br />
              <br />
            </div>
          </div>
              <form action="./expert/UpdateExpert.action?id=<s:property value="#expert.expertid"/>" method="post" id="form" namespace="/expert">
                <DIV class=padding>
                <DIV id=middlebody>
                <table cellspacing="0" cellpadding="0" width="100%" border="0">
                  <tbody>
                   <tr>
	                <td><div align="left">|&nbsp;&nbsp;欢迎,admin&nbsp;&nbsp;|&nbsp;&nbsp;
	                   <a  class="table_t"  href="./index.jsp">注销</a>&nbsp;&nbsp;|&nbsp;&nbsp;
	                   <a href="javascript:history.go(-1)">后退</a>&nbsp;&nbsp;|</div></td>
                      <td><div align="center"><a 
      href="./admin/FindAllUser.action">登录用户管理</a></div></td>
                      <td><div align="center"><a 
      href="./admin/ShowAllExperts.action">专家信息管理</a></div></td>
                      <td height="50"><div align="center"><a 
      href="./admin/showunits.html">单位信息管理</a></div></td>
                      <td><div align="center"><a 
      href="./admin/showprojectCategorys.html">项目管理</a></div></td>
                    </tr>
                  </tbody>
                </table>
                <table width="50%" border="0" cellpadding="0" cellspacing="1">
                  <tr>
                     <s:property value="#expert.name"/>
                    <td width="19%" height="20" align="center" bgcolor="#f3f3f3"><div align="center">姓名 </div></td>
                    <td width="81%" height="20" bgcolor="#f3f3f3"><div align="left">
                      <input id="name" type="text" value="<s:property value="#expert.name"/>" name="expert.name" />
                                    
                    </div></td>
                  </tr>
                  <tr>
                    <td height="20" align="center" bgcolor="#f3f3f3"><div align="center">单位</div></td>
                    <td height="20" bgcolor="#f3f3f3"><div align="left">
                      <input id="unitname" type="text" value="<s:property value="#expert.unitname"/>" name="expert.unitname" />                    
                    </div></td>
                  </tr>
                  <tr>
                    <td height="20" align="center" bgcolor="#f3f3f3"><div align="center">职称</div></td>
                    <td height="20" bgcolor="#f3f3f3"><div align="left">
                      <input id="title" type="text" value="<s:property value="#expert.title"/>" name="expert.title" />                    
                    </div></td>
                  </tr>
                  <tr>
                    <td height="20" align="center" bgcolor="#f3f3f3"><div align="center">国籍</div></td>
                    <td height="20" bgcolor="#f3f3f3"><div align="left">
                      <input id="nation" type="text" value="<s:property value="#expert.nation"/>" name="expert.nation" />                    
                    </div></td>
                  </tr>
                  <tr>
                    <td height="20" align="center" bgcolor="#f3f3f3"><div align="center">性别</div></td>
                    <td height="20" bgcolor="#f3f3f3"><div align="left">
                      <input id="sex" type="text" value="<s:property value="#expert.sex"/>" name="expert.sex" />                    
                    </div></td>
                  </tr>
                  <tr>
                    <td height="20" align="center" bgcolor="#f3f3f3"><div align="center">电话 </div></td>
                    <td height="20" bgcolor="#f3f3f3"><div align="left">
                      <input id="tel" type="text" value="<s:property value="#expert.tel"/>" name="expert.tel" />                    
                    </div></td>
                  </tr>
                  <tr>
                    <td height="20" align="center" bgcolor="#f3f3f3"><div align="center">简介 </div></td>
                    <td height="20" bgcolor="#f3f3f3"><div align="left">
                      <input id="introduction" type="text" name="expert.introduction" />                    
                    </div></td>
                  </tr>
                  <tr>
                    <td height="30" align="center" bgcolor="#f3f3f3">&nbsp;</td>
                    <td height="30" align="center" bgcolor="#f3f3f3"><div align="left">
                      <input id="submit2" type="submit" value="修改" name="submit6" />
                      <input id="button22" type="reset" value="取消" name="button22" />
                    </div></td>
                  </tr>
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
