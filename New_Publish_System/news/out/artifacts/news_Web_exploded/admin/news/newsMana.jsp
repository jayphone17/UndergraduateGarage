<%@ page language="java" pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>
<%@ taglib prefix="fmt" uri="http://java.sun.com/jsp/jstl/fmt"%>
<%@ page isELIgnored="false" %> 
<%
String path = request.getContextPath();
%>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
	<head>
		<meta http-equiv="pragma" content="no-cache" />
		<meta http-equiv="cache-control" content="no-cache" />
		<meta http-equiv="expires" content="0" />
		<meta http-equiv="keywords" content="keyword1,keyword2,keyword3" />
		<meta http-equiv="description" content="This is my page" />

		<link rel="stylesheet" type="text/css" href="<%=path %>/css/base.css" />
		
		<script language="JavaScript" src="<%=path %>/js/public.js" type="text/javascript"></script>
		
        <script language="javascript">
           function newsAdd()
           {
              var url="<%=path %>/admin/news/newsAdd.jsp";
              window.location.href=url;
           }
           
           function newsDetail(id)
           {
			   var url="<%=path %>/news?type=newsDetail&id="+id;
			   var features="width="+screen.width-200+" ,height="+screen.height-150+" ,toolbar=no, top=0, left=0, menubar=no, scrollbars=no, resizable=no,location=no, status=no"
			   window.open(url,null,features);
           }
       </script>
	</head>

	<body leftmargin="2" topmargin="2" background='<%=path %>/img/allbg.gif'>
			<table width="98%" border="0" cellpadding="2" cellspacing="1" bgcolor="#D1DDAA" align="center" style="margin-top:8px">
				<tr bgcolor="#EEF4EA">
			        <td colspan="13" background="<%=path %>/img/wbg.gif" class='title'><span>&nbsp;</span></td>
			    </tr>
				<tr align="center" bgcolor="#FAFAF1" height="22">
					<td width="10%">类别</td>
					<td width="30%">标题</td>
					<td width="10%">内容</td>
					<td width="10%">发布时间</td>
					<td width="10%">操作</td>
		        </tr>	
				<c:forEach items="${requestScope.newsList}" var="news">
				<tr align='center' bgcolor="#FFFFFF" onMouseMove="javascript:this.bgColor='red';" onMouseOut="javascript:this.bgColor='#FFFFFF';" height="22">
					<td bgcolor="#FFFFFF" align="center">
						 ${news.catelog_name}
					</td>
					<td bgcolor="#FFFFFF" align="center">
						 ${news.title}
					</td>
					<td bgcolor="#FFFFFF" align="center">
						 
						 <a href="#" onclick="newsDetail(${news.id})" class="pn-loperator">查看内容</a>
					</td>
					<td bgcolor="#FFFFFF" align="center">
					    ${news.shijian}
					</td>
					
					<td bgcolor="#FFFFFF" align="center">
						<a class="pn-loperator" href="<%=path %>/news?type=newsDel&id=${news.id}">删除</a>
					</td>
				</tr>
				</c:forEach>
			</table>
			
			<table width='98%'  border='0'style="margin-top:8px;margin-left: 5px;">
			  <tr>
			    <td>
			      <input type="button" value="新闻录入" style="width: 80px;" onclick="newsAdd()" />
			    </td>
			  </tr>
		    </table>
	</body>
</html>
