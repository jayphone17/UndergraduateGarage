package dao;


import domain.Comm;
import domain.Module;
import orm.MethodType;
import orm.SqlAnnotation;

import java.util.ArrayList;

public interface ModuleDao {
    @SqlAnnotation(
            sql = "insert into  sms_module values(?,?,?,?,?,?,?,?,?)",
            methodType = MethodType.INSERT,
            resultType = Integer.class
    )
    int insertModule(Module var1);


    @SqlAnnotation(
            sql = "select * from sms_module",
            methodType =MethodType.SELECTLIST,
            resultType = Module.class
    )
    ArrayList<Module> selectList ();


    //-----------------
    @SqlAnnotation(

            sql = "SELECT * FROM SMS_MODULE WHERE MOID =?",
            methodType = MethodType.SELECTONE,
            resultType = Module.class
    )
    Module selectModuleByMoid(Integer  var1);


    //通过Moid 主键 得到这个表里的外键Nid
    @SqlAnnotation(
            sql = "SELECT Nid FROM    SMS_MODULE WHERE Moid =?",
            methodType = MethodType.SELECTLIST,
            resultType =Integer.class
    )
    Integer selectNidByMoid(Integer Moid);



    //-----------------



    @SqlAnnotation(
            sql = "SELECT * FROM    SMS_MODULE WHERE Nid =?",
            methodType = MethodType.SELECTONE,
            resultType = Module.class
    )
    Module selectMoudleByNid(String Nid);


    @SqlAnnotation(
            sql = "SELECT * FROM    SMS_MODULE WHERE Moid =?",
            methodType = MethodType.SELECTLIST,
            resultType = Module.class
    )
    Module selectProjectByMoid (String Moid);





    //------------------增
    @SqlAnnotation(
            sql = "insert into SMS_MODULE values(?,?,?,?)",
            methodType = MethodType.INSERT
    )
    int insertFunction(Module var1);

    //-----------删
    @SqlAnnotation(
            sql = "delete from  SMS_MODULE where Moid = ?",
            methodType = MethodType.DELETE,
            resultType = Integer.class
    )
    int deleteModuleByMoid(String var1);

    //-------------------改
    @SqlAnnotation(
            sql = "update  SMS_MODULE set Moname = ?,Monick = ?,Moupdate = ?, Nid=?, Mopriority=?, Mocontent=?,Moneed=? where Moid = ?",
            methodType=MethodType.UPDATE,
            resultType = Integer.class
    )
    int updateModule (String Moname,String Monick,String Moupdate,String Nid,String Mopriority,String Mocontent,String Moneed,String Moid);


    @SqlAnnotation(
            sql = "update  SMS_MODULE set Moneed=? where Moid = ?",
            methodType=MethodType.UPDATE,
            resultType = Integer.class
    )
    int updateMoneed (String Moneed,String Moid);

}
