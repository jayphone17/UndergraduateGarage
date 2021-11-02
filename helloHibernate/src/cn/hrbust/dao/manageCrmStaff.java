package cn.hrbust.dao;

import cn.hrbust.pojo.CrmPost;
import cn.hrbust.pojo.CrmStaff;
import junit.framework.TestCase;
import org.hibernate.HibernateException;
import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.Transaction;
import org.hibernate.query.Query;

import java.lang.module.Configuration;
import java.sql.Date;
import java.util.List;

public class manageCrmStaff extends TestCase implements staffDAO{
  //增
  public void testSaveStaff(){
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;

    CrmPost crmPost = new CrmPost();
    crmPost.setPostId(1);
    crmPost.setName("数据结构讲师");

    CrmStaff crmStaff = new CrmStaff();
    crmStaff.setBirthday(Date.valueOf("1998-05-11"));
    crmStaff.setGender("male");
    crmStaff.setLoginName("jayphone");
    crmStaff.setLoginPwd("ljf980511");
    crmStaff.setOnDutyDate(Date.valueOf("2020-9-30"));
    crmStaff.setStaffCode("66");
    crmStaff.setStaffName("张三");

    crmStaff.setCrmPost(crmPost);
    try {
      sf = HibernateUtil.getSf(); //session factory单态模式
      session = sf.getCurrentSession();  //保证每个读写线程有唯一的session实例
      ts = session.beginTransaction();
      session.save(crmPost);
      session.save(crmStaff);
      ts.commit();
    } catch (HibernateException e) {
      e.printStackTrace();
      if(ts != null){
        ts.rollback();
      }
    }finally{
      //session.close();
      //sf.close();
    }
  }

  //删
  public void testDeleteStaff(){
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    try {
      sf = HibernateUtil.getSf();
      session = sf.getCurrentSession();
      ts = session.beginTransaction();
      CrmStaff crmStaff = session.get(CrmStaff.class,1);
      if(crmStaff!=null){
        session.delete(crmStaff);
      }
      ts.commit();
    }catch (Exception e){
      e.printStackTrace();
      if(ts!=null){
        ts.rollback();
      }
    }finally {
      //session.close();
      //sf.close();
    }
  }
  //改
  public void testUpdateStaff(){
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    try {
      sf = HibernateUtil.getSf();
      session = sf.getCurrentSession();
      ts = session.beginTransaction();
      CrmStaff crmStaff = session.get(CrmStaff.class,3);
      crmStaff.setBirthday(Date.valueOf("1999-06-16"));
      crmStaff.setGender("测试修改");
      crmStaff.setLoginName("测试");
      crmStaff.setLoginPwd("测试");
      crmStaff.setOnDutyDate(Date.valueOf("2020-9-30"));
      crmStaff.setStaffCode("888888");
      crmStaff.setStaffName("linjiefeng");
      session.save(crmStaff);
      ts.commit();
    }catch (Exception e){
      e.printStackTrace();
      if(ts!=null){
        ts.rollback();
      }
    }finally {
      //session.close();
      //sf.close();
    }
  }

  //查
  public void testQueryStaff(){
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    try {
      sf = HibernateUtil.getSf(); //sessionfactory单态模式
      session = sf.getCurrentSession();  //保证每个读写线程有唯一的session实例
      ts = session.beginTransaction();
      Query sqlQuery = session.getNamedQuery("QueryStaffs");
      List staffs = sqlQuery.getResultList();
      for(int i = 0 ; i < staffs.size() ; i++)
      {
        CrmStaff crmStaff = (CrmStaff) staffs.get(i);
        System.out.println(crmStaff.toString());
      }
      ts.commit();
    } catch (Exception e) {
      e.printStackTrace();
      if(ts != null){
        ts.rollback();
      }
    }finally{
      //session.close();
      //sf.close();
    }
  }
}
