package cn.hrbust.dao;

import cn.hrbust.pojo.Group;
import cn.hrbust.pojo.User;
import junit.framework.TestCase;
import org.hibernate.HibernateException;
import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.Transaction;
import org.hibernate.query.Query;

import java.lang.module.Configuration;
import java.sql.Date;
import java.util.List;

public class Association_Mapping_1_VS_n单向 extends TestCase {
  //单向的多对一关联映射保存
  public void testCascadeSaveUserAndGroup(){
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    Group g = new Group();
    g.setName("软件工程");
    User u = new User();//一个user
    u.setName("linjiefeng");
    u.setGender("男");
    u.setAge(23);
    u.setBirthday(Date.valueOf("1998-5-1"));
    User u1 = new User();//另一个user
    u1.setName("林杰锋");
    u1.setGender("男");
    u1.setAge(23);
    u1.setBirthday(Date.valueOf("1998-05-11"));
    u.setGroup(g);
    u1.setGroup(g);
    try {
      sf = HibernateUtil.getSf();
      session = sf.getCurrentSession();
      ts = session.beginTransaction();
      session.save(u);
      session.save(u1);
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

  //单向的多对一关联映射查询
  public void testSelectManyToOne1(){
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    try{
      sf = HibernateUtil.getSf();
        session = sf.getCurrentSession();
      ts = session.beginTransaction();//开始事务
      Query query = session.createQuery("from User");
      List users = query.getResultList();
      for(int i=0;i<users.size();i++){
        User u =(User)users.get(i);
        System.out.println(u.toString());
      }
      ts.commit();//提交事务
    }catch (HibernateException e){
      e.printStackTrace();
      if(ts!=null){
        ts.rollback();
      }
    }finally {
      //session.close();//关闭Session
      //sf.close();
    }
  }
}
