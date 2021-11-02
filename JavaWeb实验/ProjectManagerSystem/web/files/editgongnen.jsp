<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<%@ taglib uri ="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ page import="domain.Function"%>
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312" />
<title>项目管理系统 by www.eyingda.com</title>
<link rel="stylesheet" rev="stylesheet" href="../css/style.css" type="text/css" media="all" />


<style type="text/css">
<!--
.atten {font-size:12px;font-weight:normal;color:#F00;}
-->
</style>
</head>
<script type="text/javascript">
	window.onload=function(){
		var buttionEles=document.getElementsByClassName("savebutton");
		for(var i=0;i<buttionEles.length;i++){
			buttionEles[i].onclick=function () {
				var formEle = document.getElementById("form");
				formEle.submit();
				alert("保存成功")
			}
		}
	}
</script>
<body class="ContentBody">
  <form action="UpdateFunction?ControlerDirection=update&Fid=${requestScope.Function.getFid()}" method="post" name="form" id="form" target="_self" >
<div class="MainDiv">
<table width="99%" border="0" cellpadding="0" cellspacing="0" class="CContent">
  <tr>
      <th class="tablestyle_title" >项目功能修改页面</th>
  </tr>
  <tr>
    <td class="CPanel">
		
		<table border="0" cellpadding="0" cellspacing="0" style="width:100%">
		<tr><td align="left">
		<input type="button" name="Submit" value="保存" class="savebutton" />　
			
			<input type="button" name="Submit2" value="返回" class="button" onclick="window.history.go(-1);"/>
		</td></tr>
		<tr align="center">
          <td class="TablePanel">${requestScope.Function.getProjectName()}项目</td>
		  </tr>
		<TR>
			<TD width="100%">
				<fieldset style="height:100%;">
				<legend>项目功能信息</legend>
					  <table border="0" cellpadding="2" cellspacing="1" style="width:100%">
					 
					  <tr>
					    <td nowrap align="right" width="15%">功能名称:</td>
					    <td width="35%"><input name="Fname" type="text" class="text" style="width:154px" value="${requestScope.Function.getFname()}" />
				        <span class="red">*</span></td>
					    <td align="right">需求版本号</td>
					    <td><input class="text" name="Fversion" style="width:154px" value="${requestScope.Function.getFversion()}"/></td>
					  </tr>
					  <tr>
					    <td width="15%" align="right">所属项目:</td>
					    <td width="35%"><input class="text" name="ProjectName" style="width:154px" value="${requestScope.Function.getProjectName()}"/></td>
					    <td width="15%"align="right">所属模块:</td>
					    <td width="35%"><input class="text" name="ModuleName" style="width:154px" value="${requestScope.Function.getModuleName()}"/></td>
					  </tr>
					  <tr>
					    <td align="right">优先级:</td>
					    <td><select name="Fpriority" value="" >
                            <option  selected="selected">${requestScope.Function.getFpriority()}</option>
                            <option>暂不</option>
                            <option>一般</option>
                            <option>需要</option>
                            <option>急</option>
                            <option>很急</option>
                        </select></td>
					    
					    <td align="right">&nbsp;</td>
					    <td>&nbsp;</td>
					  </tr>
					  <tr>
					    <td align="right">功能明细:</td>
					    <td colspan="3"><textarea name="Fcontent" cols="100" rows="10">${requestScope.Function.getFcontent()}</textarea></td>
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
