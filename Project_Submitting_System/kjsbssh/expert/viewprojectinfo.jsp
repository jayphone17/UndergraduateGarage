<%@ page language="java" import="java.util.*" pageEncoding="gb2312"%>
<%@ taglib uri="/struts-tags" prefix="s"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
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
<script type="text/javascript" src="../js/acesys.js"></script>
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
<div id="container" ><div id="content2">
<table width="100%" height="41"  border="0" align="center" cellpadding="0" cellspacing="0">
<tr><td height="4" colspan="2" align="left" valign="bottom">&nbsp;</td>
    </tr><tr><td height="15" align="left" valign="top">&nbsp;</td>
      <td height="15" align="left" valign="top" class="12"><table width="100%" height="20" border="0" cellpadding="0" cellspacing="0"><tr><td height="20" align="center"><div class="right_proaducts">
        <div align="left">�ҵ�λ��&gt;&gt;�Ƽ���Ŀ�걨&gt;��Ŀ��ϸ��Ϣ</div>
      </div>
      <form action="showprojectCategorys.html" method="post" id="form" onsubmit="return checkAudit(this)">
	  <DIV class=padding><DIV id=middlebody><table cellspacing="0" cellpadding="0" width="100%" border="0"><tbody>
	  <tr><td><div align="left">|&nbsp;&nbsp;��ӭ,ר���û�<s:property value="#session.expert.expert.name"/>&nbsp;&nbsp;|&nbsp;&nbsp;<a 
      class="table_t" 
      href="./index.jsp">ע��</a>&nbsp;&nbsp;|&nbsp;&nbsp;
	  <a href="javascript:history.go(-1)">����</a>&nbsp;&nbsp;|</div></td>
                      <td><div align="center"><a 
      href="./expert/viewexpertinfo.html">ר����Ϣ</a></div></td>
                      <td><div align="center"><a 
      href="./expert/reworkpassword.html">�޸�����</a></div></td>
                      <td height="50"><div align="center"><a 
      href="./expert/showprojectCategorys.html">��Ŀ����</a></div></td>
                      </tr></tbody></table>
                <table width="50%" border="0" cellpadding="0" cellspacing="1">
                  <input type="hidden" value="6" name="projectId" />
                  <input type="hidden" value="4" name="categoryid" />
                  <tbody>
                    <tr>
                      <td width="21%" bgcolor="#f3f3f3"><div align="right">��Ŀ����</div></td>
                      <td width="2%" bgcolor="#f3f3f3">&nbsp;</td>
                      <td width="77%" bgcolor="#f3f3f3"><div align="left">�Ƽ��з�</div></td>
                    </tr>
                    <tr>
                      <td bgcolor="#f3f3f3"><div align="right">���뵥λ</div></td>
                      <td bgcolor="#f3f3f3">&nbsp;</td>
                      <td bgcolor="#f3f3f3"><div align="left">��˼�ɿƼ����޹�˾</div></td>
                    </tr>
                    <tr>
                      <td bgcolor="#f3f3f3"><div align="right">������</div></td>
                      <td bgcolor="#f3f3f3">&nbsp;</td>
                      <td bgcolor="#f3f3f3"><div align="left">henry</div></td>
                    </tr>
                    <tr>
                      <td bgcolor="#f3f3f3"><div align="right">ְ��</div></td>
                      <td bgcolor="#f3f3f3">&nbsp;</td>
                      <td bgcolor="#f3f3f3"><div align="left">��Ŀ����</div></td>
                    </tr>
                    <tr>
                      <td bgcolor="#f3f3f3"><div align="right">ѧ��</div></td>
                      <td bgcolor="#f3f3f3">&nbsp;</td>
                      <td bgcolor="#f3f3f3"><div align="left">�о���</div></td>
                    </tr>
                    <tr>
                      <td bgcolor="#f3f3f3"><div align="right">�ʱ��</div></td>
                      <td bgcolor="#f3f3f3">&nbsp;</td>
                      <td bgcolor="#f3f3f3"><div align="left">2008-12-26</div></td>
                    </tr>
                    <tr>
                      <td bgcolor="#f3f3f3"><div align="right">��Ŀ��״</div></td>
                      <td bgcolor="#f3f3f3">&nbsp;</td>
                      <td bgcolor="#f3f3f3"><div align="left">һ�ڳﱸ</div></td>
                    </tr>
                    <tr>
                      <td bgcolor="#f3f3f3"><div align="right">��Ŀǰ��</div></td>
                      <td bgcolor="#f3f3f3">&nbsp;</td>
                      <td bgcolor="#f3f3f3"><div align="left">����</div></td>
                    </tr>
                    <tr>
                      <td bgcolor="#f3f3f3"><div align="right">���ѵ����</div></td>
                      <td bgcolor="#f3f3f3">&nbsp;</td>
                      <td bgcolor="#f3f3f3"><div align="left">�Ŷ��з�����</div></td>
                    </tr>
                    <tr>
                      <td bgcolor="#f3f3f3"><div align="right">�о�����</div></td>
                      <td bgcolor="#f3f3f3">&nbsp;</td>
                      <td bgcolor="#f3f3f3"><div align="left">��ѧ�о�</div></td>
                    </tr>
                    <tr>
                      <td bgcolor="#f3f3f3"><div align="right">Ԥ���о��ɹ�</div></td>
                      <td bgcolor="#f3f3f3">&nbsp;</td>
                      <td bgcolor="#f3f3f3"><div align="left">Ԥ����Ч</div></td>
                    </tr>
                    <tr>
                      <td bgcolor="#f3f3f3"><div align="right">�����ʽ�</div></td>
                      <td bgcolor="#f3f3f3">&nbsp;</td>
                      <td bgcolor="#f3f3f3"><div align="left">100��</div></td>
                    </tr>
                    <tr>
                      <td bgcolor="#f3f3f3"><div align="right">ר���������</div></td>
                      <td bgcolor="#f3f3f3">&nbsp;</td>
                      <td bgcolor="#f3f3f3"><div align="left">
                        <textarea id="opinion" name="expertOpinion"></textarea>
                      </div></td>
                    </tr>
                    <tr>
                      <td bgcolor="#f3f3f3"><div align="right">ר������</div></td>
                      <td bgcolor="#f3f3f3">&nbsp;</td>
                      <td bgcolor="#f3f3f3"><div align="left">
                        <input id="score" name="score" />                      
                      </div></td>
                    </tr>
                    <tr>
                      <td colspan="2" align="middle" bgcolor="#f3f3f3">&nbsp;</td>
                      <td height="30" align="middle" bgcolor="#f3f3f3"><div align="left">
                        <input name="submit" type="submit" value="�ύ" />
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
<p><a href="http://www.ascenttech.com.cn/" target="_blank">��Ȩ���У�������˼������Ƽ����޹�˾ &copy;2004-2008|��ICP��05005681</a></p>
</div>

</div>
</body>
</html>