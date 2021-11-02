<%@ page pageEncoding="UTF-8" %>
<%@page language="java" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix="fmt" uri="http://java.sun.com/jsp/jstl/fmt" %>
<%@ page isELIgnored="false" %>
<%
    String path = request.getContextPath();
    String basePath = request.getScheme() + "://" + request.getServerName() + ":" + request.getServerPort() + path + "/";
%>
<!DOCTYPE HTML >
<html>
<head>
    <meta http-equiv="pragma" content="no-cache">
    <meta http-equiv="cache-control" content="no-cache">
    <meta http-equiv="expires" content="0">
    <meta http-equiv="keywords" content="keyword1,keyword2,keyword3">
    <meta http-equiv="description" content="This is my page">
    <LINK href="<%=path %>/css/css.css" type=text/css rel=stylesheet>
</head>

<BODY text=#000000 leftMargin=0 topMargin=0>
<div class="wrap">
    <TABLE cellSpacing=0 cellPadding=0 width="100%" align=center border=0 background="<%=path %>/img/fengmian.gif">
        <TR height="90">
            <TD align="center">
                <jsp:include flush="true" page="/qiantai/inc/incTop1.jsp"></jsp:include>
            </TD>
        </TR>
    </TABLE>


    <TABLE id=guide cellSpacing=0 cellPadding=0 width="100%" align=center border=0>
        <TR>
            <TD align="left">
                <jsp:include flush="true" page="/qiantai/inc/incTop2.jsp"></jsp:include>
            </TD>
        </TR>
    </TABLE>

    <TABLE class=MainTable style="MARGIN-TOP: 0px" cellSpacing=0 cellPadding=0 width="100%" align=center border=0>
        <TR>
            <TD class=Side vAlign=top align=right width="25%">
                <jsp:include flush="true" page="/qiantai/inc/incLeft.jsp"></jsp:include>
            </TD>
            <td width="1">&nbsp;</td>
            <TD class=Side vAlign=top align=right width="75%">
                <c:forEach items="${requestScope.catelogList}" var="catelog">
                    <TABLE class=dragTable cellSpacing=0 cellPadding=0 width="100%" border=0>
                        <TR background="<%=path %>/img/right_03.gif">
                            <TD class=head>
                                <SPAN class=TAG>${catelog.name1 }</SPAN>
                            </TD>
                        </TR>
                        <TR align="left">
                            <TD height="5"></TD>
                        </TR>
                        <TR align="left" height="230">
                            <TD>
                                <table width="99%" border="0" cellpadding="9" cellspacing="9" bgcolor="#FFFFFF"
                                       align="center" style="margin-top:8px">
                                    <c:forEach items="${catelog.newsList}" var="news">
                                        <tr align='center' bgcolor="#FFFFFF" height="22">
                                            <td width="80%" align="left"><a
                                                    href="<%=path %>/news?type=newsDetailQian&id=${news.id }">${news.title }</a>
                                            </td>
                                            <td width="20%" align="right">${news.shijian }</td>
                                        </tr>
                                    </c:forEach>
                                </table>
                            </TD>
                        </TR>
                        <TR align="left">
                            <TD height="5"></TD>
                        </TR>
                    </TABLE>
                </c:forEach>
            </TD>
        </TR>
    </TABLE>
    <jsp:include flush="true" page="/qiantai/inc/incFoot.jsp"></jsp:include>
</div>
</BODY>
</html>
