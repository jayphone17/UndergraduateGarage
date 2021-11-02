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
<li><a href="../index.jsp">首页</a></li>
<li><a href="../jieshao.jsp">系统介绍</a></li>
<li><a href="../zhinan.jsp">审报指南</a></li>
<li><a href="../login.jsp">项目申报</a></li>
<li><a href="../lianxi.jsp">联系我们</a></li>
<li></li>
</ul>
</div>

</div>
<div id="container" >
  <div id="content2">
    <table width="100%" height="41"  border="0" align="center" cellpadding="0" cellspacing="0">
    <tr>
      <td height="15" align="left" valign="top">&nbsp;</td>
      <td height="15" align="left" valign="top" class="12"><table width="100%" height="20" border="0" cellpadding="0" cellspacing="0">
        <tr>
          <td height="20" align="center"><div class="right_proaducts">
            <div align="left">我的位置&gt;&gt;科技项目申报&gt;单位信息 </div>
          </div>
              <form action="../unit/UpdateUnit.action?id=<s:property value="#unit.unitid"/>" method="post" id="form">
                <DIV class=padding>
                <DIV id=middlebody>
                <table cellspacing="0" cellpadding="0" width="100%" border="0">
                  <tbody>
                    <tr>
	                <td><div align="left">|&nbsp;&nbsp;欢迎,admin&nbsp;&nbsp;|&nbsp;&nbsp;
	                   <a  class="table_t"  href="../index.html">注销</a>&nbsp;&nbsp;|&nbsp;&nbsp;
	                   <a href="javascript:history.go(-1)">后退</a>&nbsp;&nbsp;|</div></td>
                      <td><div align="center"><a 
      href="../admin/FindAllUser.action">登录用户管理</a></div></td>
                      <td><div align="center"><a 
      href="../admin/ShowAllExperts.action">专家信息管理</a></div></td>
                      <td height="50"><div align="center"><a 
      href="../admin/ShowAllUnits.action">单位信息管理</a></div></td>
                      <td><div align="center"><a 
      href="../admin/showprojectCategorys.html">项目管理</a></div></td>
                    </tr>
                  </tbody>
                </table>
                <table width="60%" border="0" cellpadding="0" cellspacing="1">
                  <tbody>
                    <tr> </tr>
                    <tr>
                      <td height="20" align="center" bgcolor="#f3f3f3">单位名称</td>
                      <td height="20" bgcolor="#f3f3f3"><div align="left">
                        <input id="unit.unitname" value="<s:property value="#unit.unitname"/>" name="unit.unitname" />
                      </div></td>
                    </tr>
                    <tr>
                      <td height="20" align="center" bgcolor="#f3f3f3">单位地址</td>
                      <td height="20" bgcolor="#f3f3f3"><div align="left">
                        <input id="unit.address" value="<s:property value="#unit.address"/>" name="unit.address" />
                      </div></td>
                    </tr>
                    <tr>
                      <td height="20" align="center" bgcolor="#f3f3f3">单位法人</td>
                      <td height="20" bgcolor="#f3f3f3"><div align="left">
                        <input id="unit.corporation" value="<s:property value="#unit.corporation"/>" name="unit.corporation" />
                      </div></td>
                    </tr>
                    <tr>
                      <td height="20" align="center" bgcolor="#f3f3f3">注册资金</td>
                      <td height="20" bgcolor="#f3f3f3"><div align="left">
                        <input id="unit.investment" value="<s:property value="#unit.investment"/>" name="unit.investment" />
                      </div></td>
                    </tr>
                    <tr>
                      <td height="20" align="center" bgcolor="#f3f3f3">单位性质</td>
                      <td height="20" bgcolor="#f3f3f3"><div align="left">
                        <input id="unit.type" value="<s:property value="#unit.type"/>" name="unit.type" />
                      </div></td>
                    </tr>
                    <tr>
                      <td height="20" align="center" bgcolor="#f3f3f3">单位电话</td>
                      <td height="20" bgcolor="#f3f3f3"><div align="left">
                        <input id="unit.tel" value="<s:property value="#unit.tel"/>" name="unit.tel" />
                      </div></td>
                    </tr>
                    <tr>
                      <td height="20" align="center" bgcolor="#f3f3f3">单位邮箱</td>
                      <td height="20" bgcolor="#f3f3f3"><div align="left">
                        <input id="unit.email" value="<s:property value="#unit.email"/>" name="unit.email" />
                      </div></td>
                    </tr>
                    <tr>
                      <td height="20" align="center" bgcolor="#f3f3f3">单位传真</td>
                      <td height="20" bgcolor="#f3f3f3"><div align="left">
                        <input id="unit.fax" value="<s:property value="#unit.fax"/>" name="unit.fax" />
                      </div></td>
                    </tr>
                    <tr>
                      <td height="20" align="center" bgcolor="#f3f3f3">单位邮编</td>
                      <td height="20" bgcolor="#f3f3f3"><div align="left">
                        <input id="unit.zipcode" value="<s:property value="#unit.zipcode"/>" name="unit.zipcode" />
                      </div></td>
                    </tr>
                    <tr>
                      <td align="center" bgcolor="#f3f3f3">单位简介</td>
                      <td bgcolor="#f3f3f3"><div align="left">
                        <textarea id="textarea" name="unit.introduction" rows="5" cols="40">北美外资企业</textarea>
                      </div></td>
                    </tr>
                    <tr>
                      <td height="30" colspan="2" align="center" bgcolor="#f3f3f3"><input id="submit3" type="submit" value="修改" name="submit7" />
                          <input id="button23" type="reset" value="取消" name="button23" />                      </td>
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