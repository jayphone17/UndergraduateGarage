<%@ page language="java" import="java.util.*" pageEncoding="gb2312"%>
<%@ taglib uri="/struts-tags" prefix="s" %>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">

  <html>
<head>

 <base href="<%=basePath%>">
 
<title>�Ƽ���Ŀ�걨ϵͳ</title>
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
<li><a href="./index.jsp">��ҳ</a></li>
<li><a href="./jieshao.jsp">ϵͳ����</a></li>
<li><a href="./zhinan.jsp">��ָ��</a></li>
<li><a href="./login.jsp">��Ŀ�걨</a></li>
<li><a href="./lianxi.jsp">��ϵ����</a></li>
<li></li>
</ul>
</div>

</div>
<div id="container" ><div id="content2"><table width="100%" height="41"  border="0" align="center" cellpadding="0" cellspacing="0"><tr><td width="15" height="18" align="left" valign="top"><div align="left"></div></td>
      <td width="385" align="left" valign="bottom" class="12">&nbsp;</td>
    </tr><tr><td height="4" colspan="2" align="left" valign="bottom"></td>
    </tr><tr><td height="15" align="left" valign="top">&nbsp;</td>
      <td height="15" align="left" valign="top" class="12"><table width="100%" height="20" border="0" cellpadding="0" cellspacing="0">
	  <tr><td height="20"><div class="right_proaducts">�ҵ�λ��&gt;&gt;�Ƽ���Ŀ�걨&gt;������Ŀ�����б�<br />
        <br /></div>
              <form action="" method="post" id="form"><DIV class=padding><DIV id=middlebody>
			  <table cellspacing="0" cellpadding="0" width="100%" border="0"><tbody>
			 <tr><td><div align="left">|&nbsp;&nbsp;��ӭ,ר���û�<s:property value="#session.expert.expert.name"/>&nbsp;&nbsp;|&nbsp;&nbsp;<a 
      class="table_t"  href="./index.jsp">ע��</a>&nbsp;&nbsp;|&nbsp;&nbsp;
	  <a href="javascript:history.go(-1)">����</a>&nbsp;&nbsp;|</div></td>
                      <td><div align="center"><a  href="./expert/viewexpertinfo.html">ר����Ϣ</a></div></td>
                      <td><div align="center"><a  href="./expert/reworkpassword.html">�޸�����</a></div></td>
                      <td height="50"><div align="center"><a  href="./expert/showprojectCategorys.html">��Ŀ����</a></div></td>
                      </tr></tbody></table>
                <table width="100%" border="0" cellpadding="0" cellspacing="1">
                  <tbody>
                    <tr>
                      <td width="10%" align="center" valign="middle" bgcolor="#fba661">���ID</td>
                      <td width="40%" align="center" valign="middle" bgcolor="#fba661">��������</td>
                      <td width="20%" align="center" valign="middle" bgcolor="#fba661">�걨��ʼʱ��</td>
                      <td width="20%" align="center" valign="middle" bgcolor="#fba661">�걨����ʱ��</td>
                      <td width="10%" align="center" valign="middle" bgcolor="#fba661">��Ŀ</td>
                    </tr>
                    <s:iterator id="s" value="categorys" status="sta">
                    <tr>
                      <td align="center" valign="middle" bgcolor="#f3f3f3">categorys.categoryid</td>
                      <td align="center" valign="middle" bgcolor="#f3f3f3">categorys.categoryname</td>
                      <td align="center" valign="middle" bgcolor="#f3f3f3">categorys.repStartTime</td>
                      <td align="center" valign="middle" bgcolor="#f3f3f3">categorys.repStopTime</td>
                      <td align="center" valign="middle" bgcolor="#f3f3f3"><a href="./expert/FindProjectInfo.action?id=categoryid">��Ŀ</a></td>
                    </tr>
                    </s:iterator>
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
<p><a href="http://www.ascenttech.com.cn/" target="_blank">��Ȩ���У�������˼������Ƽ����޹�˾ &copy;2004-2008|��ICP��05005681</a></p>
</div>

</div>
</body>
</html>