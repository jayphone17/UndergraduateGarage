package dao;

import domain.Function;
import orm.MethodType;
import orm.SqlAnnotation;

import java.util.ArrayList;

public interface FunctionDao {
    @SqlAnnotation(

            sql = "SELECT  Nname FROM   sms_function WHERE Fid =?",
            resultType = String.class
    )
    String selectFunctionName(String moid);
    @SqlAnnotation(
            sql = "select * from sms_function",

            resultType = Function.class
    )
    ArrayList<Function>selectList  ();

    //-----------------



    @SqlAnnotation(
            sql = "SELECT * FROM    sms_function WHERE moid =?",
            methodType = MethodType.SELECTLIST,
            resultType = Function.class
    )
    Function selectFucntionBymoid(String moid);


    @SqlAnnotation(
            sql = "select * from  sms_function WHERE Fid =?",
            methodType = MethodType.SELECTONE,
            resultType = Function.class

    )
    Function selectFunctionByFid (String Fid);





    //------------------增
    @SqlAnnotation(
            sql = "insert into  sms_function values(?,?,?,?,?,?,?,?,?)",
            methodType = MethodType.INSERT,
            resultType = Integer.class
    )
    int insertFunction(Function var1);

    //-----------删
    @SqlAnnotation(
            sql = "delete from  sms_function where Fid = ?",
            methodType = MethodType.DELETE,
            resultType = Integer.class
    )
    int deleteFunctionByFid(String Fid);






    //-------------------改
    @SqlAnnotation(
            sql = "update  sms_function set Fname = ?,Fversion = ?,Fpriority = ?,Fcontent = ? where Fid = ?",
            methodType = MethodType.UPDATE,
            resultType = Integer.class


    )
    Integer updateFunction(String Fname,String Fversion,String Fpriority,String Fcontent,String  Fid);
}
