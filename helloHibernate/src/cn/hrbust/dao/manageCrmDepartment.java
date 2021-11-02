package cn.hrbust.dao;

import cn.hrbust.pojo.CrmDepartment;
import junit.framework.TestCase;
import org.hibernate.HibernateException;
import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.Transaction;
import org.hibernate.query.Query;

import java.lang.module.Configuration;
import java.util.List;

public class manageCrmDepartment extends TestCase implements departmentDAO{
  //增
  public void testSaveDepartment(){
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    CrmDepartment crmDepartment = new CrmDepartment();
    crmDepartment.setDepName("校团委");
    try {
      sf = HibernateUtil.getSf(); //session factory单态模式
      session = sf.getCurrentSession();  //保证每个读写线程有唯一的session实例
      ts = session.beginTransaction();
      session.save(crmDepartment);
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
  public void testDeleteDepartment(){
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    try {
      sf = HibernateUtil.getSf();
      session = sf.getCurrentSession();
      ts = session.beginTransaction();
      CrmDepartment crmDepartment = session.get(CrmDepartment.class,1);
      if(crmDepartment!=null){
        session.delete(crmDepartment);
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
  public void testUpdateDepartment(){
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    try {
      sf = HibernateUtil.getSf();
      session = sf.getCurrentSession();
      ts = session.beginTransaction();
      CrmDepartment crmDepartment = session.get(CrmDepartment.class,6);
      crmDepartment.setDepName("软件与微电子学院");
      session.save(crmDepartment);
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
  public void testQueryDepartment(){
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    try {
      sf = HibernateUtil.getSf();
      session = sf.getCurrentSession();
      ts = session.beginTransaction();
      Query sqlQuery = session.getNamedQuery("QueryDepartments");
      List departments = sqlQuery.getResultList();
      for(int i = 0 ; i < departments.size() ; i++)
      {
        CrmDepartment crmDepartment = (CrmDepartment) departments.get(i);
        System.out.println(crmDepartment.toString());
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
