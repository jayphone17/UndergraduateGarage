<%@ page language="java" import="java.util.*" pageEncoding="gb2312"%>
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
</head>

<body>
<div id="container" >

<div id="header";>
</div>

<div id="navigation">
<ul>
<li class="selected"></li>
<li><a href="../index.html">��ҳ</a></li>
<li><a href="../jieshao.html">ϵͳ����</a></li>
<li><a href="../zhinan.html">��ָ��</a></li>
<li><a href="../login.html">��Ŀ�걨</a></li>
<li><a href="../lianxi.html">��ϵ����</a></li>
<li></li>
</ul>
</div>

</div>
<div id="container" ><div id="content2"><table width="100%" height="41"  border="0" align="center" cellpadding="0" cellspacing="0"><tr><td width="15" height="18" align="left" valign="top"><div align="left"></div></td>
      <td width="385" align="left" valign="bottom" class="12">&nbsp;</td>
    </tr><tr><td height="4" colspan="2" align="left" valign="bottom"></td>
    </tr><tr><td height="15" align="left" valign="top">&nbsp;</td>
      <td height="15" align="left" valign="top" class="12"><table width="100%" height="20" border="0" cellpadding="0" cellspacing="0"><tr><td height="20" align="center"><div class="right_proaducts">
        <div align="left">�ҵ�λ��&gt;&gt;�Ƽ���Ŀ�걨&gt;��Ŀ��ѯ</div>
      </div>
      <form action="../unit/highquery1.html" method="post" id="form"><DIV class=padding><DIV id=middlebody>
	   <table cellspacing="0" cellpadding="0" width="100%" border="0">
	  <tbody>
	  <tr><td><div align="left">|&nbsp;&nbsp;��ӭ,��λ�û�&nbsp;&nbsp;|&nbsp;&nbsp;
	  <a class="table_t"  href="../index.html">ע��</a>&nbsp;&nbsp;|&nbsp;&nbsp;
	  <a href="javascript:history.go(-1)">����</a>&nbsp;&nbsp;|</div></td>
         <td><div align="center"><a href="../unit/viewunitinfo.html">��λ��Ϣ</a></div></td>
         <td><div align="center"><a href="../unit/reworkpassword.html">�޸�����</a></div></td>
         <td><div align="center"><a href="../unit/showprojectCategorys.html">��Ŀ�걨����</a></div></td>
         <td height="50"><div align="center"><a href="../unit/simpleSearch.html">��Ϣ��ѯ</a></div></td>
       </tr>
	   </tbody>
	   </table>
               
		      <div align="center">
		         <table width="60%" border="0" cellpadding="0" cellspacing="1" bgcolor="#f3f3f3">
		           <tbody>
		         <tr>
		          <td align="center" width="20%" valign="middle">��Ŀ����:</td>
		          <td  align="left" width="80%"><input type="text" name="sercontext" size="30" ></td>
		          </tr>
		         <tr><td align="center">��ʼ����</td>
		         <td align="left"><input  type="text" name="startDate" id="temp2" onFocus="setday(this)" /></td></tr>
		          <tr><td align="center">��������</td>
		          <td align="left"><input  type="text" name="endDate" id="temp3"  onFocus="setday(this)" /></td>
		         <tr><td align="center">�����ʽ�</td>
		          <td align="left"><input type="text" name="money" size="30"></td></tr>
		         <tr><td colspan="2" align="center"><input type="submit" value="�߼���ѯ" style="font-size:8pt"></td></tr>
		         </tbody>
		         </table> 
	          </div>
                <table width="100%" border="0" cellpadding="0" cellspacing="1">
                  <tbody>
                    <tr>
                      <td align="center" bgcolor="#fba661">����Ŀ</td>
                      <td align="center" bgcolor="#fba661">����Ŀ</td>
                      <td width="208" align="center" bgcolor="#fba661">����</td>
                    </tr>
                    <tr>
                      <td width="150" align="center" bgcolor="#f3f3f3">�Ƽ��з�</td>
                      <td width="342" align="center" bgcolor="#f3f3f3"><a href="../unit/viewprojectinfo1.html">�����з�</a></td>
                      <td align="center" bgcolor="#f3f3f3"><a href="../unit/viewprojectinfo.html">û������</a></td>
                    </tr>
                    <tr>
                      <td width="150" align="center" bgcolor="#f3f3f3">���̽���</td>
                      <td width="342" align="center" bgcolor="#f3f3f3"><a href="../unit/viewprojectinfo1.html">�������̽���</a></td>
                      <td align="center" bgcolor="#f3f3f3"><a href="../unit/viewprojectinfo.html">û������</a></td>
                    </tr>
                    <tr>
                      <td width="150" align="center" bgcolor="#f3f3f3">���ڹ���</td>
                      <td width="342" align="center" bgcolor="#f3f3f3"><a href="../unit/viewprojectinfo1.html">����Ͷ����Ŀ</a></td>
                      <td align="center" bgcolor="#f3f3f3"><a href="../unit/viewprojectinfo.html">û������</a></td>
                    </tr>
                    <tr>
                      <td width="150" align="center" bgcolor="#f3f3f3">���ս���</td>
                      <td width="342" align="center" bgcolor="#f3f3f3"><a href="../unit/viewprojectinfo1.html">���չ�˾������Ŀ</a></td>
                      <td align="center" bgcolor="#f3f3f3">ר�������󣬲����޸�</td>
                    </tr>
                    <tr>
                      <td width="150" align="center" bgcolor="#f3f3f3">���˹���</td>
                      <td width="342" align="center" bgcolor="#f3f3f3"><a href="../unit/viewprojectinfo1.html">���˹���ϵͳ</a></td>
                      <td align="center" bgcolor="#f3f3f3">ר�������󣬲����޸�</td>
                    </tr>
                  </tbody>
                </table>
                <div></div>
              </td>
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