<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<%@ taglib uri ="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312" />
<title>项目管理系统 by www.eyingda.com</title>
<link rel="stylesheet" rev="stylesheet" href="../css/style.css" type="text/css" media="all" />


<script type="text/javascript">

	window.onload=function(){
		var buttionEles=document.getElementsByClassName("savebutton");
		for(var i=0;i<buttionEles.length;i++){
			buttionEles[i].onclick=function () {
				var formEle = document.getElementById("FunctionNeedform");
				formEle.submit();
				alert("保存成功")
			}
		}
	}

	// function tishi()
	// {
	// 	var a=confirm('数据库中保存有该人员基本信息，您可以修改或保留该信息。');
	// 	if(a!=true)return false;
	// 	window.open("冲突页.htm","","depended=0,alwaysRaised=1,width=800,height=400,location=0,menubar=0,resizable=0,scrollbars=0,status=0,toolbar=0");
	// }
	//
	// function check()
	// {
	// 	document.getElementById("aa").style.display="";
	// }

</script>
<style type="text/css">
<!--
.atten {font-size:12px;font-weight:normal;color:#F00;}
-->
</style>
</head>

<body class="ContentBody">
  <form action="UpdateNeed?action=editNeed&Nid=${requestScope.Function.getNeedNid()}" method="post"  name="FunctionNeedform" id="FunctionNeedform" target="_self" >
<div class="MainDiv">
<table width="99%" border="0" cellpadding="0" cellspacing="0" class="CContent">
  <tr>
      <th class="tablestyle_title" >变更需求</th>
  </tr>
  <tr>
    <td class="CPanel">
		
		<table border="0" cellpadding="0" cellspacing="0" style="width:100%">
		<tr><td align="left">
		<input type="button" name="Submit" value="保存" class="savebutton" />
			<input type="button" name="Submit2" value="返回" class="button" onclick="window.history.go(-1);"/>
		</td></tr>

		
		
		<tr align="center">
          <td class="TablePanel">${requestScope.Function.getFname()}功能</td>
		  </tr>
		<TR>
			<TD width="100%">
				<fieldset style="height:100%;">
				<legend>添加需求</legend>
					  <table border="0" cellpadding="2" cellspacing="1" style="width:100%">
					  <tr>
					    <td width="15%" align="right">需求描述:</td>
					    <td width="85%"><textarea name="NeedContent" cols="100" rows="20" value="${requestScope.Function.getNeedContect()}">${requestScope.Function.getNeedContect()}</textarea></td>
					    </tr>
					  </table>
			  <br />
				</fieldset>			</TD>
		</TR>
		</TABLE>
	
	
	 </td>
  </tr>
  

		
		

		<TR>
			<TD colspan="2" align="center" height="50px">
			<input type="button" name="Submit" value="保存" class="savebutton" />　
			
			<input type="button" name="Submit2" value="返回" class="button" onclick="window.history.go(-1);"/></TD>
		</TR>
		</TABLE>
	
	
	 </td>
  </tr>
  
  
  
  
  </table>

</div>
</form>
</body>
</html>
