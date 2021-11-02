package cn.hrbust.dao;

import cn.hrbust.pojo.CrmDepartment;
import cn.hrbust.pojo.CrmPost;
import junit.framework.TestCase;
import org.hibernate.HibernateException;
import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.Transaction;
import org.hibernate.query.Query;

import java.lang.module.Configuration;
import java.util.List;

public class manageCrmPost extends TestCase implements postDAO{
  //增
  public void testSavePosition(){
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    CrmDepartment crmDepartment = new CrmDepartment();
    crmDepartment.setDepName("党委宣传部");

    CrmPost crmPost = new CrmPost();
    crmPost.setName("Oracle");

    crmPost.setCrmDepartment(crmDepartment);
    try {
      sf = HibernateUtil.getSf();
      session = sf.getCurrentSession();
      ts = session.beginTransaction();
      session.save(crmPost);
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
  public void testDeletePosition(){
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    try {
      sf = HibernateUtil.getSf();
      session = sf.getCurrentSession();
      ts = session.beginTransaction();
      CrmPost crmPost = session.get(CrmPost.class,5);
      if(crmPost!=null){
        session.delete(crmPost);
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
  public void testUpdatePosition(){
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    try {
      sf = HibernateUtil.getSf();
      session = sf.getCurrentSession();
      ts = session.beginTransaction();
      CrmPost crmPost = session.get(CrmPost.class,2);
      crmPost.setName("学院院长");
      session.save(crmPost);
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
  public void testQueryPosition(){
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    try {
      sf = HibernateUtil.getSf();
      session = sf.getCurrentSession();
      ts = session.beginTransaction();
      Query sqlQuery = session.getNamedQuery("QueryPosts");
      List posts = sqlQuery.getResultList();
      for(int i = 0 ; i < posts.size() ; i++)
      {
        CrmPost crmPost = (CrmPost) posts.get(i);
        System.out.println(crmPost.toString());
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
