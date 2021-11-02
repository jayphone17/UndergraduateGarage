package dao;


import domain.Project;
import orm.MethodType;
import orm.SqlAnnotation;

import java.util.ArrayList;

public interface ProjectDao {
    //通过外键得到名字的方法



    @SqlAnnotation(
            sql = "select * from sms_project",
            methodType = MethodType.SELECTLIST,
            resultType = Project.class
    )
    ArrayList<Project> selectProjectList();
    //-----------------




    @SqlAnnotation(
            sql = "SELECT * FROM   SMS_project WHERE Pjtid =?",
            methodType = MethodType.SELECTONE,
            resultType = Project.class
    )
    Project selectProjectByPjtid(Integer Pjtid);
    //------------------增
    @SqlAnnotation(
            sql = "insert into sms_project values(?,?,?,?)",
            methodType = MethodType.INSERT
    )
    int insertProject(Project var1);

    //-----------删
    @SqlAnnotation(
            sql = "delete from sms_project where Pjtid = ?"
    )
    int deleteProject(String var1);
    //-------------------改
    @SqlAnnotation(
            sql = "update sms_project comm set cname = ?,price = ?,kid = ? where cid = ?"
    )
    int update(Project  var1);

}
