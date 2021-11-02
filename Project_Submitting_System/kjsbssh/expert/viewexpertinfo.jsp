<%@ page language="java" import="java.util.*" pageEncoding="utf-8"%>
<%@ taglib uri="/struts-tags" prefix="s"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
  
  <base href="<%=basePath%>">
  
<title>科技项目申报系统</title>
<meta http-equiv="content-type" content="text/html; charset=utf-8" />
<meta name="description" content="Your website description goes here" />
<meta name="keywords" content="your,keywords,goes,here" />
<link rel="stylesheet" href="../css/andreas08(blue).css" type="text/css" media="screen,projection" />
<style type="text/css">
<!--
.STYLE1 {color: #FF0000}
-->
</style>
<script type="text/javascript" src="../js/acesys.js"></script>
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
      <td height="15" align="left" valign="top" class="12"><table width="100%" height="20" border="0" cellpadding="0" cellspacing="0"><tr><td height="20"><div class="right_proaducts">我的位置&gt;&gt;科技项目申报&gt;专家信息<br />
        <br /></div>
        
          <form action="./expert/UpdateExpertInfo.action?id=<s:property value="#session.expert.expert.expertid"/>" method="post" id="form" onsubmit="return checkEexinfromation(this)">
			 <DIV class=padding><DIV id=middlebody><table cellspacing="0" cellpadding="0" width="100%" border="0"><tbody>
			 <tr><td><div align="left">|&nbsp;&nbsp;欢迎,专家用户<s:property value="#session.expert.expert.name"/>&nbsp;&nbsp;|&nbsp;&nbsp;
      <a class="table_t"  href="./index.jsp">注销</a>&nbsp;&nbsp;|&nbsp;&nbsp;
	  <a href="javascript:history.go(-1)">后退</a>&nbsp;&nbsp;|</div></td>
                      <td><div align="center"><a 
      href="./expert/DisplayExpertInfo.action">专家信息</a></div></td>
                      <td><div align="center"><a 
      href="./expert/reworkpassword.html">修改密码</a></div></td>
                      <td height="50"><div align="center"><a 
      href="./expert/showprojectCategorys.html">项目管理</a></div></td>
                      </tr></tbody></table>
                
                <table width="50%" border="0" align="center" cellpadding="0" cellspacing="1">
                  <tbody><tr><td width="17%" height="20" align="right" bgcolor="#f3f3f3">名称</td>
                      <td width="3%" height="20" align="right" bgcolor="#f3f3f3">&nbsp;</td>
                      <td height="20" colspan="2" bgcolor="#f3f3f3"><input type="text" value="<s:property value="#expert.name"/>" name="expert.name" /></td>
                      
                    </tr><tr>
                      <td height="20" align="right" bgcolor="#f3f3f3">单位名称</td>
                      <td height="20" align="right" bgcolor="#f3f3f3">&nbsp;<input type="hidden" value="<s:property value="#session.expert.expert.expertid"/>" name="expert.expertid"/></td>
                      <td height="20" colspan="2" bgcolor="#f3f3f3"><input type="text" value="<s:property value="#expert.unitname"/>" name="expert.unitname" id="expert.unitname"  /></td>
                    </tr><tr>
                      <td height="20" align="right" bgcolor="#f3f3f3">国籍</td>
                      <td height="20" align="right" bgcolor="#f3f3f3">&nbsp;</td>
                      <td height="20" colspan="2" bgcolor="#f3f3f3"><input type="text" value="<s:property value="#expert.nation"/>" name="expert.nation" id="nation" /></td>
                    </tr>
                    <tr>
                      <td height="20" align="right" bgcolor="#f3f3f3">性别</td>
                      <td height="20" align="right" bgcolor="#f3f3f3">&nbsp;</td>
                      <td height="20" colspan="2" bgcolor="#f3f3f3"><select name="expert.sex">
                        <option value="男">男</option>
                        <option value="女">女</option>
                      </select>                      </td>
                    </tr>
                    <tr>
                      <td height="20" align="right" bgcolor="#f3f3f3">职称</td>
                      <td height="20" align="right" bgcolor="#f3f3f3">&nbsp;</td>
                      <td height="20" colspan="2" bgcolor="#f3f3f3"><input type="text" value="<s:property value="#expert.title"/>" name="expert.title" id="expert.title" /></td>
                    </tr><tr>
                      <td height="20" align="right" bgcolor="#f3f3f3">电话</td>
                      <td height="20" align="right" bgcolor="#f3f3f3">&nbsp;</td>
                      <td height="20" colspan="2" bgcolor="#f3f3f3"><input type="text" value="<s:property value="#expert.tel"/>" name="expert.tel" id="tel" /></td>
                    </tr><tr>
                      <td height="20" align="right" bgcolor="#f3f3f3">简介</td>
                      <td height="20" align="right" bgcolor="#f3f3f3">&nbsp;</td>
                      <td height="20" colspan="2" bgcolor="#f3f3f3"><input type="text" value="<s:property value="#expert.introduction"/>" name="expert.introduction" id="introduction" /></td>
                    </tr><tr><td height="30" colspan="2" bgcolor="#f3f3f3">&nbsp;</td>
                      <td width="22%" height="30" bgcolor="#f3f3f3"><input type="submit" name="Submit" value="修改" /></td>
                      <td width="58%" height="30" bgcolor="#f3f3f3"><input type="submit" name="Submit2" value="取消" /></td>
                  </tr>
                                  
                  </tbody></table>
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