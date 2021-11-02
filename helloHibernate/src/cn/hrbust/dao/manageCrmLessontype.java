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
import java.util.List;

public class manageCrmLessontype extends TestCase implements lessonTypeDAO {
  @Override
  //增
  public void testSavelessonType() {
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    CrmClass crmClass = new CrmClass();
    CrmLessontype crmLessontype = new CrmLessontype();
    crmLessontype.setLessonTypeId(1);
    crmLessontype.setLessonName("公共课");
    crmLessontype.setLessonCost(104.5);
    crmLessontype.setTotal(60);
    crmLessontype.setRemark("该课程需要60学时");
    try {
      sf = HibernateUtil.getSf(); //session factory单态模式
      session = sf.getCurrentSession();  //保证每个读写线程有唯一的session实例
      ts = session.beginTransaction();
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
  @Override
  //删
  public void testDeletelessonType() {
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    try {
      sf = HibernateUtil.getSf();
      session = sf.getCurrentSession();
      ts = session.beginTransaction();
      CrmLessontype crmLessontype = session.get(CrmLessontype.class,8);
      if(crmLessontype!=null){
        session.delete(crmLessontype);
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
  @Override
  //改
  public void testUpdatelessonType() {
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    try {
      sf = HibernateUtil.getSf();
      session = sf.getCurrentSession();
      ts = session.beginTransaction();

      CrmLessontype crmLessontype = session.get(CrmLessontype.class,15);
      crmLessontype.setLessonName("语言课");
      session.save(crmLessontype);
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
  @Override
  //查
  public void testQuerylessonType() {
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    try {
      sf = HibernateUtil.getSf();
      session = sf.getCurrentSession();
      ts = session.beginTransaction();

      Query sqlQuery = session.getNamedQuery("QueryLessonTypes");

      List lessonTypes = sqlQuery.getResultList();
      for(int i = 0 ; i < lessonTypes.size() ; i++)
      {
        CrmLessontype crmLessontype = (CrmLessontype) lessonTypes.get(i);
        System.out.println(crmLessontype.toString());
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
