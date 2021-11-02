package cn.hrbust.dao;
import cn.hrbust.pojo.CrmClass;
import cn.hrbust.pojo.CrmLessontype;
import junit.framework.TestCase;
import org.hibernate.HibernateException;
import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.Transaction;
import org.hibernate.query.Query;

import java.lang.module.Configuration;
import java.sql.Date;
import java.util.List;

public class manageCrmClass extends TestCase implements classDAO{
  //增
  public void testSaveClass(){
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    CrmClass crmClass = new CrmClass();
    CrmLessontype crmLessontype = new CrmLessontype();

    crmLessontype.setLessonName("专业课");
//    crmClass.setClassId(2);
    crmClass.setName("数据结构");
    crmClass.setBeginTime(Date.valueOf("2018-09-1"));
    crmClass.setEndTime(Date.valueOf("2019-1-8"));
    crmClass.setTotalCount(80);
    crmClass.setGoCount(70);
    crmClass.setLeaveCount(10);
    crmClass.setCrmLessontype(crmLessontype);
    try {
      sf = HibernateUtil.getSf(); //session factory单态模式
      session = sf.getCurrentSession();  //保证每个读写线程有唯一的session实例
      ts = session.beginTransaction();
      session.save(crmClass);
      session.save(crmLessontype);
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
  public void testDeleteClass(){
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    try {
      sf = HibernateUtil.getSf();
      session = sf.getCurrentSession();
      ts = session.beginTransaction();
      CrmClass crmClass = session.get(CrmClass.class,20);
      if(crmClass!=null){
        session.delete(crmClass);
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
  public void testUpdateClass(){
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    try {
      sf = HibernateUtil.getSf();
      session = sf.getCurrentSession();
      ts = session.beginTransaction();

      CrmClass crmClass = session.get(CrmClass.class,17);
      crmClass.setName("计算机网络");
      session.save(crmClass);
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
  public void testQueryClass(){
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    try {
      sf = HibernateUtil.getSf();
      session = sf.getCurrentSession();
      ts = session.beginTransaction();

      Query sqlQuery = session.getNamedQuery("QueryClass");

      List classes = sqlQuery.getResultList();
      for(int i = 0 ; i < classes.size() ; i++)
      {
        CrmClass crmClass = (CrmClass) classes.get(i);
        System.out.println(crmClass.toString());
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
