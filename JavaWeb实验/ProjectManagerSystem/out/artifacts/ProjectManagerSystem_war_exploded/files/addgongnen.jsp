<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<%@ taglib uri ="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>

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
	<script type="text/javascript">
		window.onload=function(){
			var Eles =document.getElementsByClassName("saveFunction");
			for(var i=0;i<Eles.length;i++){
				Eles[i].onclick=function(){
					var formEle = document.getElementById("form");
					formEle.submit();
					alert("保存成功")
				}
			}

			document.getElementById("ProjectSelect").onchange=function(){
				var xhr =new XMLHttpRequest();//创建一个用于发送异步请求的对象
				xhr.open("post","selectProject?Pjtid="+this.value,true);//-----.
				xhr.send();
				//等待响应信息
				xhr.onreadystatechange = function(){
					if(xhr.readyState==4 && xhr.status==200){
						var jsonObjectString =xhr.responseText;//得到相应的结果
						var newSelectEle = document.createElement("select");//设置添加的配件的类型
						newSelectEle.onchange=function(){
							//自己写一个流程///在这里调用将value赋值
						}
						newSelectEle.setAttribute("id","ModuleSelect");//设置select元素
                        newSelectEle.setAttribute("name","Moid");
						var newOption =document.createElement("option");//添加一个新的option配置
						newOption.innerHTML="==请选择==";
						newSelectEle.appendChild(newOption);//
						var jsonObject =window.eval("("+jsonObjectString+")");//给结果拼串
						var ModuleList = jsonObject.ModuleList;//得到数组
						alert(ModuleList);
						//数组遍历e
						for(var i=0;i<ModuleList.length;i++){
							var Module =ModuleList[i];
							var newOptionEle =document.createElement("option");
							alert(Module.moid);
							newOptionEle.setAttribute("value",Module.moid);//加一个value元素
							newOptionEle.innerHTML=Module.moname;//加他的名字展示
							newSelectEle.appendChild(newOptionEle);//把这个option加到select里
						}
						var moduleSpan = document.getElementById("ModuleSelectSpan");//得到body里的span元素
						moduleSpan.removeChild(document.getElementById("ModuleMoid"));//移除
						moduleSpan.appendChild(newSelectEle);//添加新的
					}
				}
            }

        }


	</script>
</head>

<body class="ContentBody">
  <form action="UpdateFunction?ControlerDirection=insert" method="post" id="form" name="form" target="sypost" >
<div class="MainDiv">
<table width="99%" border="0" cellpadding="0" cellspacing="0" class="CContent">
  <tr>
      <th class="tablestyle_title" >项目功能添加页面</th>
  </tr>
  
  <tr>
    <td class="CPanel">
		
		<table border="0" cellpadding="0" cellspacing="0" style="width:100%">
		<tr><td align="left">
		<input type="button"  name="Submit" value="保存" class="saveFunction" />　
			
			<input type="button" name="Submit2" value="返回" class="button" onclick="window.history.go(-1);"/>
		</td>
		</tr>
		<tr align="center">
			<td class="TablePanel" height="30" style="font-size:16px"><span class="TablePanel" style="font-size:16px">
		  <select id="ProjectSelect" name="Pjtid" >
            <option selected="selected">=请选择项目=</option>
			 <c:forEach var="Project" items="${requestScope.ProjectList}">
				 <option value="${Project.getPjtid()}">${Project.getPjtname()}</option>
			 </c:forEach>
          </select>
			</td>
		</tr>


		<tr align="center"><td><a href="#">+添加功能+</a>&nbsp;&nbsp;&nbsp;
			&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<a href="#">-删除功能-</a></td></tr>
			
		<TR id="zdjh">
			<TD width="100%">
				<fieldset style="height:100%;">
				<legend>功能一</legend>
					  <table border="0" cellpadding="2" cellspacing="1" style="width:100%">
					 
					  <tr>
					    <td nowrap align="right" width="15%">功能名称:</td>
					    <td width="35%"><input name='FunctionName' type="text" class="text" style="width:154px" value="请输入功能名称" />
				        <span class="red">*</span></td>
					    <td align="right">需求版本号</td>
					    <td><input class="text" name='Functionversion' style="width:154px" value="请输入需求版本号"/></td>
					  </tr>
					  <tr>
					    <td align="right">优先级:</td>
					    <td><select name="Functionpriority" >
                            <option  selected="selected">==请选择==</option>
                            <option value="1">暂不</option>
                            <option value="2">一般</option>
                            <option value="3">需要</option>
                            <option value="4">急</option>
                            <option value="5">很急</option>
                        </select></td>
					    <td width="15%"align="right">所属模块:</td>
					    <td width="35%"><span class="TablePanel" style="font-size:16px">
							<span id="ModuleSelectSpan">
								 <select name="ModuleMoid" id="ModuleMoid" >
                            <option  selected="selected" >=请选择模块=</option>
                                 </select>
							</span>
						</td>
					  </tr>
					  <tr>
					    <td align="right">功能描述:</td>
					    <td colspan="3"><textarea name="FunctionContent" cols="80" rows="6" value ="请输入功能描述"></textarea></td>
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
			<input type="button" name="Submit" value="保存" class="saveFunction"/>　
			
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
