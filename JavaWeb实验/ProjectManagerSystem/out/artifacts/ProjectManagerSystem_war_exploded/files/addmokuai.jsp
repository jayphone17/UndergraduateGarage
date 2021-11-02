<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<%@ taglib uri ="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ page import="domain.Module"%>
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312" />
<title>项目管理系统 by www.eyingda.com</title>
<link rel="stylesheet" rev="stylesheet" href="../css/style.css" type="text/css" media="all" />


<script language="JavaScript" type="text/javascript">
function tishi()
{
  var a=confirm('数据库中保存有该人员基本信息，您可以修改或保留该信息。');
  if(a!=true)return false;
  window.open("冲突页.htm","","depended=0,alwaysRaised=1,width=800,height=400,location=0,menubar=0,resizable=0,scrollbars=0,status=0,toolbar=0");
}

function check()
{
document.getElementById("aa").style.display="";
}



	window.onload = function () {
		var Eles = document.getElementsByClassName("saveFunction");
		for (var i = 0; i < Eles.length; i++) {
			Eles[i].onclick = function () {
				var formEle = document.getElementById("form");
				formEle.submit();
				alert("保存成功")
			}
		}
		document.getElementById("ProjectSelect").onchange = function () {
			var xhr = new XMLHttpRequest();//创建一个用于发送异步请求的对象
			xhr.open("post", "selectNeed?Pjtid=" + this.value, true);//-----.
			xhr.send();
			//等待响应信息
			xhr.onreadystatechange = function () {
				if (xhr.readyState == 4 && xhr.status == 200) {

					var jsonObjectString = xhr.responseText;//得到相应的结果
					var newSelectEle = document.createElement("select");//设置添加的配件的类型
					newSelectEle.onchange = function () {
						//自己写一个流程///在这里调用将value赋值
					}
					newSelectEle.setAttribute("id", "NeedSelect");//设置select元素
					newSelectEle.setAttribute("name", "Nid");
					var newOption = document.createElement("option");//添加一个新的option配置
					newOption.innerHTML = "==请选择==";
					newSelectEle.appendChild(newOption);//
					var jsonObject = window.eval("(" + jsonObjectString + ")");//给结果拼串
					var NeedList = jsonObject.NeedList;//得到数组

					//数组遍历e
					for (var i = 0; i < NeedList.length; i++) {
						var Need = NeedList[i];
						var newOptionEle = document.createElement("option");
						newOptionEle.setAttribute("value", Need.nid);//加一个value元素
						newOptionEle.innerHTML = Need.nname;//加他的名字展示
						newSelectEle.appendChild(newOptionEle);//把这个option加到select里
					}
					var moduleSpan = document.getElementById("NeedSelectSpan");//得到body里的span元素
					moduleSpan.removeChild(document.getElementById("NeedNid"));//移除
					moduleSpan.appendChild(newSelectEle);//添加新的
				}
			}
		}

	}





</script>
<style type="text/css">
<!--
.atten {font-size:12px;font-weight:normal;color:#F00;}
-->
</style>
</head>

<body class="ContentBody">
  <form action="UpdateModule?ControlerDirection=insert"  method="post"   id="form" target="sypost" >
<div class="MainDiv">
<table width="99%" border="0" cellpadding="0" cellspacing="0" class="CContent">
  <tr>
      <th class="tablestyle_title" >项目模块添加页面</th>
  </tr>
  <tr>
    <td class="CPanel">
		
		<table border="0" cellpadding="0" cellspacing="0" style="width:100%">
		<tr><td align="left">
		<input type="button" name="Submit" value="保存" class="saveFunction" />　
			
			<input type="button" name="Submit2" value="返回" class="button" onclick="window.history.go(-1);"/>
		</td></tr>

		
		
		<tr align="center">
          <td class="TablePanel">
			  <select id="ProjectSelect1" name="Pjtid" >
				  <option selected="selected">=请选择项目=</option>
				  <c:forEach var="Project" items="${requestScope.ProjectList}">
					  <option value="${Project.getPjtid()}">${Project.getPjtname()}</option>
				  </c:forEach>
			  </select>
          </td>
		  </tr>
		  <tr align="center"><td><a href="#">+添加模块+</a>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
			<a href="#">-删除模块-</a></td></tr>
		<TR>
			<TD width="100%">
				<fieldset style="height:100%;">
				<legend>模块一</legend>
					  <table border="0" cellpadding="2" cellspacing="1" style="width:100%">
					 
					  <tr>
					    <td nowrap align="right" width="13%">模块名字:</td>
					    <td width="46%"><input name="Moname" class="text" style="width:300px" type="text" size="40" value =""/>
				        <span class="red"> *</span></td>
					    <td align="right" width="9%"></td>
					    <td width="32%">&nbsp;</td>
					    </tr>
					  <tr>
					    <td nowrap align="right">模块标识:</td>
					    <td><input name="Monick" id="a" class="text" style="width:154px"  value ="" /></td>
					    <td align="right">所属项目:</td>
					    <td>
							<select id="ProjectSelect" name="Pjtid" >
								<option selected="selected">=请选择项目=</option>
								<c:forEach var="Project" items="${requestScope.ProjectList}">
									<option value="${Project.getPjtid()}">${Project.getPjtname()}</option>
								</c:forEach>
							</select>
                        </td>
					  </tr>
					   <tr>
					    <td nowrap align="right">所属需求:</td>

						<span id="NeedSelectSpan">
								 <select name="Nid" id="NeedNid" >
                            <option  selected="selected" >=请选择需求=</option>
                                 </select>
							</span>
					    <td align="right">优先级:</td>
						   <td><select name="Mopriority" >
							   <option  selected="selected">==请选择==</option>
							   <option value="1">暂不</option>
							   <option value="2">一般</option>
							   <option value="3">需要</option>
							   <option value="4">急</option>
							   <option value="5">很急</option>
						   </select></td>
					  </tr>
					  <tr>
					    <td nowrap align="right" height="120px">模块描述:</td>
					    <td colspan="3"><textarea id="M" name="Mocontent"  value ="" rows="5" cols="80"></textarea></td>
					    </tr>
						<tr>
					    <td nowrap align="right" height="120px">需求描述:</td>
					    <td colspan="3">
							<textarea id="x" name="Moneed"  value =""  rows="5" cols="80"></textarea>						</td>
					    </tr>
					  </table>
			 <br />
				</fieldset>			
			</TD>
		</TR>

		</TABLE>
	
	
	 </td>
  </tr>
  

		
		
		
		
		<TR>
			<TD colspan="2" align="center" height="50px">
			<input type="button" name="Submit" value="保存" class="saveFunction" />　
			
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
