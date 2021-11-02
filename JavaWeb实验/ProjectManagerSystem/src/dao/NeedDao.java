package dao;


import domain.Need;
import orm.MethodType;
import orm.SqlAnnotation;

import java.util.ArrayList;

public interface NeedDao {
    @SqlAnnotation(
            sql = "select * from  sms_need",

            resultType = Need.class
    )
    ArrayList<Need> selectList ();
    //-----------------

    //通过Nid 得到外键



    //-----------------查单条
    @SqlAnnotation(
            sql = "SELECT * FROM    SMS_NEED WHERE Nid =?",
            methodType = MethodType.SELECTONE,
            resultType = Need.class
    )
    Need selectNeedByNid(Integer Nid);


    @SqlAnnotation(
            sql = "SELECT * FROM    SMS_NEED WHERE sms_need.Pjtid =?",
            methodType = MethodType.SELECTLIST,
            resultType = Need.class
    )
    ArrayList<Need> selectNeedByPjtid (String Pjtid);





    //------------------增
    @SqlAnnotation(
            sql = "insert into sms_need values(?,?,?,?)",
            methodType = MethodType.INSERT
    )
    int insertNeed(Need var1);

    //-----------删
    @SqlAnnotation(
            sql = "delete from  sms_need where Nid = ?"
    )
    int deleteFunctionByNid(String var1);


    //-------------------改
    @SqlAnnotation(
            sql = "update  sms_need set Ncontent=? where Nid = ?",
            methodType =MethodType.UPDATE,
            resultType = Integer.class
    )
    Integer updateNeedContent (String Ncontent ,String Nid);


}
