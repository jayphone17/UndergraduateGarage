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
      <td height="15" align="left" valign="top" class="12">
	  <table width="100%" height="20" border="0" cellpadding="0" cellspacing="0"><tr><td height="20" align="center"><div class="right_proaducts">
        <div align="left">�ҵ�λ��&gt;&gt;�Ƽ���Ŀ�걨&gt;��Ŀ��ϸ��Ϣ</div>
      </div>
      <form action="../unit/unit_index.html" method="post" id="form"><DIV class=padding><DIV id=middlebody>
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
                <table width="60%" border="0" cellpadding="0" cellspacing="1">
                  <tbody>
                    <tr>
                      <td width="22%" bgcolor="#f3f3f3"><div align="right">��Ŀ����</div></td>
                      <td width="2%" bgcolor="#f3f3f3">&nbsp;</td>
                      <td width="76%" bgcolor="#f3f3f3"><div align="left">
                          <input size="40" value="�Ƽ��з�" name="editProject.projectname" />
                      </div></td>
                    </tr>
                    <tr>
                      <td bgcolor="#f3f3f3"><div align="right">���뵥λ</div></td>
                      <td bgcolor="#f3f3f3">&nbsp;</td>
                      <td bgcolor="#f3f3f3"><div align="left">util <font color="#FF0000">�����޸ģ�������λ��Ϣ������</font></div></td>
                    </tr>
                    <tr>
                      <td bgcolor="#f3f3f3"><div align="right">������</div></td>
                      <td bgcolor="#f3f3f3">&nbsp;</td>
                      <td bgcolor="#f3f3f3"><div align="left">
                          <input size="40" value="henry" name="editProject.applicant" />
                      </div></td>
                    </tr>
                    <tr>
                      <td bgcolor="#f3f3f3"><div align="right">ְ��</div></td>
                      <td bgcolor="#f3f3f3">&nbsp;</td>
                      <td bgcolor="#f3f3f3"><div align="left">
                          <input size="40" value="��Ŀ����" name="editProject.grade" />
                      </div></td>
                    </tr>
                    <tr>
                      <td bgcolor="#f3f3f3"><div align="right">ѧ��</div></td>
                      <td bgcolor="#f3f3f3">&nbsp;</td>
                      <td bgcolor="#f3f3f3"><div align="left">
                          <input size="40" value="�о���" name="editProject.education" />
                      </div></td>
                    </tr>
                    <tr>
                      <td bgcolor="#f3f3f3"><div align="right">�ʱ��</div></td>
                      <td bgcolor="#f3f3f3">&nbsp;</td>
                      <td bgcolor="#f3f3f3"><div align="left">2008-12-26 <font color="#FF0000">���������޸ģ�����ϵ����Ա</font></div></td>
                    </tr>
                    <tr>
                      <td bgcolor="#f3f3f3"><div align="right">��Ŀ��״</div></td>
                      <td bgcolor="#f3f3f3">&nbsp;</td>
                      <td bgcolor="#f3f3f3"><div align="left">
                          <input size="40" value="�з���" name="editProject.status" />
                      </div></td>
                    </tr>
                    <tr>
                      <td bgcolor="#f3f3f3"><div align="right">��Ŀǰ��</div></td>
                      <td bgcolor="#f3f3f3">&nbsp;</td>
                      <td bgcolor="#f3f3f3"><div align="left">
                          <input size="40" value="����" name="editProject.future" />
                      </div></td>
                    </tr>
                    <tr>
                      <td bgcolor="#f3f3f3"><div align="right">���ѵ����</div></td>
                      <td bgcolor="#f3f3f3">&nbsp;</td>
                      <td bgcolor="#f3f3f3"><div align="left">
                          <input size="40" value="�з�����" name="editProject.analysis" />
                      </div></td>
                    </tr>
                    <tr>
                      <td bgcolor="#f3f3f3"><div align="right">�о�����</div></td>
                      <td bgcolor="#f3f3f3">&nbsp;</td>
                      <td bgcolor="#f3f3f3"><div align="left">
                          <input size="40" value="��ѧ���㷽��" name="editProject.way" />
                      </div></td>
                    </tr>
                    <tr>
                      <td bgcolor="#f3f3f3"><div align="right">Ԥ���о��ɹ�</div></td>
                      <td bgcolor="#f3f3f3">&nbsp;</td>
                      <td bgcolor="#f3f3f3"><div align="left">
                          <input size="40" value="������Ч" name="editProject.result" />
                      </div></td>
                    </tr>
                    <tr>
                      <td bgcolor="#f3f3f3"><div align="right">�����ʽ�</div></td>
                      <td bgcolor="#f3f3f3">&nbsp;</td>
                      <td bgcolor="#f3f3f3"><div align="left">
                          <input size="40" value="100��" name="editProject.capital" />
                      </div></td>
                    </tr>
                    <tr>
                      <td colspan="3" align="middle" bgcolor="#f3f3f3"><div align="center">
                          <input name="submit5" type="submit" value="�޸�" />
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