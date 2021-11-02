<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head><%@ taglib uri ="http://java.sun.com/jsp/jstl/core" prefix="c"%>
	<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312" />
<title>项目管理系统 by www.eyingda.com</title>
<link rel="stylesheet" rev="stylesheet" href="../css/style.css" type="text/css" media="all" />


<script  type="text/javascript">
window.onload=function () {
		document.getElementById("ProjectSelect").onchange = function () {
			var xhr = new XMLHttpRequest();//创建一个用于发送异步请求的对象
			xhr.open("post", "selectNeed?Pjtid=" + this.value, true);//-----.
			xhr.send();
			xhr.onreadystatechange = function () {
				//等待响应信息
				if (xhr.readyState == 4 && xhr.status == 200) {
					var jsonObjectString = xhr.responseText;//得到相应的结果
					var newSelectEle = document.createElement("select");//设置添加的配件的类型
					newSelectEle.onchange = function () {
						//自己写一个流程///在这里调用将value赋值
					}
					newSelectEle.setAttribute("id", "NeedSelect");//设置select元素
					newSelectEle.setAttribute("name", "Nid");
					var newOption = document.createElement("option");//添加一个新的option配置
					newOption.innerHTML = "==请选择需求==";
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
					moduleSpan.removeChild(document.getElementById("NeedSelect"));//移除select
					moduleSpan.appendChild(newSelectEle);//添加新的
				}
			}
		}

				// function tishi() {
				// 	var a = confirm('数据库中保存有该人员基本信息，您可以修改或保留该信息。');
				// 	if (a != true) return false;
				// 	window.open("冲突页.htm", "", "depended=0,alwaysRaised=1,width=800,height=400,location=0,menubar=0,resizable=0,scrollbars=0,status=0,toolbar=0");
				// }
				//
				// function check() {
				// 	document.getElementById("aa").style.display = "";
				// }



				var buttionEles = document.getElementsByClassName("savebutton");
					for (var i = 0; i < buttionEles.length; i++) {
						buttionEles[i].onclick = function () {
							var formEle = document.getElementById("form");
							formEle.submit();
							alert("保存成功")
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
  <form action="UpdateModule?ControlerDirection=update&Moid=${requestScope.Module.getMoid()}"      method="post" name="form" id="form" target="_self" >
<div class="MainDiv">
<table width="99%" border="0" cellpadding="0" cellspacing="0" class="CContent">
  <tr>
      <th class="tablestyle_title" >项目模块修改页面</th>
  </tr>
  <tr>
    <td class="CPanel">
		
		<table border="0" cellpadding="0" cellspacing="0" style="width:100%">
		<tr><td align="left">
		<input type="button" name="Submit"  value="保存" class="savebutton"/>　
			
			<input type="button" name="Submit2" value="返回" class="button" onclick="window.history.go(-1);"/>
		</td></tr>

		
		
		<tr align="center">
          <td class="TablePanel">${requestScope.Module.getProjectName()}项目</td>
		  </tr>
		<TR>
			<TD width="100%">
				<fieldset style="height:100%;">
				<legend>项目模块信息</legend>
					  <table border="0" cellpadding="2" cellspacing="1" style="width:100%">
					 
					  <tr>
					    <td nowrap align="right" width="13%">模块名字:</td>
					    <td width="46%"><input name="Moname" value="${requestScope.Module.getMoname()}" class="text" style="width:300px" type="text" size="40" />
				        <span class="red"> *</span></td>
					    <td nowrap="nowrap" align="right">模块标识:</td>
					    <td><input name="Monick" id="" value="${requestScope.Module.getMonick()}" class="text" style="width:154px" /></td>
					  </tr>


					  <tr>
					    <td align="right">所属项目:</td>
					    <td><select id="ProjectSelect" name="Projectid">
							<option name="${requestScope.Module.getProjectId()}">${requestScope.Module.getProjectName()}</option>
							<c:forEach var="Project" items="${requestScope.ProjectList}">
								<option value="${Project.getPjtid()}">${Project.getPjtname()}</option>
							</c:forEach>
                          </select>                        </td>


					    <td nowrap="nowrap" align="right">所属需求:</td>
					    <td><span id="NeedSelectSpan">
								 <select name="Nid" id="NeedSelect" >
                            <option  selected="selected" >=请选择需求=</option>
                                 </select>
							</span>                      </td>
					  </tr>
					   <tr>
						   <td align="right">优先级:</td>
						   <td><select name="Mpriority" >
							   <option  selected="selected">${requestScope.Module.getMopriority()}</option>
							   <option value="1">暂不</option>
							   <option value="2">一般</option>
							   <option value="3">需要</option>
							   <option value="4">急</option>
							   <option value="5">很急</option>
						   </select></td>                     </td>
					    <td align="right">&nbsp;</td>
					    <td>&nbsp;</td>
					  </tr>
					  <tr align="top">
					    <td nowrap align="right" height="120px">模块描述:</td>
					    <td colspan="3">
							<textarea  name="Mocontent" rows="10" cols="80">${requestScope.Module.getMocontent()}</textarea>						</td>
					    </tr>
						<tr align="top">
					    <td nowrap align="right" height="120px">需求描述:</td>
					    <td colspan="3">
							<textarea  name="Moneed" rows="10" cols="80">${requestScope.Module.getMoneed()}</textarea>						</td>
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
			<input type="button" name="Submit" value="保存" class="savebutton"/>　
			
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
